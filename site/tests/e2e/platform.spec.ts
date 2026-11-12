import { test, expect, type Locator } from '@playwright/test';

const introduction = '#/notes/seminar-01/topics/01-introduction';
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
  await expect(page.getByRole('heading', { name: 'Привет, C!' })).toBeVisible();
  expect(requests.some(url => url.includes('/toolchain/'))).toBeFalsy();
  const image = page.locator('article img');
  await expect(image).toHaveJSProperty('complete', true);
  expect(await image.evaluate((img: HTMLImageElement) => img.naturalWidth)).toBeGreaterThan(0);
  const editor = page.locator('.code-editor');
  const code = '#include <stdio.h>\nint main(void) { printf("edited: %d\\n", 19 * 23); return 0; }';
  await setCode(editor, code);
  await compile(editor);
  await expect(editor.getByRole('tabpanel')).toContainText('edited: 437');
  await expect(editor.locator('.editor-status')).toContainText('код 0');
  await page.reload();
  await expect(editor.locator('.cm-content')).toContainText('19 * 23');
  await page.locator('article a').filter({ hasText: 'типы данных и переменные' }).click();
  await expect(page.getByRole('heading', { name: 'Типы данных', exact: true })).toBeVisible();
  await page.goBack();
  await expect(editor.locator('.cm-content')).toContainText('19 * 23');
  await editor.getByRole('button', { name: '↺ Сбросить' }).click();
  await expect(editor.locator('.cm-content')).toContainText('Привет, мир!');
  await compile(editor);
  await expect(editor.getByRole('tabpanel')).toContainText('Привет, мир!');
  expect(requests.filter(url => url.includes('/toolchain/')).every(url => new URL(url).origin === 'http://127.0.0.1:4173')).toBeTruthy();
});

test('stdin scanf, stderr, exit code, errors and independent editor state', async ({ page }) => {
  await page.goto('#/notes/seminar-01/topics/03-input-output');
  const editors = page.locator('.code-editor');
  const input = editors.nth(0);
  await input.locator('summary').click();
  await input.getByLabel('stdin', { exact: true }).fill('12 30');
  await compile(input);
  await expect(input.getByRole('tabpanel')).toContainText('Сумма: 42');
  await compile(editors.nth(1));
  await expect(editors.nth(1).locator('.editor-status')).toContainText('код 7');
  await expect(editors.nth(1).getByRole('tabpanel')).toContainText('Пример диагностического сообщения');
  await editors.nth(1).getByRole('tab', { name: 'stdout', exact: true }).click();
  await expect(editors.nth(1).getByRole('tabpanel')).toContainText('Начало программы');
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
  const editor = page.locator('.code-editor');
  await setCode(editor, '#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n#include <math.h>\nint main(void) { double x; if (scanf("%lf", &x)!=1) return 2; int *p=malloc(3*sizeof(int)); if(!p) return 1; for(int i=0;i<3;i++) p[i]=i+1; printf("%.1f %zu %d\\n", sqrt(x), strlen("abc"), *(p+2)); free(p); return 0; }');
  await editor.locator('summary').click();
  await editor.getByLabel('stdin', { exact: true }).fill('81');
  await compile(editor);
  await expect(editor.getByRole('tabpanel')).toContainText('9.0 3 3');
  await expect(editor.locator('.editor-status')).toContainText('код 0');
});

test('runaway program times out and manual stop leaves the page responsive', async ({ page }) => {
  await page.goto('#/notes/seminar-02/topics/02-loops');
  const editor = page.locator('.code-editor').nth(1);
  await compile(editor);
  await expect(editor.locator('.editor-status')).toContainText('Превышено время выполнения');
  await editor.getByRole('button', { name: '▶ Запустить' }).click();
  await expect(editor.locator('.editor-status')).toContainText('Выполнение…', { timeout: 120000 });
  await editor.getByRole('button', { name: '■ Остановить' }).click();
  await expect(editor.locator('.editor-status')).toContainText('Программа остановлена');
  await page.getByRole('link', { name: 'Сдача заданий', exact: true }).first().click();
  await expect(page.getByRole('heading', { name: 'Сдача заданий' })).toBeVisible();
});

