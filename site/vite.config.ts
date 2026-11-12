import { defineConfig } from 'vite';
import react from '@vitejs/plugin-react';
import { generateContent } from './scripts/generate-content-manifest.mjs';

export default defineConfig({
  base: process.env.BASE_PATH || '/',
  plugins: [react(), {
    name: 'notes-reload',
    configureServer(server) {
      server.watcher.add('notes');
      let timer: ReturnType<typeof setTimeout>;
      server.watcher.on('all', (_event, path) => {
        if (!path.replaceAll('\\', '/').includes('/notes/')) return;
        clearTimeout(timer);
        timer = setTimeout(async () => {
          try { await generateContent(); server.ws.send({ type: 'full-reload' }); }
          catch (error) { console.error(error); }
        }, 150);
      });
    },
  }],
});
