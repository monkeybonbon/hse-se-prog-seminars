import test from 'node:test';
import assert from 'node:assert/strict';
import { mkdtemp, mkdir, writeFile, rm, readFile } from 'node:fs/promises';
import os from 'node:os';
import path from 'node:path';
import { compileMarkdown, extractMetadata } from '../scripts/content.mjs';
import { generateContent } from '../scripts/generate-content-manifest.mjs';

test('Obsidian and relative links, Unicode, anchors, images, literal code and diagnostics', () => {
  const docs = [{ path: 'seminar-01/topics/01-start.md', title: 'Начало' }, { path: 'seminar-01/topics/02-Русская заметка.md', title: 'Русская заметка' }];
  const assets = [{ path: 'seminar-01/assets/мой рисунок.svg' }];
  const warnings = [];
  const input = '# Начало\n\n## Тема\n\n## Тема\n\n[[Русская заметка|Дальше]] [[Русская заметка#Мой раздел]]\n\n![[мой рисунок.svg]]\n\n[Ссылка](<02-Русская заметка.md#Мой раздел>)\n\n![Картинка](<../assets/мой рисунок.svg>)\n\n[[Неизвестно]]\n\n`[[literal]]`\n\n```c id=stable\n// [[literal]]\nint main(void) { return 0; }\n```\n';
  const result = compileMarkdown(input, docs[0].path, docs, assets, value => warnings.push(value));
  assert.ok(result.markdown.includes('02-%D0%A0%D1%83%D1%81%D1%81%D0%BA%D0%B0%D1%8F%20'));
  assert.ok(result.markdown.includes('#мой-раздел'));
  assert.ok(result.markdown.includes('__CONTENT_ASSET__/seminar-01/assets/'));
  assert.ok(result.markdown.includes('`[[literal]]`'));
  assert.ok(result.markdown.includes('// [[literal]]'));
  assert.equal(result.codeBlocks, 1);
  assert.ok(result.markdown.includes('id=stable'));
  assert.deepEqual(result.headings.map(item => item.id), ['начало', 'тема', 'тема-1']);
  assert.equal(warnings.length, 1);
  assert.match(warnings[0], /Неизвестно/);
});

test('duplicate explicit code IDs fail with actionable diagnostic', () => {
  assert.throws(() => compileMarkdown('```c id=x\n1\n```\n\n```c id=x\n2\n```', 'a.md', [], []), /duplicate C block id x/);
});

test('H1 wins, fallback filenames and explicit task metadata', () => {
  assert.equal(extractMetadata('# Тема\n', '01-other.md').title, 'Тема');
  assert.equal(extractMetadata('Простой текст', '04-Моя тема.md').title, 'Моя тема');
  assert.equal(extractMetadata('---\ntaskCount: 3\n---\n# Tasks', 'tasks.md').taskCount, 3);
});

test('build discovers added/renamed/deleted topics and assets without changing Markdown', async () => {
  const root = await mkdtemp(path.join(os.tmpdir(), 'c-notes-'));
  try {
    const topics = path.join(root, 'notes/seminar-04/topics');
    await mkdir(topics, { recursive: true });
    await mkdir(path.join(root, 'notes/seminar-04/assets'));
    const original = '# Новый конспект\n\n```c\nint main(void) { return 0; }\n```\n';
    await writeFile(path.join(topics, '10-ten.md'), original);
    await writeFile(path.join(topics, '2-two.md'), '# Второй');
    await writeFile(path.join(root, 'notes/seminar-04/tasks.md'), '---\ntaskCount: 4\n---\n# Задачи');
    await writeFile(path.join(root, 'notes/seminar-04/assets/рисунок.txt'), 'asset');
    let manifest = await generateContent({ root });
    assert.equal(manifest.seminars[0].taskCount, 4);
    assert.equal(manifest.seminars[0].topics[0].title, 'Второй');
    assert.equal(await readFile(path.join(topics, '10-ten.md'), 'utf8'), original);
    assert.equal(await readFile(path.join(root, 'public/content/seminar-04/assets/рисунок.txt'), 'utf8'), 'asset');
    await rm(path.join(topics, '2-two.md'));
    await writeFile(path.join(topics, '03-added.md'), '# Добавлено');
    await rm(path.join(root, 'notes/seminar-04/assets/рисунок.txt'));
    manifest = await generateContent({ root });
    assert.deepEqual(manifest.seminars[0].topics.map(topic => topic.title), ['Добавлено', 'Новый конспект']);
    await assert.rejects(readFile(path.join(root, 'public/content/seminar-04/assets/рисунок.txt')), /ENOENT/);
  } finally { await rm(root, { recursive: true, force: true }); }
});
