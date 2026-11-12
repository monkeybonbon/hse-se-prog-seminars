import { useEffect, useRef, useState } from 'react';
import { EditorView, keymap } from '@codemirror/view';
import { EditorState } from '@codemirror/state';
import { basicSetup } from 'codemirror';
import { cpp } from '@codemirror/lang-cpp';
import { HighlightStyle, syntaxHighlighting } from '@codemirror/language';
import { tags } from '@lezer/highlight';
import { runC, type RunnerEvent } from '../services/runner';

const colors = HighlightStyle.define([
  { tag: tags.keyword, color: '#a44269' }, { tag: tags.string, color: '#70794c' },
  { tag: tags.number, color: '#a76c36' }, { tag: tags.comment, color: '#968492', fontStyle: 'italic' },
  { tag: tags.typeName, color: '#94619b' }, { tag: tags.function(tags.variableName), color: '#88604e' },
  { tag: tags.meta, color: '#a44269' },
]);
const editorTheme = EditorView.theme({
  '&': { fontSize: '13px', color: '#4e3c46', backgroundColor: '#fff9fb' },
  '.cm-content': { fontFamily: '"Cascadia Code", "SFMono-Regular", Consolas, monospace', padding: '12px 0', minHeight: '135px' },
  '.cm-gutters': { backgroundColor: '#f8edf2', color: '#ac8c9a', border: 'none' },
  '.cm-activeLine, .cm-activeLineGutter': { backgroundColor: '#efdae44d' },
  '.cm-focused': { outline: 'none' }, '.cm-cursor': { borderLeftColor: '#a44269' },
  '.cm-selectionBackground, &.cm-focused .cm-selectionBackground': { background: '#e7c8dc' },
  '.cm-scroller': { overflow: 'auto' },
});

export function CodeEditor({ source, notePath, blockId }: { source: string; notePath: string; blockId: string }) {
  const storageKey = `c-notes:v1:${notePath}:${blockId}`;
  const [storageError, setStorageError] = useState(false);
  const [code, setCode] = useState(() => { try { return localStorage.getItem(storageKey) ?? source; } catch { return source; } });
  const [stdin, setStdin] = useState('');
  const [status, setStatus] = useState('Готов к запуску');
  const [busy, setBusy] = useState(false);
  const [stdout, setStdout] = useState('');
  const [stderr, setStderr] = useState('');
  const [diagnostics, setDiagnostics] = useState('');
  const [outputTab, setOutputTab] = useState<'stdout' | 'stderr' | 'diagnostics'>('stdout');
  const host = useRef<HTMLDivElement>(null);
  const editor = useRef<EditorView | null>(null);
  const stop = useRef<(() => void) | null>(null);
  const latestCode = useRef(code);
  latestCode.current = code;
  useEffect(() => {
    try { localStorage.setItem(storageKey, code); } catch { setStorageError(true); }
  }, [code, storageKey]);
  const startRef = useRef<() => void>(() => {});
  useEffect(() => {
    if (!host.current) return;
    const view = new EditorView({
      parent: host.current,
      state: EditorState.create({ doc: latestCode.current, extensions: [basicSetup, cpp(), editorTheme, syntaxHighlighting(colors),
        EditorView.contentAttributes.of({ 'aria-label': 'Редактор кода C', spellcheck: 'false' }),
        keymap.of([{ key: 'Mod-Enter', run: () => { startRef.current(); return true; } }]),
        EditorView.updateListener.of(update => { if (update.docChanged) setCode(update.state.doc.toString()); }),
      ] }),
    });
    editor.current = view;
    return () => { view.destroy(); editor.current = null; stop.current?.(); };
  }, []);
  function onEvent(event: RunnerEvent) {
    if (event.type === 'loading') setStatus('Загрузка компилятора…');
    if (event.type === 'compiling') setStatus('Компиляция…');
    if (event.type === 'progress' && event.message) setStatus(`${event.message}${event.elapsedMs !== undefined ? ` · ${(event.elapsedMs / 1000).toFixed(1)} с` : ''}`);
    if (event.type === 'running') setStatus('Выполнение…');
    if (event.type === 'output') {
      (event.stream === 'stderr' ? setStderr : setStdout)(value => value + event.text);
      if (event.stream === 'stderr') setOutputTab('stderr');
    }
    if (event.type === 'diagnostics') setDiagnostics(value => value + event.text);
    if (event.type === 'error') { setStatus(event.message || 'Ошибка выполнения'); setBusy(false); stop.current = null; }
    if (event.type === 'done') {
      setStatus(`${event.compilationFailed ? 'Ошибка компиляции' : 'Выполнение завершено'} · код ${event.exitCode}`);
      setBusy(false); stop.current = null;
      if (event.compilationFailed) setOutputTab('diagnostics');
    }
  }
  function start() {
    if (busy) return;
    setStdout(''); setStderr(''); setDiagnostics(''); setOutputTab('stdout'); setBusy(true);
    try { stop.current = runC(latestCode.current, stdin, onEvent); }
    catch (error) { setStatus(String(error)); setBusy(false); stop.current = null; }
  }
  startRef.current = start;
  function reset() {
    if (editor.current) editor.current.dispatch({ changes: { from: 0, to: editor.current.state.doc.length, insert: source } });
    setCode(source);
  }
  return <section className="code-editor" aria-label="Интерактивный пример C">
    <div className="code-toolbar"><span className="file-label"><span className="file-dot" /> main.c <span className="muted">/ C11</span></span><span className="toolbar-actions">
      <button onClick={reset} disabled={busy} title="Восстановить код из конспекта">↺ Сбросить</button>
      {busy ? <button className="run-button" onClick={() => { stop.current?.(); stop.current = null; setBusy(false); setStatus('Программа остановлена'); }}>■ Остановить</button> : <button className="run-button" onClick={start}>▶ Запустить</button>}
    </span></div>
    <div ref={host} />
    <details className="stdin"><summary>Ввод программы <span>stdin</span></summary><textarea aria-label="stdin" value={stdin} onChange={event => setStdin(event.target.value)} placeholder="Данные для scanf, например: 12 30" /></details>
    <div className="output-tabs" role="tablist" aria-label="Результат программы">{(['stdout', 'stderr', 'diagnostics'] as const).map(tab => <button key={tab} role="tab" aria-selected={outputTab === tab} onClick={() => setOutputTab(tab)}>{tab === 'diagnostics' ? 'Компилятор' : tab}{(tab === 'stderr' && stderr || tab === 'diagnostics' && diagnostics) ? ' •' : ''}</button>)}<span className={busy ? 'running-dot' : 'idle-dot'} /></div>
    <pre className="program-output" role="tabpanel" aria-label={outputTab}>{({ stdout, stderr, diagnostics })[outputTab] || <span className="output-placeholder">{busy ? 'Ожидание результата…' : 'Здесь появится вывод программы'}</span>}</pre>
    <div className="editor-status" role="status"><span>{status}</span><span>{code === source ? 'Исходный код' : 'Изменено · сохранено локально'}</span></div>
    {storageError && <p className="warning">Браузер запретил localStorage или хранилище заполнено. Изменения сохраняются только до закрытия страницы.</p>}
  </section>;
}
