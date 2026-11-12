import { mkdir, readFile, writeFile } from 'node:fs/promises';
import { createHash } from 'node:crypto';

// Immutable Derle artifacts; no application JS from Derle is redistributed.
export const revision = '0ca413907c0472fe04687037895378a6c51ff5b4';
const artifacts = {
  'clang.mjs': 'f649891db10422819537a6bf08cca9a1c83ddb7a',
  'clang.wasm': '4976f125f12b4b0add8b8bb3878abc64498a8863',
  'lld.mjs': 'e7900d608b4fa237da5041e3c91f2a28d0a5dbb7',
  'lld.wasm': 'ea42b3d942ab63dc9d5ed0ed925ebc6169f27f52',
  'sysroot.tar': '97bd03d63eaa60ec527c692c25515cad1389f989',
};
function gitHash(bytes) {
  return createHash('sha1').update(`blob ${bytes.length}\0`).update(bytes).digest('hex');
}
await mkdir('public/toolchain/licenses', { recursive: true });
for (const [name, expected] of Object.entries(artifacts)) {
  const target = `public/toolchain/${name}`;
  try { if (gitHash(await readFile(target)) === expected) { console.log(`Cached: ${name}`); continue; } } catch {}
  console.log(`Downloading ${name}…`);
  const response = await fetch(`https://raw.githubusercontent.com/senolgulgonul/derle/${revision}/toolchain/${name}`, { signal: AbortSignal.timeout(180000) });
  if (!response.ok) throw new Error(`${name}: HTTP ${response.status}`);
  const bytes = Buffer.from(await response.arrayBuffer());
  if (gitHash(bytes) !== expected) throw new Error(`Integrity check failed: ${name}`);
  await writeFile(target, bytes);
}
const licenses = {
  'LLVM.txt': 'https://raw.githubusercontent.com/llvm/llvm-project/llvmorg-18.1.2/llvm/LICENSE.TXT',
  'Emscripten.txt': 'https://raw.githubusercontent.com/emscripten-core/emscripten/3.1.58/LICENSE',
  'wasi-libc.txt': 'https://raw.githubusercontent.com/WebAssembly/wasi-libc/wasi-sdk-24/LICENSE',
  'wasi-APACHE-LLVM.txt': 'https://raw.githubusercontent.com/WebAssembly/wasi-libc/wasi-sdk-24/LICENSE-APACHE-LLVM',
  'wasi-APACHE.txt': 'https://raw.githubusercontent.com/WebAssembly/wasi-libc/wasi-sdk-24/LICENSE-APACHE',
  'wasi-MIT.txt': 'https://raw.githubusercontent.com/WebAssembly/wasi-libc/wasi-sdk-24/LICENSE-MIT',
  'cloudlibc.txt': 'https://raw.githubusercontent.com/WebAssembly/wasi-libc/wasi-sdk-24/libc-bottom-half/cloudlibc/LICENSE',
  'musl.txt': 'https://raw.githubusercontent.com/WebAssembly/wasi-libc/wasi-sdk-24/libc-top-half/musl/COPYRIGHT',
  'dlmalloc-notices.c': 'https://raw.githubusercontent.com/WebAssembly/wasi-libc/wasi-sdk-24/dlmalloc/src/malloc.c',
  'emmalloc-notices.c': 'https://raw.githubusercontent.com/WebAssembly/wasi-libc/wasi-sdk-24/emmalloc/emmalloc.c',
};
for (const [name, url] of Object.entries(licenses)) {
  const response = await fetch(url, { signal: AbortSignal.timeout(30000) });
  if (!response.ok) throw new Error(`License ${name}: HTTP ${response.status}`);
  await writeFile(`public/toolchain/licenses/${name}`, await response.text());
}
await writeFile('public/toolchain/NOTICE.txt', `Clang/LLVM 18.1.2, wasi-sdk 24, Emscripten runtime.\nBinary source: https://github.com/senolgulgonul/derle/tree/${revision}/toolchain\nLLVM: Apache-2.0 WITH LLVM-exception; wasi-libc: Apache-2.0/MIT/BSD; Emscripten: MIT/NCSA.\nSee licenses/ for full notices. Application code from Derle is not included.\n`);
console.log('Toolchain ready.');
