import test from 'node:test';
import assert from 'node:assert/strict';
import { mkdtemp, mkdir, writeFile, rm, readFile } from 'node:fs/promises';
import os from 'node:os';
import path from 'node:path';
import { compileMarkdown, extractMetadata, taskIdsFromMarkdown } from '../scripts/content.mjs';
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

test('Obsidian vault: sem ranges, filenames as titles, shared media, tasks and automatic additions', async () => {
  const root = await mkdtemp(path.join(os.tmpdir(), 'c-vault-'));
  try {
    const notes = path.join(root, 'notes');
    for (const folder of ['АиАЯ/sem1-2', 'АиАЯ/sem3', 'АиАЯ/sem4', '0 media', 'seminar-01/topics']) await mkdir(path.join(notes, folder), { recursive: true });
    const source = '# Формат\n\n![[Pasted image 123.png]]\n\n[[Переменные]]\n\n![Ещё](../../0%20media/Pasted%20image%20123.png)\n';
    await writeFile(path.join(notes, 'АиАЯ/sem1-2/printf, scanf.md'), source);
    await writeFile(path.join(notes, 'АиАЯ/sem1-2/Переменные.md'), 'Обычный текст');
    await writeFile(path.join(notes, 'АиАЯ/sem3/0 tasks.md'), '# 1 (1б)\n\nПервое\n\n# 2 (0,5 б)\n\nВторое');
    await writeFile(path.join(notes, 'АиАЯ/sem3/Циклы.md'), '# while\n\n```c\nint main(void) { return 0; }\n```\n\n# for');
    await writeFile(path.join(notes, 'АиАЯ/sem3/Пустая заметка.md'), '');
    await writeFile(path.join(notes, 'АиАЯ/sem4/0 tasks.md'), '# 1.1 (0.5 б)\n\nВопрос\n\n# 1.2 (1б)\n\nВопрос\n\n# 2 (1б)\n\nВопрос');
    await writeFile(path.join(notes, '0 media/Pasted image 123.png'), 'image');
    await writeFile(path.join(notes, 'seminar-01/topics/demo.md'), '# Demo');
    const warnings = [];
    let { seminars } = await generateContent({ root, warn: warning => warnings.push(warning) });
    assert.deepEqual(seminars.map(item => item.id), ['seminar-01-02', 'seminar-03', 'seminar-04']);
    assert.equal(seminars[0].title, 'Семинары 1–2');
    const printing = seminars[0].topics.find(item => item.title === 'printf, scanf');
    assert.ok(printing.markdown.startsWith('# printf, scanf\n'));
    assert.ok(printing.markdown.includes('## Формат'));
    assert.ok(printing.markdown.includes('__CONTENT_ASSET__/0%20media/Pasted%20image%20123.png'));
    assert.ok(printing.markdown.includes('#/notes/'));
    assert.deepEqual(seminars[1].topics.map(item => item.title), ['Пустая заметка', 'Циклы']);
    assert.equal(seminars[1].tasks.path, 'АиАЯ/sem3/0 tasks.md');
    assert.deepEqual(seminars[1].taskIds, ['1', '2']);
    assert.deepEqual(seminars[2].taskIds, ['1.1', '1.2', '2']);
    assert.equal(seminars[2].taskCount, 3);
    assert.equal(await readFile(path.join(notes, 'АиАЯ/sem1-2/printf, scanf.md'), 'utf8'), source);
    assert.equal(await readFile(path.join(root, 'public/content/0 media/Pasted image 123.png'), 'utf8'), 'image');
    assert.deepEqual(warnings, []);
    await mkdir(path.join(notes, 'АиАЯ/sem10'));
    await writeFile(path.join(notes, 'АиАЯ/sem10/Новая тема.md'), '# Раздел');
    await rm(path.join(notes, 'АиАЯ/sem3/Пустая заметка.md'));
    ({ seminars } = await generateContent({ root }));
    assert.equal(seminars.at(-1).title, 'Семинар 10');
    assert.equal(seminars.at(-1).topics[0].title, 'Новая тема');
    assert.deepEqual(seminars[1].topics.map(item => item.title), ['Циклы']);
  } finally { await rm(root, { recursive: true, force: true }); }
});

test('task numbering comes only from headings and ignores code examples', () => {
  assert.deepEqual(taskIdsFromMarkdown('# Задания\n\n# 1.1 (0.5 б)\n\n# 1.2 (1 б)\n\n# 2. Массив\n\n```text\n# 99\n```'), ['1.1', '1.2', '2']);
  const compiled = compileMarkdown('# Тема\n\n## Раздел', 'АиАЯ/sem3/Тема.md', [], [], () => {}, { title: 'Тема' });
  assert.equal(compiled.headings.filter(heading => heading.depth === 1).length, 1);
  assert.equal(compiled.headings[1].depth, 2);
});

test('link resolution normalizes Unicode without renaming files on disk', () => {
  const file = 'АиАЯ/sem3/й.md'.normalize('NFD');
  const compiled = compileMarkdown('[[й]]\n\n![[мой рисунок.png]]', 'АиАЯ/sem3/Начало.md', [{ path: file, title: 'й' }], [{ path: '0 media/мой рисунок.png'.normalize('NFD') }], warning => assert.fail(warning));
  assert.ok(compiled.markdown.includes('#/notes/'));
  assert.ok(compiled.markdown.includes('__CONTENT_ASSET__/0%20media/'));
});
