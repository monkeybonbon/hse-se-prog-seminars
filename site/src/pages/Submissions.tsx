import { useEffect, useState } from 'react';
import config from '../../site.config.json';
import type { Seminar, SubmissionReport } from '../types';
import { GitInstructions } from '../components/GitInstructions';

const formatDate = (value: string | null) => value ? new Intl.DateTimeFormat('ru-RU', { dateStyle: 'short', timeStyle: 'short' }).format(new Date(value)) : '—';
export function Submissions({ seminars }: { seminars: Seminar[] }) {
  const [report, setReport] = useState<SubmissionReport | null>(null);
  const [error, setError] = useState('');
  const [loading, setLoading] = useState(true);
  const [group, setGroup] = useState('');
  const [seminarId, setSeminarId] = useState('');
  const [search, setSearch] = useState('');
  const [now, setNow] = useState(Date.now());
  async function load() {
    setLoading(true); setError('');
    try {
      const response = await fetch(`${import.meta.env.BASE_URL}submissions.json?t=${Date.now()}`, { cache: 'no-store', signal: AbortSignal.timeout(15000) });
      if (!response.ok) throw new Error('Отчёт пока недоступен. Он появится после запуска workflow на GitHub.');
      const value = await response.json();
      if (!Array.isArray(value.students) || typeof value.status !== 'string') throw new Error('Некорректный формат отчёта.');
      setReport(value); setNow(Date.now());
    } catch (error) { setError(error instanceof Error ? error.message : 'Не удалось загрузить отчёт.'); }
    finally { setLoading(false); }
  }
  useEffect(() => { void load(); const timer = setInterval(() => setNow(Date.now()), 60000); return () => clearInterval(timer); }, []);
  const stale = !report?.updatedAt || now - Date.parse(report.updatedAt) > config.reportStaleMinutes * 60000;
  const groups = [...new Set(report?.students.map(student => student.group) || [])].sort();
  const visible = seminarId ? seminars.filter(seminar => seminar.id === seminarId) : seminars;
  const students = report?.students.filter(student => (!group || student.group === group) && `${student.surname} ${student.branch}`.toLowerCase().includes(search.toLowerCase())) || [];
  return <>
    <span className="eyebrow">ПРАКТИКА / ВЕТКИ РЕПОЗИТОРИЯ</span><h1>Сдача заданий</h1>
    <p className="lead">Все решения — в своей ветке. Здесь видно, какие файлы уже загружены.</p>
    <div className="notice"><strong>Загружено ≠ принято.</strong> Таблица показывает наличие файлов. Проверка правильности решений проводится отдельно.</div>
    <div className="report-info"><span>Обновлено: {formatDate(report?.updatedAt || null)}</span><button onClick={load} disabled={loading}>{loading ? 'Загрузка…' : '↻ Обновить данные'}</button></div>
    {(error || report?.status === 'unavailable' || report?.status === 'partial' || stale && report) && <p className="warning" role="status">{error || (report?.status === 'unavailable' ? 'Не удалось получить актуальные данные GitHub. Ниже последний доступный отчёт.' : report?.status === 'partial' ? 'Данные некоторых веток недоступны. Для них статус сдачи неизвестен.' : 'Отчёт устарел. Дождитесь следующего запуска GitHub Actions.')} {report?.attemptedAt && `Последняя попытка: ${formatDate(report.attemptedAt)}.`}</p>}
    <div className="report-filters"><label>Группа<select aria-label="Группа" value={group} onChange={event => setGroup(event.target.value)}><option value="">Все группы</option>{groups.map(item => <option key={item}>{item}</option>)}</select></label><label>Семинар<select aria-label="Семинар" value={seminarId} onChange={event => setSeminarId(event.target.value)}><option value="">Все семинары</option>{seminars.map(item => <option value={item.id} key={item.id}>{item.title}</option>)}</select></label><label>Студент<input value={search} onChange={event => setSearch(event.target.value)} placeholder="Поиск по фамилии" /></label></div>
    <div className="table-scroll submission-table" tabIndex={0} aria-label="Таблица загруженных решений"><table>
      <thead><tr><th rowSpan={2}>Студент / ветка</th>{visible.map(seminar => <th key={seminar.id} colSpan={Math.max(1, seminar.taskCount)}>{seminar.title}</th>)}<th rowSpan={2}>Последний commit</th></tr><tr>{visible.flatMap(seminar => seminar.taskCount ? Array.from({ length: seminar.taskCount }, (_, i) => <th key={`${seminar.id}-${i}`}>№ {i + 1}</th>) : [<th key={seminar.id}>Нет заданий</th>])}</tr></thead>
      <tbody>{students.map(student => <tr key={student.branch}><th><span>{student.surname}</span><small>{student.group}</small>{student.sha ? <a href={`https://github.com/${config.repository}/tree/${student.sha}`} target="_blank" rel="noreferrer">{student.branch} ↗</a> : <small>{student.branch} · ветка не найдена</small>}</th>{visible.flatMap(seminar => seminar.taskCount ? Array.from({ length: seminar.taskCount }, (_, i) => {
        const file = `${i + 1}.c`;
        const uploaded = student.submissions[seminar.id]?.includes(file);
        const unknown = student.status === 'unavailable';
        return <td key={`${seminar.id}-${i}`} className={unknown ? 'unknown' : uploaded ? 'uploaded' : 'not-uploaded'}>{unknown ? 'Нет данных' : uploaded && student.sha ? <a href={`https://github.com/${config.repository}/blob/${student.sha}/submissions/${seminar.id}/${file}`} target="_blank" rel="noreferrer">Загружено ↗</a> : 'Не загружено'}</td>;
      }) : [<td key={seminar.id}>—</td>])}<td className="commit-date">{formatDate(student.lastCommitAt)}{student.sha && <code>{student.sha.slice(0, 7)}</code>}</td></tr>)}</tbody>
    </table></div>
    {!loading && students.length === 0 && <p className="empty-state">{report?.students.length ? 'По выбранным фильтрам студентов нет.' : 'Студенческие ветки пока не обнаружены. Ожидаемые студенты появятся здесь, если преподаватель добавит students.json.'}</p>}
    {!!report?.warnings?.length && <details className="report-warnings"><summary>Диагностика сбора ({report.warnings.length})</summary><ul>{report.warnings.map((warning, i) => <li key={i}>{warning}</li>)}</ul></details>}
    <p className="muted small-text">Кнопка загружает опубликованный JSON. Сбор веток выполняется в GitHub Actions каждые 15 минут и при push в main; запуски по расписанию могут задерживаться.</p>
    <GitInstructions />
  </>;
}
