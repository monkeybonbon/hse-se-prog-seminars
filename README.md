# Семинары по программированию на C

Конспекты, примеры и задания находятся на [сайте курса](https://monkeybonbon.github.io/hse-se-prog-seminars/).

## Где что лежит

- **`submissions/`** — сюда добавляйте свои решения в собственной ветке.
- `site/` — конспекты и код сайта; инструкция для преподавателя находится в [site/README.md](site/README.md).
- `.github/` и `.gitignore` — служебные файлы автоматической публикации.

## Как сдать задания

Получите у преподавателя право записи в репозиторий. Замените номер группы и фамилию в имени ветки на свои: например, `BPI2412_Ivanov`.

Выполняйте команды из корня репозитория (в Windows можно использовать Git Bash):

```bash
git clone https://github.com/monkeybonbon/hse-se-prog-seminars.git
cd hse-se-prog-seminars
git switch -c BPI2412_Ivanov
mkdir -p submissions/seminar-01
```

Сохраните решения как `submissions/seminar-01/1.c`, `2.c`, `3.c` — по номеру задания. Затем:

```bash
git add submissions/seminar-01/
git commit -m "Submit seminar 01 tasks"
git push -u origin BPI2412_Ivanov
```

Для следующих семинаров используйте ту же ветку и папки `submissions/seminar-02/`, `submissions/seminar-03/` и т. д.

Меняйте только свои решения в `submissions/`. Pull Request и merge не нужны. Таблица на сайте обновляется примерно каждые 15 минут; «Загружено» означает наличие файла, а не принятую работу.
