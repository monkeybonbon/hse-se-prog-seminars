import { defineConfig } from '@playwright/test';
export default defineConfig({
  testDir: './tests/e2e',
  timeout: 180000,
  expect: { timeout: 10000 },
  workers: 1,
  use: { baseURL: 'http://127.0.0.1:4173/qa-repo/', headless: true, actionTimeout: 15000, navigationTimeout: 20000, ...(process.env.PLAYWRIGHT_CHANNEL ? { channel: process.env.PLAYWRIGHT_CHANNEL } : {}), screenshot: 'only-on-failure' },
  webServer: { command: 'node scripts/serve-built.mjs', url: 'http://127.0.0.1:4173/qa-repo/', reuseExistingServer: !process.env.CI },
});
