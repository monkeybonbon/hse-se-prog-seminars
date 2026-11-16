import { test, expect, type Locator } from '@playwright/test';
import content from '../../src/generated/content.json' with { type: 'json' };
import config from '../../site.config.json' with { type: 'json' };

const notes = content.seminars.flatMap(seminar => seminar.topics);
const exampleNote = notes.find(note => note.codeBlocks > 0 && note.markdown.includes('__CONTENT_ASSET__'))!;
const multiNote = notes.find(note => note.codeBlocks >= 3)!;
const tasksSeminar = content.seminars.find(seminar => seminar.tasks)!;
const tasksNote = tasksSeminar.tasks!;
const mathNote = [...notes, tasksNote].find(note => note.markdown.includes('$'))!;
const introduction = `#${exampleNote.route}`;
async function setCode(editor: Locator, source: string) {
  const content = editor.locator('.cm-content');
  await content.click();
  await content.press('ControlOrMeta+a');
  await content.pressSequentially(source, { delay: 0 });
}
async function compile(editor: Locator) {
  await editor.getByRole('button', { name: '▶ Запустить' }).click();
  await expect(editor.locator('.editor-status')).toContainText(/код \d+|Ошибка|Превышено|поврежд|Не удалось/i, { timeout: 120000 });
}

test('real C compilation, edited source, persistence, reset, Obsidian links, images, no eager toolchain', async ({ page }) => {
  const requests: string[] = [];
  page.on('request', request => requests.push(request.url()));
  await page.goto(introduction);
  await expect(page.getByRole('heading', { name: exampleNote.title, exact: true, level: 1 })).toBeVisible();
  expect(requests.some(url => url.includes('/toolchain/'))).toBeFalsy();
  const image = page.locator('article img').first();
  await image.scrollIntoViewIfNeeded();
  await expect(image).toHaveJSProperty('complete', true);
  expect(await image.evaluate((img: HTMLImageElement) => img.naturalWidth)).toBeGreaterThan(0);
  const editor = page.locator('.code-editor').first();
  const original = await editor.locator('.cm-content').innerText();
  const code = '#include <stdio.h>\nint main(void) { printf("edited: %d\\n", 19 * 23); return 0; }';
  await setCode(editor, code);
  await compile(editor);
  await expect(editor.getByRole('tabpanel')).toContainText('edited: 437');
  await expect(editor.locator('.editor-status')).toContainText('код 0');
  await page.reload();
  await expect(editor.locator('.cm-content')).toContainText('19 * 23');
  const otherNote = notes.find(note => note.path !== exampleNote.path)!;
  await page.locator('.sidebar').getByRole('link', { name: otherNote.title, exact: false }).click();
  await expect(page.getByRole('heading', { name: otherNote.title, exact: true, level: 1 })).toBeVisible();
  await page.goBack();
  await expect(editor.locator('.cm-content')).toContainText('19 * 23');
  await editor.getByRole('button', { name: '↺ Сбросить' }).click();
  await expect(editor.locator('.cm-content')).toHaveText(original, { useInnerText: true });
  expect(requests.filter(url => url.includes('/toolchain/')).every(url => new URL(url).origin === 'http://127.0.0.1:4173')).toBeTruthy();
});

test('stdin scanf, stderr, exit code, errors and independent editor state', async ({ page }) => {
  await page.goto(`#${multiNote.route}`);
  const editors = page.locator('.code-editor');
  const input = editors.nth(0);
  await setCode(input, '#include <stdio.h>\nint main(void) { int a,b; if(scanf("%d%d",&a,&b)!=2) return 1; printf("Сумма: %d\\n",a+b); return 0; }');
  await input.locator('summary').click();
  await input.getByLabel('stdin', { exact: true }).fill('12 30');
  await compile(input);
  await expect(input.getByRole('tabpanel')).toContainText('Сумма: 42');
  await setCode(editors.nth(1), '#include <stdio.h>\nint main(void) { printf("Начало программы\\n"); fprintf(stderr,"Пример диагностического сообщения\\n"); return 7; }');
  await compile(editors.nth(1));
  await expect(editors.nth(1).locator('.editor-status')).toContainText('код 7');
  await expect(editors.nth(1).getByRole('tabpanel')).toContainText('Пример диагностического сообщения');
  await editors.nth(1).getByRole('tab', { name: 'stdout', exact: true }).click();
  await expect(editors.nth(1).getByRole('tabpanel')).toContainText('Начало программы');
  await setCode(editors.nth(2), '#include <stdio.h>\nint main(void) { printf("broken") return 0; }');
  await compile(editors.nth(2));
  await expect(editors.nth(2).locator('.editor-status')).toContainText('Ошибка компиляции');
  await expect(editors.nth(2).getByRole('tabpanel')).toContainText('error:');
  await setCode(editors.nth(2), 'int main(void) { return 3; }');
  await compile(editors.nth(2));
  await expect(editors.nth(2).locator('.editor-status')).toContainText('код 3');
  await page.reload();
  await expect(editors.nth(2).locator('.cm-content')).toContainText('return 3;');
  await expect(editors.nth(0).locator('.cm-content')).toContainText('scanf');
  await expect(editors.nth(1).locator('.cm-content')).toContainText('return 7;');
});

