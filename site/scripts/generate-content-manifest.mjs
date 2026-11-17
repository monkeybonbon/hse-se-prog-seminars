import { access, readdir, readFile, mkdir, writeFile, cp, rm } from 'node:fs/promises';
import path from 'node:path';
import { pathToFileURL } from 'node:url';
import { compileMarkdown, extractMetadata, topicRoute, taskIdsFromMarkdown } from './content.mjs';

export async function walk(directory) {
  const entries = await readdir(directory, { withFileTypes: true });
  const nested = await Promise.all(entries.filter(entry => !entry.name.startsWith('.')).map(async entry => {
    const full = path.join(directory, entry.name);
    if (entry.isSymbolicLink()) return [];
    return entry.isDirectory() ? walk(full) : [full];
  }));
  return nested.flat();
}

async function seminarSources(notes, prefix = '') {
  const entries = await readdir(path.join(notes, prefix), { withFileTypes: true });
  const sources = [];
  for (const entry of entries.filter(item => item.isDirectory() && !item.isSymbolicLink() && !item.name.startsWith('.'))) {
    const sourcePath = prefix ? `${prefix}/${entry.name}` : entry.name;
    const match = entry.name.match(/^sem(\d+)(?:-(\d+))?$/i);
    if (match) {
      const number = Number(match[1]);
      const end = match[2] ? Number(match[2]) : null;
      if (number < 1 || end !== null && end < number) throw new Error(`Invalid seminar range: ${sourcePath}`);
      const numberLabel = end ? `${number}–${end}` : String(number);
      sources.push({ id: `seminar-${String(number).padStart(2, '0')}${end ? `-${String(end).padStart(2, '0')}` : ''}`, number, numberLabel, title: `${end ? 'Семинары' : 'Семинар'} ${numberLabel}`, sourcePath, layout: 'obsidian' });
    } else sources.push(...await seminarSources(notes, sourcePath));
  }
  return sources;
}

export async function generateContent({ root = process.cwd(), warn = console.warn } = {}) {
  const notes = path.join(root, 'notes');
  const modules = await readFile(path.join(root, '..', '.gitmodules'), 'utf8').catch(error => { if (error.code === 'ENOENT') return ''; throw error; });
  if (/^\s*path\s*=\s*site\/notes\s*$/m.test(modules)) {
    try { await access(path.join(notes, '.git')); }
    catch { throw new Error('Obsidian notes submodule is not initialized. Run git submodule update --init --recursive from the repository root (or npm run notes:sync from site/).'); }
  }
  const files = (await walk(notes)).map(file => path.relative(notes, file).split(path.sep).join('/'));
  const documents = [];
  const assets = files.filter(file => !/\.md$/i.test(file)).map(file => ({ path: file }));
  let sources = await seminarSources(notes);
  if (!sources.length) {
    sources = (await readdir(notes, { withFileTypes: true })).filter(entry => entry.isDirectory() && /^seminar-\d+$/.test(entry.name)).map(entry => ({ id: entry.name, number: Number(entry.name.split('-')[1]), title: `Семинар ${Number(entry.name.split('-')[1])}`, sourcePath: entry.name, layout: 'legacy' }));
  }
  const usedIds = new Set();
  for (const source of sources) {
    if (usedIds.has(source.id)) throw new Error(`Duplicate seminar number: ${source.sourcePath}`);
    usedIds.add(source.id);
  }
  for (const file of files.filter(file => /\.md$/i.test(file))) {
    const source = sources.find(item => file.startsWith(`${item.sourcePath}/`));
    if (!source) continue;
    const relative = file.slice(source.sourcePath.length + 1);
    if (source.layout === 'legacy' && !/^(?:topics\/.+|tasks)\.md$/i.test(relative)) continue;
    const isTasks = /^(?:0\s+)?tasks\.md$/i.test(relative);
    const raw = await readFile(path.join(notes, file), 'utf8');
    const metadata = extractMetadata(raw, file);
    const title = source.layout === 'obsidian' ? (isTasks ? `Задания: ${source.title.toLowerCase()}` : extractMetadata('', file).title) : metadata.title;
    documents.push({ path: file, ...metadata, title, isTasks, seminarId: source.id });
  }
  const seminars = [];
  const compare = (a, b) => a.localeCompare(b, 'ru', { numeric: true });
  const output = path.join(root, 'public/content');
  await rm(output, { recursive: true, force: true });
  await mkdir(output, { recursive: true });
  for (const source of sources.sort((a, b) => a.number - b.number || compare(a.sourcePath, b.sourcePath))) {
    const topics = documents.filter(item => item.seminarId === source.id && !item.isTasks).sort((a, b) => compare(a.path, b.path));
    const taskDocuments = documents.filter(item => item.seminarId === source.id && item.isTasks);
    if (taskDocuments.length > 1) throw new Error(`${source.sourcePath}: keep only one tasks.md or 0 tasks.md`);
    const tasks = taskDocuments[0];
    const taskIds = tasks?.taskCount ? Array.from({ length: tasks.taskCount }, (_, i) => String(i + 1)) : tasks ? taskIdsFromMarkdown(tasks.markdown) : [];
    const render = doc => ({ ...doc, route: topicRoute(doc.path), ...compileMarkdown(doc.markdown, doc.path, documents, assets, warn, { title: source.layout === 'obsidian' ? doc.title : undefined }) });
    seminars.push({ ...source, taskCount: taskIds.length, taskIds, topics: topics.map(render), tasks: tasks ? render(tasks) : null });
    if (tasks && !taskIds.length) warn(`[content] ${tasks.path}: specify taskCount or numbered task headings to track submissions.`);
  }
  for (const asset of assets) {
    const destination = path.join(output, asset.path);
    await mkdir(path.dirname(destination), { recursive: true });
    await cp(path.join(notes, asset.path), destination);
  }
  await mkdir(path.join(root, 'src/generated'), { recursive: true });
  const manifest = { seminars };
  await writeFile(path.join(root, 'src/generated/content.json'), JSON.stringify(manifest, null, 2));
  await writeFile(path.join(output, 'manifest.json'), JSON.stringify({ seminars: seminars.map(({ id, title, taskCount, taskIds }) => ({ id, title, taskCount, taskIds })) }, null, 2));
  console.log(`Content: ${seminars.length} seminars, ${documents.length} notes, ${assets.length} assets.`);
  return manifest;
}
if (process.argv[1] && import.meta.url === pathToFileURL(path.resolve(process.argv[1])).href) await generateContent();
