import { readdir, readFile, mkdir, writeFile, cp, rm } from 'node:fs/promises';
import path from 'node:path';
import { pathToFileURL } from 'node:url';
import { compileMarkdown, extractMetadata, topicRoute } from './content.mjs';

export async function walk(directory) {
  const entries = await readdir(directory, { withFileTypes: true });
  const nested = await Promise.all(entries.filter(entry => !entry.name.startsWith('.')).map(async entry => {
    const full = path.join(directory, entry.name);
    if (entry.isSymbolicLink()) return [];
    return entry.isDirectory() ? walk(full) : [full];
  }));
  return nested.flat();
}
export async function generateContent({ root = process.cwd(), warn = console.warn } = {}) {
  const notes = path.join(root, 'notes');
  const files = (await walk(notes)).map(file => path.relative(notes, file).split(path.sep).join('/').normalize('NFC'));
  const documents = [];
  const assets = files.filter(file => !file.endsWith('.md')).map(file => ({ path: file }));
  for (const file of files.filter(file => /^seminar-\d+\/(?:topics\/.+|tasks)\.md$/i.test(file))) {
    const raw = await readFile(path.join(notes, file), 'utf8');
    documents.push({ path: file, ...extractMetadata(raw, file) });
  }
  const seminars = [];
  const directories = (await readdir(notes, { withFileTypes: true })).filter(entry => entry.isDirectory() && /^seminar-\d+$/.test(entry.name));
  const compare = (a, b) => a.localeCompare(b, 'ru', { numeric: true });
  const output = path.join(root, 'public/content');
  await rm(output, { recursive: true, force: true });
  await mkdir(output, { recursive: true });
  for (const directory of directories.sort((a, b) => compare(a.name, b.name))) {
    const id = directory.name;
    const topics = documents.filter(item => item.path.startsWith(`${id}/topics/`)).sort((a, b) => compare(a.path, b.path));
    const tasks = documents.find(item => item.path === `${id}/tasks.md`);
    const render = doc => ({ ...doc, route: topicRoute(doc.path), ...compileMarkdown(doc.markdown, doc.path, documents, assets, warn) });
    seminars.push({ id, number: Number(id.split('-')[1]), title: `Семинар ${Number(id.split('-')[1])}`, taskCount: tasks?.taskCount || 0, topics: topics.map(render), tasks: tasks ? render(tasks) : null });
    if (tasks && !tasks.taskCount) warn(`[content] ${tasks.path}: specify taskCount in frontmatter to track submissions.`);
  }
  for (const asset of assets) {
    const destination = path.join(output, asset.path);
    await mkdir(path.dirname(destination), { recursive: true });
    await cp(path.join(notes, asset.path), destination);
  }
  await mkdir(path.join(root, 'src/generated'), { recursive: true });
  const manifest = { seminars };
  await writeFile(path.join(root, 'src/generated/content.json'), JSON.stringify(manifest, null, 2));
  await writeFile(path.join(output, 'manifest.json'), JSON.stringify({ seminars: seminars.map(({ id, title, taskCount }) => ({ id, title, taskCount })) }, null, 2));
  console.log(`Content: ${seminars.length} seminars, ${documents.length} notes, ${assets.length} assets.`);
  return manifest;
}
if (process.argv[1] && import.meta.url === pathToFileURL(path.resolve(process.argv[1])).href) await generateContent();
