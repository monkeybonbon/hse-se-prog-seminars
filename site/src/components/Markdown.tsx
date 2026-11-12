import { lazy, Suspense, useState, type ReactNode } from 'react';
import ReactMarkdown from 'react-markdown';
import remarkGfm from 'remark-gfm';
import remarkMath from 'remark-math';
import rehypeKatex from 'rehype-katex';
import rehypeHighlight from 'rehype-highlight';
import { visit } from 'unist-util-visit';
import GithubSlugger from 'github-slugger';
import type { Note } from '../types';

const CodeEditor = lazy(() => import('./CodeEditor').then(module => ({ default: module.CodeEditor })));

function remarkEnhance() {
  return (tree: any) => {
    const slugger = new GithubSlugger();
    const text = (node: any): string => node.value ?? node.children?.map(text).join('') ?? '';
    visit(tree, (node: any) => {
      if (node.type === 'heading') node.data = { hProperties: { id: slugger.slug(text(node)) } };
      if (node.type === 'code' && node.lang?.toLowerCase() === 'c') node.data = { hProperties: { 'data-source': node.value, 'data-block-id': node.meta?.match(/id=([\w-]+)/)?.[1] } };
      if (node.type === 'blockquote') {
        const first = node.children?.[0]?.children?.[0];
        const marker = first?.type === 'text' && first.value.match(/^\[!(\w+)\][+-]?\s*/);
        if (marker) {
          const labels: Record<string, string> = { NOTE: 'На заметку', TIP: 'Совет', WARNING: 'Обратите внимание', IMPORTANT: 'Важно' };
          first.value = first.value.slice(marker[0].length);
          node.children[0].children.unshift({ type: 'strong', children: [{ type: 'text', value: (labels[marker[1]] || marker[1]) + '\n' }] });
          node.data = { hProperties: { className: 'callout' } };
        }
      }
    });
  };
}
function flatten(children: ReactNode): string {
  if (typeof children === 'string') return children;
  if (Array.isArray(children)) return children.map(flatten).join('');
  if (children && typeof children === 'object' && 'props' in children) return flatten((children.props as { children: ReactNode }).children);
  return '';
}
function StaticCode({ children, className }: { children: ReactNode; className?: string }) {
  const [copied, setCopied] = useState(false);
  const [failed, setFailed] = useState(false);
  return <div className="static-code"><button onClick={async () => { try { await navigator.clipboard.writeText(flatten(children)); setCopied(true); setTimeout(() => setCopied(false), 1800); } catch { setFailed(true); } }}>{failed ? 'Выделите текст для копирования' : copied ? 'Скопировано' : 'Копировать'}</button><pre><code className={className}>{children}</code></pre></div>;
}
export function Markdown({ note }: { note: Note }) {
  return <div className="markdown"><ReactMarkdown
    remarkPlugins={[remarkGfm, remarkMath, remarkEnhance]}
    rehypePlugins={[rehypeKatex, [rehypeHighlight, { ignoreMissing: true }]]}
    components={{
      pre: ({ children }) => <>{children}</>,
      code: ({ node, children, className, ...props }) => {
        const properties = node?.properties;
        if (properties && properties['data-source'] !== undefined) return <Suspense fallback={<p className="muted">Загрузка редактора…</p>}><CodeEditor key={`${note.path}:${properties['data-block-id']}`} notePath={note.path} blockId={String(properties['data-block-id'])} source={String(properties['data-source'])} /></Suspense>;
        if (className?.includes('language-') || flatten(children).includes('\n')) return <StaticCode className={className}>{children}</StaticCode>;
        return <code {...props} className={className}>{children}</code>;
      },
      a: ({ children, href, ...props }) => <a href={href} {...props} {...(href?.startsWith('http') ? { target: '_blank', rel: 'noreferrer noopener' } : {})}>{children}</a>,
      img: ({ alt, ...props }) => <img alt={alt || ''} loading="lazy" {...props} />,
      table: ({ children }) => <div className="table-scroll"><table>{children}</table></div>,
    }}
  >{note.markdown.replaceAll('__CONTENT_ASSET__/', `${import.meta.env.BASE_URL}content/`)}</ReactMarkdown></div>;
}
