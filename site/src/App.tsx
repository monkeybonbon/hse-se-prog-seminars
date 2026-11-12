import { useEffect, useMemo, useState } from 'react';
import { HashRouter, Link, Navigate, NavLink, useLocation } from 'react-router-dom';
import rawContent from './generated/content.json';
import config from '../site.config.json';
import type { Note, Seminar } from './types';
import { Markdown } from './components/Markdown';
import { GitInstructions } from './components/GitInstructions';
import { Submissions } from './pages/Submissions';

const seminars = rawContent.seminars as Seminar[];
const allNotes = seminars.flatMap(seminar => [...seminar.topics, ...(seminar.tasks ? [seminar.tasks] : [])]);
const first = allNotes[0];
const decoded = (value: string) => { try { return decodeURI(value); } catch { return value; } };
const exampleCount = (value: number) => `${value} ${value % 100 >= 11 && value % 100 <= 14 ? 'примеров' : value % 10 === 1 ? 'пример' : value % 10 >= 2 && value % 10 <= 4 ? 'примера' : 'примеров'} C`;
function Shell() {
  const location = useLocation();
  const [menu, setMenu] = useState(false);
  const [query, setQuery] = useState('');
  const [closed, setClosed] = useState<Set<string>>(new Set());
  const note = allNotes.find(item => decoded(item.route) === decoded(location.pathname));
  const seminar = seminars.find(item => item.id === note?.path.split('/')[0]);
  const submissions = location.pathname === '/submissions';
  const tasks = note?.path.endsWith('/tasks.md');
  const noteIndex = note ? allNotes.indexOf(note) : -1;
  const count = useMemo(() => seminars.reduce((total, item) => total + item.topics.length, 0), []);
  useEffect(() => {
    setMenu(false);
    document.title = `${note?.title || (submissions ? 'Сдача заданий' : 'Страница не найдена')} · ${config.title}`;
    const frame = requestAnimationFrame(() => {
      if (location.hash) {
        let id = location.hash.slice(1);
        try { id = decodeURIComponent(id); } catch {}
        document.getElementById(id)?.scrollIntoView({ behavior: 'smooth' });
      } else window.scrollTo(0, 0);
    });
    return () => cancelAnimationFrame(frame);
  }, [location.pathname, location.hash, note, submissions]);
  if (location.pathname === '/' && first) return <Navigate to={first.route} replace />;
  const matches = (item: Note) => !query || `${item.title} ${item.markdown}`.toLocaleLowerCase('ru').includes(query.toLocaleLowerCase('ru'));
  return <div className="workspace">
    <a className="skip-link" href="#reading-area" onClick={event => { event.preventDefault(); document.getElementById('reading-area')?.focus(); }}>К содержимому</a>
    <header className="topbar"><div className="brand"><span className="brand-mark">C<span>✦</span></span><Link to={first?.route || '/'}>{config.title}<small>ПРОГРАММИРОВАНИЕ · СЕМИНАРЫ</small></Link></div><nav aria-label="Основная навигация"><Link className={!submissions ? 'top-link active' : 'top-link'} to={first?.route || '/'}>Конспекты</Link><NavLink className="top-link" to="/submissions">Сдача заданий</NavLink><a className="repo-link" href={`https://github.com/${config.repository}`} target="_blank" rel="noreferrer">GitHub ↗</a></nav><button className="menu-toggle" aria-label="Меню семинаров" aria-expanded={menu} onClick={() => setMenu(value => !value)}>☰</button></header>
    <div className="workspace-body">
      {menu && <button className="sidebar-backdrop" aria-label="Закрыть меню" onClick={() => setMenu(false)} />}
      <aside className={`sidebar ${menu ? 'is-open' : ''}`} aria-label="Семинары и темы"><div className="sidebar-heading"><span>ВАШ УЧЕБНЫЙ БЛОКНОТ</span><span>✧</span></div><label className="search-field"><span>⌕</span><input aria-label="Поиск по конспектам" placeholder="Найти в конспектах…" value={query} onChange={event => setQuery(event.target.value)} />{query && <button aria-label="Очистить поиск" onClick={() => setQuery('')}>×</button>}</label><div className="tree-label">СОДЕРЖАНИЕ <span>{seminars.length} семинара</span></div>
        <nav className="note-tree">{seminars.map(item => <div key={item.id} className="seminar-group"><button className="seminar-toggle" aria-expanded={!closed.has(item.id) || !!query} onClick={() => setClosed(current => { const next = new Set(current); if (next.has(item.id)) next.delete(item.id); else next.add(item.id); return next; })}><span className="tree-chevron">{closed.has(item.id) && !query ? '›' : '⌄'}</span><span className="folder-icon">▱</span>{item.title}<span className="seminar-number">{String(item.number).padStart(2, '0')}</span></button>{(!closed.has(item.id) || query) && <div className="topic-list">{item.topics.filter(matches).map(topic => <NavLink key={topic.path} to={topic.route}><span className="note-icon">≡</span>{topic.title}</NavLink>)}{item.tasks && matches(item.tasks) && <NavLink className="tasks-link" to={item.tasks.route}><span className="note-icon">☷</span>Задания на семинар<span className="task-count">{item.taskCount}</span></NavLink>}</div>}</div>)}</nav>
        {query && !allNotes.some(matches) && <p className="search-empty">Ничего не найдено</p>}
        <div className="sidebar-bottom"><NavLink to="/submissions"><span>↥</span> Сдача заданий <span>↗</span></NavLink><div className="sidebar-tip"><span>✦</span><p>Читайте. Меняйте код.<br />Проверяйте свои идеи.</p></div><p className="local-note"><span className="idle-dot" /> Изменения кода хранятся у вас</p></div>
      </aside>
      <main id="reading-area" tabIndex={-1}>
        <div className="document-tab"><span>≡</span> {note?.title || (submissions ? 'Сдача заданий' : 'Конспекты')} <span className="tab-pin">✧</span><span className="document-label">C / учебный блокнот</span></div>
        <div className={`reading-layout ${submissions ? 'wide' : ''}`}><article className="article" key={note?.path || location.pathname}>
          {submissions ? <Submissions seminars={seminars} /> : note ? <>
            <div className="breadcrumbs"><Link to={first?.route || '/'}>Конспекты</Link><span>/</span><span>{seminar?.title}</span><span>/</span><span>{tasks ? 'Практика' : 'Теория'}</span></div>
            <div className="note-topline"><span className="eyebrow">{seminar?.title.toUpperCase()} · {tasks ? 'ЗАДАНИЯ' : 'КОНСПЕКТ'}</span><span className="reading-meta">{Math.max(1, Math.ceil(note.markdown.length / 1000))} мин чтения{note.codeBlocks > 0 ? ` · ${exampleCount(note.codeBlocks)}` : ''}</span></div>
            {seminar && <nav className="seminar-tabs" aria-label="Раздел семинара"><Link className={!tasks ? 'selected' : ''} to={seminar.topics[0]?.route || note.route}>Конспект</Link>{seminar.tasks && <Link className={tasks ? 'selected' : ''} to={seminar.tasks.route}>Задания на семинар <span>{seminar.taskCount}</span></Link>}</nav>}
            <Markdown note={note} />
            {tasks && seminar && <GitInstructions seminar={seminar.id} />}
            <nav className="page-navigation" aria-label="Переходы между темами">{noteIndex > 0 ? <Link to={allNotes[noteIndex - 1].route}><small>← ПРЕДЫДУЩАЯ ТЕМА</small>{allNotes[noteIndex - 1].title}</Link> : <span />}{noteIndex < allNotes.length - 1 && <Link to={allNotes[noteIndex + 1].route}><small>СЛЕДУЮЩАЯ ТЕМА →</small>{allNotes[noteIndex + 1].title}</Link>}</nav>
          </> : <><h1>{first ? 'Страница не найдена' : 'Блокнот пока пуст'}</h1><p>{first ? 'Возможно, заметка была перемещена.' : 'Добавьте Markdown-файлы в notes/seminar-01/topics/.'}</p>{first && <Link to={first.route}>Открыть первый конспект →</Link>}</>}
          <footer className="article-footer"><span>C · конспекты</span><span>{count} тем · учимся на практике <span className="footer-star">✦</span></span></footer>
        </article>
        {!submissions && note && <aside className="outline" aria-label="Оглавление темы"><div className="outline-label">НА ЭТОЙ СТРАНИЦЕ</div><nav>{note.headings.filter(heading => heading.depth > 1 && heading.depth < 4).map(heading => <Link className={heading.depth === 3 ? 'nested' : ''} key={heading.id} to={`${note.route}#${heading.id}`}>{heading.text}</Link>)}{tasks && <Link to={`${note.route}#how-to-submit`}>Как сдать задания</Link>}</nav><div className="outline-note"><span>⌘ ↵</span><p>Запустить код:<br /><kbd>Ctrl</kbd> + <kbd>Enter</kbd><br />или <kbd>⌘</kbd> + <kbd>Enter</kbd></p></div><p className="outline-caption">Каждый пример —<br />маленький эксперимент.</p><span className="outline-flower">✳</span></aside>}
        </div>
      </main>
    </div><div className="bottom-strip"><span>Место для ваших открытий</span><span>C11 · Clang / WebAssembly</span></div>
  </div>;
}
export default function App() { return <HashRouter><Shell /></HashRouter>; }
