Получите у преподавателя право записи в репозиторий. Без него создать свою ветку в этом репозитории не получится — обратитесь к преподавателю.

Работайте из корня репозитория: решения лежат в `submissions/`. Папку `site/` для сдачи менять не нужно.

- Клонируйте репозиторий и создайте свою ветку.
- Сохраните решения в `submissions/{seminar}/`: `1.c`, `2.c` и так далее, по номеру задания.
- Сделайте commit и отправьте ветку.

1. `git clone https://github.com/monkeybonbon/hse-se-prog-seminars.git`
2. `cd hse-se-prog-seminars`
3. `git switch -c BPI265_Ivanov`
4. `mkdir -p submissions/seminar-05` (например, `seminar-05`)
5. Поместите сюда файлы решений
6. `git add submissions/seminar-05/`
7. `git commit -m "Submit seminar-05 tasks"`
8. `git push -u origin BPI265_Ivanov`

> Даже текстовые задачи сдавать в файле `.c`

> Сдавайте ТОЛЬКО в своей ветке (не лезьте к другим коллегам в ветки)


