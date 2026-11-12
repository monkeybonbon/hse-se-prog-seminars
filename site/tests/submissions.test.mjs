import test from 'node:test';
import assert from 'node:assert/strict';
import { collectSubmissions, createGitHubAPI, submissionPaths } from '../scripts/collect-submissions.mjs';

const config = { repository: 'test/course', branchPattern: '^BPI[0-9]+_[A-Za-z]+$' };
const seminars = [{ id: 'seminar-01', taskCount: 3 }, { id: 'seminar-02', taskCount: 2 }];
const blob = file => ({ path: file, type: 'blob', mode: '100644' });
const commit = { tree: { sha: 'tree' }, committer: { date: '2026-11-12T15:00:00Z' } };

test('pagination, roster, invalid branches and exact task paths; no student file content is fetched', async () => {
  const calls = [];
  const api = async endpoint => {
    calls.push(endpoint);
    if (endpoint.endsWith('&page=1')) return [...Array.from({ length: 98 }, (_, i) => ({ name: `other-${i}` })), { name: 'BPI2412_Ivanov', commit: { sha: 'a' } }, { name: 'BPI2412_bad-name' }];
    if (endpoint.endsWith('&page=2')) return [{ name: 'BPI2413_Petrov', commit: { sha: 'b' } }];
    if (endpoint.startsWith('/git/commits/')) return commit;
    if (endpoint.includes('/git/trees/')) return { truncated: false, tree: ['submissions/seminar-01/1.c', 'submissions/seminar-01/3.c', 'submissions/seminar-01/99.c', 'submissions/seminar-02/2.c', 'submissions/seminar-02/01.c', 'submissions/seminar-02/nested/1.c'].map(blob) };
    throw new Error(`unexpected ${endpoint}`);
  };
  const report = await collectSubmissions({ api, config, seminars, roster: ['BPI2412_Sidorov'] });
  assert.equal(report.students.length, 3);
  assert.equal(report.status, 'ok');
  assert.deepEqual(report.students[0].submissions['seminar-01'], ['1.c', '3.c']);
  assert.deepEqual(report.students[0].submissions['seminar-02'], ['2.c']);
  assert.equal(report.students.find(student => student.surname === 'Sidorov').status, 'missing');
  assert.ok(report.warnings.some(item => item.includes('Invalid branch')));
  assert.ok(report.warnings.some(item => item.includes('99.c')));
  assert.ok(calls.every(item => !item.includes('/contents/') && !item.includes('/blobs/')));
});

test('truncated tree falls back to complete targeted traversal, ignores symlinks', async () => {
  const api = async endpoint => {
    if (endpoint.startsWith('/git/commits')) return commit;
    if (endpoint.endsWith('?recursive=1')) return { truncated: true, tree: [] };
    if (endpoint === '/git/trees/tree') return { tree: [{ path: 'submissions', type: 'tree', sha: 's' }] };
    if (endpoint === '/git/trees/s') return { tree: [{ path: 'seminar-01', type: 'tree', sha: 't' }] };
    if (endpoint === '/git/trees/t') return { tree: [blob('1.c'), { ...blob('2.c'), mode: '120000' }] };
    throw new Error(endpoint);
  };
  assert.deepEqual((await submissionPaths(api, 'sha')).paths, ['submissions/seminar-01/1.c']);
});

test('unavailable/deleted branch is unknown, never reported as missing files', async () => {
  const api = async endpoint => endpoint.startsWith('/branches') ? [{ name: 'BPI2412_Ivanov', commit: { sha: 'gone' } }] : null;
  const report = await collectSubmissions({ api, config, seminars });
  assert.equal(report.status, 'partial');
  assert.equal(report.students[0].status, 'unavailable');
});

test('network and rate limits have bounded retries, token stays only in HTTP headers', async () => {
  let attempts = 0;
  const api = createGitHubAPI({ repository: 'test/course', token: 'secret-test-token', sleep: async () => {}, fetcher: async (url, opts) => {
    attempts++;
    assert.ok(!url.includes('secret-test-token'));
    assert.equal(opts.headers.Authorization, 'Bearer secret-test-token');
    return new Response('{}', { status: 429, headers: { 'retry-after': '1' } });
  } });
  await assert.rejects(api('/branches'), /rate limit/);
  assert.equal(attempts, 3);
  let networks = 0;
  const offline = createGitHubAPI({ repository: 'test/course', sleep: async () => {}, fetcher: async () => { networks++; throw new Error('offline'); } });
  await assert.rejects(offline('/branches'), /network unavailable/);
  assert.equal(networks, 3);
});

test('a truncated fallback cannot silently produce a valid empty report', async () => {
  await assert.rejects(submissionPaths(async endpoint => endpoint.startsWith('/git/commits') ? commit : { truncated: true, tree: [] }, 'sha'), /Truncated root tree/);
});
