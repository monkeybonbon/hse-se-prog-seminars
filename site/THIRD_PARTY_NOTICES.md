# Сторонние компоненты

Clang 18.1.2 / LLVM / lld: Apache-2.0 WITH LLVM-exception. wasi-libc (wasi-sdk 24): Apache-2.0 / MIT / BSD notices, перечисленные в его LICENSE. Generated Emscripten runtime: MIT / University of Illinois/NCSA.

Артефакты toolchain загружаются из [Derle, фиксированная ревизия](https://github.com/senolgulgonul/derle/tree/0ca413907c0472fe04687037895378a6c51ff5b4/toolchain). Целостность проверяется по Git blob SHA-1. Тексты лицензий копируются в `public/toolchain/licenses/` и публикуются вместе с бинарными файлами; `public/toolchain/NOTICE.txt` содержит атрибуцию.

Само приложение Derle не содержит отдельной лицензии. Его HTML, `js/compile.mjs`, worker и код WASI не копируются и не распространяются в этом проекте. Здесь реализованы собственные worker, загрузчик sysroot и WASI host. Используются только toolchain, покрытый перечисленными upstream лицензиями.

Источники лицензий: [LLVM 18.1.2](https://github.com/llvm/llvm-project/blob/llvmorg-18.1.2/llvm/LICENSE.TXT), [wasi-libc SDK 24](https://github.com/WebAssembly/wasi-libc/blob/wasi-sdk-24/LICENSE), [Emscripten](https://github.com/emscripten-core/emscripten/blob/3.1.58/LICENSE).

JS/CSS зависимости и их лицензии сохранены npm в `node_modules/*/LICENSE*`. React и react-markdown (MIT), CodeMirror (MIT), Vite (MIT), KaTeX (MIT), highlight.js (BSD-3-Clause), remark/rehype и unified (MIT). Полный список версий закреплён в `package-lock.json`.

Шрифт Golos Text (SIL Open Font License) поставляется через @fontsource-variable/golos-text вместе с сайтом; лицензия пакета находится в node_modules/@fontsource-variable/golos-text/LICENSE. При недоступности шрифта используется системный. SVG-узор и учебная диаграмма созданы для этого проекта.