test('stdlib, strings, math, loops and pointers compile in the browser', async ({ page }) => {
  await page.goto(introduction);
  const editor = page.locator('.code-editor').first();
  await setCode(editor, '#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n#include <math.h>\nint main(void) { double x; if (scanf("%lf", &x)!=1) return 2; int *p=malloc(3*sizeof(int)); if(!p) return 1; for(int i=0;i<3;i++) p[i]=i+1; printf("%.1f %zu %d\\n", sqrt(x), strlen("abc"), *(p+2)); free(p); return 0; }');
  await editor.locator('summary').click();
  await editor.getByLabel('stdin', { exact: true }).fill('81');
  await compile(editor);
  await expect(editor.getByRole('tabpanel')).toContainText('9.0 3 3');
  await expect(editor.locator('.editor-status')).toContainText('код 0');
});

test('runaway program times out and manual stop leaves the page responsive', async ({ page }) => {
  await page.goto(introduction);
  const editor = page.locator('.code-editor').first();
  await setCode(editor, 'int main(void) { volatile unsigned long count=0; for(;;) count++; }');
  await compile(editor);
  await expect(editor.locator('.editor-status')).toContainText('Превышено время выполнения');
  await editor.getByRole('button', { name: '▶ Запустить' }).click();
  await expect(editor.locator('.editor-status')).toContainText('Выполнение…', { timeout: 120000 });
  await editor.getByRole('button', { name: '■ Остановить' }).click();
  await expect(editor.locator('.editor-status')).toContainText('Программа остановлена');
  await page.goto(`#${config.submissionsPath}`);
  await expect(page.getByRole('heading', { name: 'Сдача заданий' })).toBeVisible();
});

test('failed toolchain load recovers with a clear message', async ({ page }) => {
  await page.route('**/toolchain/**', route => route.fulfill({ status: 503, body: 'unavailable' }));
  await page.goto(introduction);
  const editor = page.locator('.code-editor').first();
  await editor.getByRole('button', { name: '▶ Запустить' }).click();
  await expect(editor.locator('.editor-status')).toContainText(/Не удалось|Failed to fetch|HTTP 503/, { timeout: 30000 });
  await expect(editor.getByRole('button', { name: '▶ Запустить' })).toBeEnabled();
});

test('unlinked report URL, removed old route, refresh, filters and immutable file links', async ({ page }) => {
  await page.route('**/submissions.json?*', route => route.fulfill({ json: {
    status: 'partial', updatedAt: '2020-01-01T00:00:00Z', students: [
      { branch: 'BPI2412_Ivanov', group: 'BPI2412', surname: 'Ivanov', status: 'ok', sha: 'abc123', lastCommitAt: null, submissions: { [tasksSeminar.id]: [`${tasksSeminar.taskIds[0]}.c`] } },
      { branch: 'BPI2413_Petrov', group: 'BPI2413', surname: 'Petrov', status: 'unavailable', sha: 'def456', lastCommitAt: null, submissions: {} },
    ], warnings: [] },
  }));
  await page.goto(introduction);
  await expect(page.getByRole('link', { name: 'Сдача заданий', exact: true })).toHaveCount(0);
  await expect(page.locator(`a[href="#${config.submissionsPath}"]`)).toHaveCount(0);
  await page.goto('#/submissions');
  await expect(page.getByRole('heading', { name: 'Страница не найдена' })).toBeVisible();
  await page.goto(`#${config.submissionsPath}`);
  await expect(page.getByRole('heading', { name: 'Сдача заданий' })).toBeVisible();
  await page.reload();
  await expect(page.getByText('Данные некоторых веток недоступны.', { exact: false })).toBeVisible();
  await expect(page.getByRole('link', { name: 'Загружено ↗' })).toHaveAttribute('href', `https://github.com/monkeybonbon/hse-se-prog-seminars/blob/abc123/submissions/${tasksSeminar.id}/${tasksSeminar.taskIds[0]}.c`);
  await page.getByLabel('Группа', { exact: true }).selectOption('BPI2413');
  await expect(page.locator('tbody')).not.toContainText('Ivanov');
  await expect(page.locator('tbody')).toContainText('Нет данных');
  await page.getByLabel('Студент', { exact: true }).fill('absent');
  await expect(page.getByText('По выбранным фильтрам студентов нет.')).toBeVisible();
});

