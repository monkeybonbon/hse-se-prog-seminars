import { readFile, mkdir, writeFile } from 'node:fs/promises';
import { pathToFileURL } from 'node:url';
import path from 'node:path';

export function createGitHubAPI({ repository, token, fetcher = fetch, sleep = ms => new Promise(resolve => setTimeout(resolve, ms)) }) {
  return async function api(endpoint) {
    for (let attempt = 0; attempt < 3; attempt++) {
      let response;
      try {
        response = await fetcher(`https://api.github.com/repos/${repository}${endpoint}`, {
          headers: { Accept: 'application/vnd.github+json', 'X-GitHub-Api-Version': '2022-11-28', ...(token ? { Authorization: `Bearer ${token}` } : {}) },
          signal: AbortSignal.timeout(30000),
        });
      } catch {
        if (attempt === 2) throw new Error('GitHub API: network unavailable');
        await sleep(500 * 2 ** attempt); continue;
      }
      if (response.ok) return response.json();
      if (response.status === 404) return null;
      const limited = response.status === 429 || response.status === 403;
      const retryable = limited || response.status >= 500;
      const retrySeconds = Number(response.headers.get('retry-after')) || 2 ** attempt;
      if (retryable && attempt < 2 && retrySeconds <= 10) { await sleep(retrySeconds * 1000); continue; }
      throw new Error(limited ? `GitHub API rate limit (HTTP ${response.status})` : `GitHub API HTTP ${response.status}`);
    }
  };
}

export async function submissionPaths(api, commitSha) {
  const commit = await api(`/git/commits/${encodeURIComponent(commitSha)}`);
  if (!commit) throw new Error('Branch was deleted or commit is unavailable');
  const recursive = await api(`/git/trees/${commit.tree.sha}?recursive=1`);
  if (!recursive) throw new Error('File tree unavailable');
  if (!recursive.truncated) return { paths: recursive.tree.filter(entry => entry.type === 'blob' && entry.mode !== '120000').map(entry => entry.path), commit };
  // Never infer absence from a truncated response. Read only the submissions subtree.
  const root = await api(`/git/trees/${commit.tree.sha}`);
  if (!root || root.truncated) throw new Error('Truncated root tree');
  const directory = root.tree.find(entry => entry.type === 'tree' && entry.path === 'submissions');
  if (!directory) return { paths: [], commit };
  const paths = [];
  const queue = [{ sha: directory.sha, prefix: 'submissions' }];
  while (queue.length) {
    const item = queue.shift();
    const tree = await api(`/git/trees/${item.sha}`);
    if (!tree || tree.truncated) throw new Error('Incomplete submissions tree');
    for (const entry of tree.tree) {
      const full = `${item.prefix}/${entry.path}`;
      if (entry.type === 'tree' && item.prefix === 'submissions' && /^seminar-\d+$/.test(entry.path)) queue.push({ sha: entry.sha, prefix: full });
      if (entry.type === 'blob' && entry.mode !== '120000') paths.push(full);
    }
  }
  return { paths, commit };
}

export async function collectSubmissions({ api, config, seminars, roster = [], now = new Date().toISOString() }) {
  const pattern = new RegExp(config.branchPattern);
  const branches = [];
  for (let page = 1; ; page++) {
    const batch = await api(`/branches?per_page=100&page=${page}`);
    if (!Array.isArray(batch)) throw new Error('Repository or branch list unavailable');
    branches.push(...batch);
    if (batch.length < 100) break;
  }
  const warnings = [];
  const valid = branches.filter(branch => {
    pattern.lastIndex = 0;
    if (pattern.test(branch.name)) return true;
    if (branch.name.startsWith('BPI')) warnings.push(`Invalid branch name: ${branch.name}`);
    return false;
  });
  const byName = new Map(valid.map(branch => [branch.name, branch]));
  for (const entry of roster) {
    const name = typeof entry === 'string' ? entry : entry.branch;
    pattern.lastIndex = 0;
    if (!pattern.test(name)) { warnings.push(`Invalid roster branch: ${name}`); continue; }
    if (!byName.has(name)) byName.set(name, { name, commit: null });
  }
  const students = [];
  for (const branch of byName.values()) {
    const [group, surname] = branch.name.split('_');
    const student = { branch: branch.name, group, surname, status: branch.commit ? 'ok' : 'missing', sha: branch.commit?.sha || null, lastCommitAt: null, submissions: {} };
    for (const seminar of seminars) student.submissions[seminar.id] = [];
    if (branch.commit) {
      try {
        const { paths, commit } = await submissionPaths(api, branch.commit.sha);
        student.lastCommitAt = commit.committer?.date || commit.author?.date || null;
        for (const file of paths.filter(file => file.startsWith('submissions/'))) {
          const match = file.match(/^submissions\/(seminar-\d+)\/([1-9]\d*)\.c$/);
          const seminar = match && seminars.find(item => item.id === match[1]);
          if (match && seminar && Number(match[2]) <= seminar.taskCount) student.submissions[seminar.id].push(`${match[2]}.c`);
          else if (file !== 'submissions/README.md') warnings.push(`${branch.name}: unexpected file ${file}`);
        }
      } catch (error) { student.status = 'unavailable'; warnings.push(`${branch.name}: ${error.message}`); }
    }
    students.push(student);
  }
  students.sort((a, b) => a.group.localeCompare(b.group, 'ru', { numeric: true }) || a.surname.localeCompare(b.surname));
  return { status: students.some(student => student.status === 'unavailable') ? 'partial' : 'ok', updatedAt: now, attemptedAt: now, repository: config.repository, seminars, students, warnings };
}

async function main() {
  const config = JSON.parse(await readFile('site.config.json', 'utf8'));
  if (process.env.GITHUB_REPOSITORY) config.repository = process.env.GITHUB_REPOSITORY;
  const { seminars } = JSON.parse(await readFile('public/content/manifest.json', 'utf8'));
  let roster = [];
  try { roster = JSON.parse(await readFile('students.json', 'utf8')); if (!Array.isArray(roster)) throw new Error('students.json must be an array'); }
  catch (error) { if (error.code !== 'ENOENT') throw error; }
  let report;
  try { report = await collectSubmissions({ api: createGitHubAPI({ repository: config.repository, token: process.env.GITHUB_TOKEN }), config, seminars, roster }); }
  catch (error) {
    try { report = JSON.parse(await readFile('public/submissions.json', 'utf8')); } catch { report = { students: [], seminars, updatedAt: null }; }
    report = { ...report, status: 'unavailable', attemptedAt: new Date().toISOString(), warnings: [error.message] };
    console.error(`Submissions unavailable: ${error.message}`);
  }
  await mkdir('public', { recursive: true });
  await writeFile('public/submissions.json', JSON.stringify(report, null, 2));
  console.log(`Submissions: ${report.status}, ${report.students.length} students.`);
}
if (process.argv[1] && import.meta.url === pathToFileURL(path.resolve(process.argv[1])).href) await main();
