import { access, mkdir, readFile, writeFile } from 'node:fs/promises';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const root = fileURLToPath(new URL('../', import.meta.url));
const destination = path.join(root, 'notes/.github/workflows/publish-site.yml');
try { await access(path.join(root, 'notes/.git')); }
catch { throw new Error('Initialize the Obsidian submodule first: npm run notes:sync'); }
const template = await readFile(path.join(root, 'integrations/obsidian/publish-site.yml'), 'utf8');
const existing = await readFile(destination, 'utf8').catch(error => { if (error.code === 'ENOENT') return null; throw error; });
if (existing !== null && existing.replaceAll('\r\n', '\n') !== template.replaceAll('\r\n', '\n')) {
  throw new Error('notes/.github/workflows/publish-site.yml already exists with different contents; keep it and review the template manually.');
}
await mkdir(path.dirname(destination), { recursive: true });
await writeFile(destination, template);
console.log('Prepared notes/.github/workflows/publish-site.yml in the Obsidian repository.');
console.log('Commit and push this file in that repository, then add its SITE_PUBLISH_TOKEN secret. See NOTES.md.');
