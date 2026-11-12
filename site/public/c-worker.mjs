// Our own compiler orchestration and WASI preview1 host. All URLs are same-origin.
const encoder = new TextEncoder();
const decoder = new TextDecoder();
const emit = (type, fields = {}) => self.postMessage({ type, ...fields });
let lastStage = 'создание worker';
const startedAt = performance.now();
function stage(message) {
  lastStage = message;
  emit('progress', { message, elapsedMs: Math.round(performance.now() - startedAt) });
}


function mountArchive(fs, bytes) {
  const string = (offset, length) => decoder.decode(bytes.subarray(offset, offset + length)).split('\0')[0];
  for (let offset = 0; offset + 512 <= bytes.length;) {
    const name = string(offset, 100);
    if (!name) break;
    const prefix = string(offset + 345, 155);
    const file = `${prefix ? prefix + '/' : ''}${name}`.replace(/^\.\//, '');
    const size = parseInt(string(offset + 124, 12).trim() || '0', 8);
    const kind = string(offset + 156, 1);
    if (!Number.isFinite(size) || offset + 512 + size > bytes.length) throw new Error('Повреждён sysroot.tar');
    if (file.startsWith('sysroot/') && !file.split('/').includes('..')) {
      const full = '/' + file.replace(/\/$/, '');
      if (kind === '5') fs.mkdirTree(full);
      if (kind === '0' || !kind) {
        fs.mkdirTree(full.slice(0, full.lastIndexOf('/')));
        fs.writeFile(full, bytes.subarray(offset + 512, offset + 512 + size));
      }
    }
    offset += 512 + Math.ceil(size / 512) * 512;
  }
}

async function fetchBytes(url) {
  const response = await fetch(url, { signal: AbortSignal.timeout(90000), cache: 'force-cache' });
  if (!response.ok) throw new Error(`Не удалось загрузить ${url}: HTTP ${response.status}. Выполните npm run toolchain.`);
  return new Uint8Array(await response.arrayBuffer());
}

async function tool(factory, args, input, output, archive, wasm) {
  let diagnostics = '';
  stage(`${typeof input === 'string' ? 'Clang' : 'LLD'}: инициализация WebAssembly`);
  const module = await factory({
    noInitialRun: true, wasmBinary: wasm, thisProgram: typeof input === 'string' ? 'clang' : 'wasm-ld',
    print: line => { diagnostics += line + '\n'; },
    printErr: line => { diagnostics += line + '\n'; },
    // Emscripten's default quit() calls process.exit in Node; retain browser-like behavior in tests.
    quit: (status, error) => { throw error ?? { status }; },
  });
  stage(`${typeof input === 'string' ? 'Clang' : 'LLD'}: подключение sysroot`);
  mountArchive(module.FS, archive);
  module.FS.mkdirTree('/work');
  module.FS.writeFile('/work/main.' + (typeof input === 'string' ? 'c' : 'o'), typeof input === 'string' ? encoder.encode(input) : input);
  let status = 0;
  stage(`${typeof input === 'string' ? 'Clang' : 'LLD'}: выполнение`);
  try { status = module.callMain(args) ?? 0; }
  catch (error) {
    // Emscripten reports a normal process exit as a thrown ExitStatus. Some
    // builds invoke quit(status) without an Error object; both are valid.
    if (typeof error?.status === 'number') status = error.status;
    else if (typeof error === 'number') status = error;
    else throw new Error(`${diagnostics}\n${error?.message || String(error)}`, { cause: error });
  }
  stage(`${typeof input === 'string' ? 'Clang' : 'LLD'}: завершён (код ${status})`);
  let bytes = null;
  if (status === 0) {
    try { bytes = module.FS.readFile(output).slice(); }
    catch (error) { throw new Error(`Компилятор завершился без выходного файла ${output}: ${error?.message || error}`); }
  }
  return { status, diagnostics, bytes };
}

class ProgramExit { constructor(code) { this.code = code; } }

async function execute(wasm, stdin) {
  const input = encoder.encode(stdin);
  let cursor = 0;
  let instance;
  let outputBytes = 0;
  const view = () => new DataView(instance.exports.memory.buffer);
  const memory = () => new Uint8Array(instance.exports.memory.buffer);
  const outputDecoders = { 1: new TextDecoder(), 2: new TextDecoder() };
  const wasi = {
    args_sizes_get(argc, size) { view().setUint32(argc, 0, true); view().setUint32(size, 0, true); return 0; },
    args_get() { return 0; },
    environ_sizes_get(count, size) { view().setUint32(count, 0, true); view().setUint32(size, 0, true); return 0; },
    environ_get() { return 0; },
    proc_exit(code) { throw new ProgramExit(code); },
    fd_write(fd, iovs, count, written) {
      if (fd !== 1 && fd !== 2) return 8; // BADF
      let total = 0;
      for (let i = 0; i < count; i++) {
        const pointer = view().getUint32(iovs + i * 8, true);
        const length = view().getUint32(iovs + i * 8 + 4, true);
        outputBytes += length;
        if (outputBytes > 1024 * 1024) throw new Error('Вывод превысил лимит 1 МиБ. Программа остановлена.');
        const text = outputDecoders[fd].decode(memory().subarray(pointer, pointer + length), { stream: true });
        if (text) emit('output', { stream: fd === 1 ? 'stdout' : 'stderr', text });
        total += length;
      }
      view().setUint32(written, total, true); return 0;
    },
    fd_read(fd, iovs, count, read) {
      if (fd !== 0) return 8;
      let total = 0;
      for (let i = 0; i < count; i++) {
        const pointer = view().getUint32(iovs + i * 8, true);
        const length = view().getUint32(iovs + i * 8 + 4, true);
        const slice = input.subarray(cursor, cursor + length);
        memory().set(slice, pointer); cursor += slice.length; total += slice.length;
      }
      view().setUint32(read, total, true); return 0;
    },
    fd_close(fd) { return fd >= 0 && fd <= 2 ? 0 : 8; },
    fd_seek() { return 70; }, // SPIPE: standard streams are not seekable.
    fd_fdstat_get(fd, pointer) {
      if (fd < 0 || fd > 2) return 8;
      memory().fill(0, pointer, pointer + 24);
      view().setUint8(pointer, 2); // CHARACTER_DEVICE
      view().setBigUint64(pointer + 8, 0x1fffffn, true); return 0;
    },
    fd_filestat_get(fd, pointer) {
      if (fd < 0 || fd > 2) return 8;
      memory().fill(0, pointer, pointer + 64); view().setUint8(pointer + 16, 2); return 0;
    },
    fd_prestat_get() { return 8; },
    fd_prestat_dir_name() { return 8; },
    path_open() { return 76; }, // NOTCAPABLE: no host filesystem access.
    clock_time_get(id, _precision, pointer) {
      const millis = id === 1 ? performance.now() : Date.now();
      view().setBigUint64(pointer, BigInt(Math.floor(millis * 1e6)), true); return 0;
    },
    clock_res_get(_id, pointer) { view().setBigUint64(pointer, 1000000n, true); return 0; },
    random_get(pointer, length) {
      for (let offset = 0; offset < length; offset += 65536) crypto.getRandomValues(memory().subarray(pointer + offset, pointer + Math.min(length, offset + 65536)));
      return 0;
    },
    sched_yield() { return 0; },
  };
  stage('WASI: подготовка WebAssembly');
  const module = await WebAssembly.compile(wasm);
  for (const descriptor of WebAssembly.Module.imports(module)) {
    if (descriptor.module !== 'wasi_snapshot_preview1') throw new Error(`Недопустимый импорт: ${descriptor.module}.${descriptor.name}`);
    if (!wasi[descriptor.name]) wasi[descriptor.name] = () => 52; // NOSYS
  }
  stage('WASI: создание экземпляра программы');
  instance = await WebAssembly.instantiate(module, { wasi_snapshot_preview1: wasi });
  emit('running');
  let code = 0;
  try { instance.exports._start(); }
  catch (error) { if (error instanceof ProgramExit) code = error.code; else throw error; }
  for (const [fd, decoder] of Object.entries(outputDecoders)) {
    const tail = decoder.decode();
    if (tail) emit('output', { stream: fd === '1' ? 'stdout' : 'stderr', text: tail });
  }
  return code;
}

self.onmessage = async ({ data }) => {
  try {
    emit('loading');
    const base = new URL('./toolchain/', import.meta.url);
    stage('Загрузка Clang, LLD и стандартной библиотеки C');
    const [clang, lld, archive, clangWasm, lldWasm] = await Promise.all([
      import(new URL('clang.mjs', base)), import(new URL('lld.mjs', base)),
      fetchBytes(new URL('sysroot.tar', base)), fetchBytes(new URL('clang.wasm', base)), fetchBytes(new URL('lld.wasm', base)),
    ]);
    stage('Компоненты компилятора загружены');
    emit('compiling');
    const object = await tool(clang.default, [
      '--target=wasm32-wasi', '--sysroot=/sysroot', '-resource-dir=/sysroot/lib/clang/18',
      '-std=c11', '-Wall', '-Wextra', '-O0', '-c', '/work/main.c', '-o', '/work/main.o',
    ], data.source, '/work/main.o', archive, clangWasm);
    if (object.diagnostics) emit('diagnostics', { text: object.diagnostics });
    if (object.status !== 0) { emit('done', { exitCode: object.status, compilationFailed: true }); return; }
    stage('Компиляция завершена, запуск линковщика');
    const linked = await tool(lld.default, [
      '--threads=1', '/sysroot/lib/wasm32-wasi/crt1.o', '/work/main.o', '-L/sysroot/lib/wasm32-wasi',
      '-lc', '-lm', '/sysroot/lib/clang/18/lib/wasi/libclang_rt.builtins-wasm32.a',
      '--max-memory=67108864', '-o', '/work/main.wasm',
    ], object.bytes, '/work/main.wasm', archive, lldWasm);
    if (linked.diagnostics) emit('diagnostics', { text: linked.diagnostics });
    if (linked.status !== 0) { emit('done', { exitCode: linked.status, compilationFailed: true }); return; }
    stage('Линковка завершена, запуск программы');
    const exitCode = await execute(linked.bytes, data.stdin || '');
    emit('done', { exitCode });
  } catch (error) {
    emit('diagnostics', { text: `Этап: ${lastStage}\n${error?.stack || String(error)}` });
    emit('error', { message: `Ошибка на этапе «${lastStage}»: ${error?.message || String(error)}` });
  }
};
