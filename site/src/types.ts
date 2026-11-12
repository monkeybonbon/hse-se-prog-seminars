export interface Heading { depth: number; text: string; id: string }
export interface Note { path: string; title: string; markdown: string; route: string; headings: Heading[]; codeBlocks: number }
export interface Seminar { id: string; number: number; title: string; taskCount: number; topics: Note[]; tasks: Note | null }
export interface Student { branch: string; group: string; surname: string; status: 'ok' | 'missing' | 'unavailable'; sha: string | null; lastCommitAt: string | null; submissions: Record<string, string[]> }
export interface SubmissionReport { status: string; updatedAt: string | null; attemptedAt?: string; students: Student[]; warnings?: string[] }
