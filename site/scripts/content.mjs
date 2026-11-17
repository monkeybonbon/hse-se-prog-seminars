import path from 'node:path';
import { unified } from 'unified';
import remarkParse from 'remark-parse';
import remarkStringify from 'remark-stringify';
import remarkGfm from 'remark-gfm';
import remarkMath from 'remark-math';
import { visit } from 'unist-util-visit';
import GithubSlugger, { slug } from 'github-slugger';

const parser = unified().use(remarkParse).use(remarkGfm).use(remarkMath);
const printer = unified().use(remarkStringify).use(remarkGfm).use(remarkMath);
export const encodePath = value => value.split('/').map(encodeURIComponent).join('/');
export const topicRoute = notePath => `/notes/${encodePath(notePath.replace(/\.md$/i, ''))}`;
export function extractMetadata(raw, file) {
  const frontmatter = raw.match(/^---\r?\n([\s\S]*?)\r?\n---\r?\n/);
  const markdown = frontmatter ? raw.slice(frontmatter[0].length) : raw;
  const heading = parser.parse(markdown).children.find(node => node.type === 'heading' && node.depth === 1);
  const title = heading ? plainText(heading) : path.posix.basename(file, '.md').replace(/^\d+[-_ ]*/, '').replaceAll('-', ' ');
  const taskCount = frontmatter?.[1].match(/^taskCount:\s*(\d+)\s*$/m);
  return { markdown, title, taskCount: taskCount ? Number(taskCount[1]) : 0 };
}
function plainText(node) { return node.value ?? node.children?.map(plainText).join('') ?? ''; }

// Task numbers are authored in headings, not inferred from student branches.
export function taskIdsFromMarkdown(markdown) {
  const ids = [];
  visit(parser.parse(markdown), 'heading', node => {
    const match = plainText(node).match(/^(?:Задание\s+)?([1-9]\d*(?:\.\d+)*)(?:[.)]?(?:\s|$))/i);
    if (match && !ids.includes(match[1])) ids.push(match[1]);
  });
  return ids;
}

export function compileMarkdown(markdown, current, documents, assets, warn = console.warn, { title } = {}) {
  const tree = parser.parse(markdown);
  if (title && !(tree.children[0]?.type === 'heading' && tree.children[0].depth === 1 && plainText(tree.children[0]) === title)) {
    if (tree.children.some(node => node.type === 'heading' && node.depth === 1)) {
      visit(tree, 'heading', node => { node.depth = Math.min(6, node.depth + 1); });
    }
    tree.children.unshift({ type: 'heading', depth: 1, children: [{ type: 'text', value: title }] });
  }
  const headings = [];
  const slugger = new GithubSlugger();
  const ids = new Set();
  let block = 0;
  function resolve(target, isImage = false, silent = false) {
    if (/^(?:[a-z][\w+.-]*:|\/\/)/i.test(target)) return target;
    const [rawPath, anchor = ''] = target.split('#');
    const decode = value => { try { return decodeURIComponent(value); } catch { return value; } };
    const normalize = value => value.normalize('NFC');
    const requested = normalize(decode(rawPath).replaceAll('\\', '/'));
    if (!requested) return `#${slug(decode(anchor))}`;
    const relative = path.posix.normalize(path.posix.join(path.posix.dirname(current), requested));
    const candidates = isImage ? assets : documents;
    const wanted = requested.replace(/\.md$/i, '');
    const exact = candidates.find(item => [relative, `${relative}.md`, requested, `${requested}.md`].includes(normalize(item.path)));
    const byName = candidates.filter(item => normalize(path.posix.basename(item.path, '.md')) === wanted || normalize(item.title || '') === wanted || normalize(path.posix.basename(item.path)) === requested);
    const found = exact || (byName.length === 1 ? byName[0] : null);
    if (!found) { if (silent) return null; warn(`[content] ${current}: unresolved or ambiguous link "${target}"`); return target; }
    const suffix = anchor ? `#${slug(decode(anchor))}` : '';
    return isImage ? `__CONTENT_ASSET__/${encodePath(found.path)}` : `#${topicRoute(found.path)}${suffix}`;
  }
  visit(tree, node => {
    if (node.type === 'heading') headings.push({ depth: node.depth, text: plainText(node), id: slugger.slug(plainText(node)) });
    if (node.type === 'code' && node.lang?.toLowerCase() === 'c') {
      const explicit = node.meta?.match(/(?:^|\s)(?:id=|#)([\w-]+)/)?.[1];
      const id = explicit || `block-${block}`;
      if (ids.has(id)) throw new Error(`${current}: duplicate C block id ${id}`);
      ids.add(id); block++;
      node.meta = `id=${id}`;
    }
    if (node.type === 'link') {
      const isNote = /\.md(?:#|$)/i.test(node.url);
      if (isNote) node.url = resolve(node.url);
      else if (!/^(?:#|[a-z][\w+.-]*:|\/\/)/i.test(node.url)) node.url = resolve(node.url, true);
      else if (node.url.startsWith('#')) node.url = resolve(node.url);
    }
    if (node.type === 'image') node.url = resolve(node.url, true);
    if (node.type === 'definition') node.url = resolve(node.url, !/\.md(?:#|$)/i.test(node.url));
  });
  // Transform text AST nodes only: code fences, inline code, and URLs remain literal.
  visit(tree, 'text', (node, index, parent) => {
    if (!parent || parent.type === 'link' || !node.value.includes('[[')) return;
    const parts = [];
    const pattern = /(!?)\[\[([^\]]+)\]\]/g;
    let from = 0;
    for (const match of node.value.matchAll(pattern)) {
      parts.push({ type: 'text', value: node.value.slice(from, match.index) });
      const [target, caption] = match[2].split('|');
      let image = match[1] === '!';
      let url = resolve(target, image, image);
      if (image && url === null) {
        const noteUrl = resolve(target, false, true);
        if (noteUrl) { image = false; url = noteUrl; }
        else url = resolve(target, true);
      }
      parts.push(image ? { type: 'image', url, alt: caption || path.posix.basename(target) } : { type: 'link', url, children: [{ type: 'text', value: caption || target.split('#')[0] || target.split('#')[1] }] });
      from = match.index + match[0].length;
    }
    if (!parts.length) return;
    parts.push({ type: 'text', value: node.value.slice(from) });
    parent.children.splice(index, 1, ...parts);
    return index + parts.length;
  });
  return { markdown: printer.stringify(tree), headings, codeBlocks: block };
}
