import config from '../../site.config.json';
export type RunnerEvent = { type: string; text?: string; stream?: 'stdout' | 'stderr'; message?: string; elapsedMs?: number; exitCode?: number; compilationFailed?: boolean };
export function runC(source: string, stdin: string, onEvent: (event: RunnerEvent) => void) {
  const worker = new Worker(`${import.meta.env.BASE_URL}c-worker.mjs`, { type: 'module' });
  let ended = false;
  let timer: ReturnType<typeof setTimeout>;
  const finish = () => { ended = true; clearTimeout(timer); worker.terminate(); };
  const deadline = (ms: number, message: string) => {
    clearTimeout(timer);
    timer = setTimeout(() => { if (!ended) { finish(); onEvent({ type: 'error', message }); } }, ms);
  };
  deadline(config.compilationTimeoutMs, 'Загрузка или компиляция заняла слишком много времени. Проверьте соединение и попробуйте снова.');
  worker.onmessage = ({ data }: MessageEvent<RunnerEvent>) => {
    if (ended) return;
    if (data.type === 'running') deadline(config.executionTimeoutMs, `Превышено время выполнения (${config.executionTimeoutMs / 1000} с). Программа остановлена.`);
    if (data.type === 'done' || data.type === 'error') finish();
    onEvent(data);
  };
  worker.onmessageerror = () => {
    if (!ended) {
      finish();
      onEvent({ type: 'error', message: 'Ошибка обмена сообщениями с компилятором (messageerror).' });
    }
  };
  worker.onerror = event => { event.preventDefault(); if (!ended) { finish(); onEvent({ type: 'error', message: event.message || 'Не удалось загрузить компилятор. Выполните npm run toolchain.' }); } };
  worker.postMessage({ source, stdin });
  return () => { if (!ended) finish(); };
}