test('mobile layout, menu, direct hash URL, refresh, tasks instructions and full-text search', async ({ page }) => {
  await page.setViewportSize({ width: 375, height: 812 });
  await page.goto(`#${tasksNote.route}`);
  await expect(page.getByRole('heading', { name: tasksNote.title, exact: true, level: 1 })).toBeVisible();
  await expect(page.getByRole('heading', { name: 'Как сдать задания' })).toBeVisible();
  await page.reload();
  await expect(page.getByRole('heading', { name: tasksNote.title, exact: true, level: 1 })).toBeVisible();
  expect(await page.evaluate(() => document.documentElement.scrollWidth <= innerWidth)).toBeTruthy();
  await page.getByRole('button', { name: 'Меню семинаров' }).click();
  await page.getByRole('textbox', { name: 'Поиск по конспектам' }).fill('printf');
  await page.locator('.sidebar').getByRole('link', { name: exampleNote.title, exact: false }).click();
  await expect(page.locator('.sidebar')).not.toBeVisible();
  await expect(page.getByRole('heading', { name: exampleNote.title, exact: true, level: 1 })).toBeVisible();
  await expect(page.locator('.cm-content').first()).toBeVisible();
  await page.screenshot({ path: '.local/mobile.png', fullPage: true });
});

test('desktop screenshot, TOC anchors and KaTeX', async ({ page }) => {
  await page.setViewportSize({ width: 1440, height: 1100 });
  await page.goto(introduction);
  await expect(page.locator('.cm-content').first()).toBeVisible();
  await page.screenshot({ path: '.local/desktop.png', fullPage: true });
  const heading = exampleNote.headings.find(heading => heading.depth === 2)!;
  await page.getByRole('complementary', { name: 'Оглавление темы' }).getByRole('link', { name: heading.text, exact: true }).click();
  await expect(page).toHaveURL(url => decodeURIComponent(url.hash).endsWith(`#${heading.id}`));
  await page.goto(`#${mathNote.route}`);
  await expect(page.locator('.katex').first()).toBeVisible();
});

test('every authored note opens directly with its filename title, shared media and seminar tasks', async ({ page }) => {
  for (const seminar of content.seminars) {
    for (const note of [...seminar.topics, ...(seminar.tasks ? [seminar.tasks] : [])]) {
      await page.goto(`#${note.route}`);
      await expect(page.getByRole('heading', { name: note.title, exact: true, level: 1 })).toBeVisible();
      await expect(page.locator('.breadcrumbs')).toContainText(seminar.title);
      for (const image of await page.locator('article img').all()) {
        await image.scrollIntoViewIfNeeded();
        await expect.poll(() => image.evaluate((img: HTMLImageElement) => img.naturalWidth)).toBeGreaterThan(0);
        await expect(image).toHaveAttribute('src', /^\/qa-repo\/content\//);
      }
      if (note.path === seminar.tasks?.path) {
        await expect(page.locator('.seminar-tabs .selected')).toContainText('Задания на семинар');
        await expect(page.locator('.git-instructions')).toContainText(`submissions/${seminar.id}/`);
        for (const id of seminar.taskIds) await expect(page.locator('.git-instructions')).toContainText(`${id}.c`);
      }
    }
  }
  const punctuated = notes.find(note => note.path.includes(','));
  if (punctuated) {
    await page.goto(`#${punctuated.route}`);
    await page.reload();
    await expect(page.getByRole('heading', { name: punctuated.title, exact: true, level: 1 })).toBeVisible();
  }
});