test('failed toolchain load recovers with a clear message', async ({ page }) => {
  await page.route('**/toolchain/**', route => route.fulfill({ status: 503, body: 'unavailable' }));
  await page.goto(introduction);
  const editor = page.locator('.code-editor');
  await editor.getByRole('button', { name: '▶ Запустить' }).click();
  await expect(editor.locator('.editor-status')).toContainText(/Не удалось|Failed to fetch|HTTP 503/, { timeout: 30000 });
  await expect(editor.getByRole('button', { name: '▶ Запустить' })).toBeEnabled();
});

test('report filters, immutable file links, stale and unknown statuses', async ({ page }) => {
  await page.route('**/submissions.json?*', route => route.fulfill({ json: {
    status: 'partial', updatedAt: '2020-01-01T00:00:00Z', students: [
      { branch: 'BPI2412_Ivanov', group: 'BPI2412', surname: 'Ivanov', status: 'ok', sha: 'abc123', lastCommitAt: null, submissions: { 'seminar-01': ['1.c'], 'seminar-02': [] } },
      { branch: 'BPI2413_Petrov', group: 'BPI2413', surname: 'Petrov', status: 'unavailable', sha: 'def456', lastCommitAt: null, submissions: {} },
    ], warnings: [] },
  }));
  await page.goto('#/submissions');
  await expect(page.getByText('Данные некоторых веток недоступны.', { exact: false })).toBeVisible();
  await expect(page.getByRole('link', { name: 'Загружено ↗' })).toHaveAttribute('href', /blob\/abc123\/submissions\/seminar-01\/1.c/);
  await page.getByLabel('Группа', { exact: true }).selectOption('BPI2413');
  await expect(page.locator('tbody')).not.toContainText('Ivanov');
  await expect(page.locator('tbody')).toContainText('Нет данных');
  await page.getByLabel('Студент', { exact: true }).fill('absent');
  await expect(page.getByText('По выбранным фильтрам студентов нет.')).toBeVisible();
});

test('mobile layout, menu, direct hash URL, refresh, tasks instructions and full-text search', async ({ page }) => {
  await page.setViewportSize({ width: 375, height: 812 });
  await page.goto('#/notes/seminar-03/tasks');
  await expect(page.getByRole('heading', { name: 'Задания на семинар 3' })).toBeVisible();
  await expect(page.getByRole('heading', { name: 'Как сдать задания' })).toBeVisible();
  await page.reload();
  await expect(page.getByRole('heading', { name: 'Задания на семинар 3' })).toBeVisible();
  expect(await page.evaluate(() => document.documentElement.scrollWidth <= innerWidth)).toBeTruthy();
  await page.getByRole('button', { name: 'Меню семинаров' }).click();
  await page.getByRole('textbox', { name: 'Поиск по конспектам' }).fill('printf');
  await page.locator('.sidebar').getByRole('link', { name: 'Привет, C!' }).click();
  await expect(page.locator('.sidebar')).not.toBeVisible();
  await expect(page.getByRole('heading', { name: 'Привет, C!' })).toBeVisible();
  await expect(page.locator('.cm-content')).toBeVisible();
  await page.screenshot({ path: '.local/mobile.png', fullPage: true });
});

test('desktop screenshot, TOC anchors and KaTeX', async ({ page }) => {
  await page.setViewportSize({ width: 1440, height: 1100 });
  await page.goto(introduction);
  await expect(page.locator('.cm-content')).toBeVisible();
  await page.screenshot({ path: '.local/desktop.png', fullPage: true });
  await page.getByRole('complementary', { name: 'Оглавление темы' }).getByRole('link', { name: 'Как устроен этот код', exact: true }).click();
  await expect(page).toHaveURL(url => decodeURIComponent(url.hash).endsWith('#как-устроен-этот-код'));
  await page.goto('#/notes/seminar-01/topics/02-data-types');
  await expect(page.locator('.katex')).toBeVisible();
});
