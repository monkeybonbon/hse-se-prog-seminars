# Конспекты из Obsidian

`site/notes` — Git-сабмодуль репозитория [hse-se-prog-seminars-obsidian](https://github.com/monkeybonbon/hse-se-prog-seminars-obsidian), ветка `main`. Конспекты и картинки редактируются и отправляются в этот отдельный репозиторий. Исходники сайта остаются в `hse-se-prog-seminars`.

## Как обновляется сайт

При каждой публикации сайт получает **свежий `main` конспектов** через `git submodule update --init --remote`, затем генерирует страницы и выполняет обычную публикацию GitHub Pages. Не требуется менять указатель сабмодуля в основном репозитории после каждого изменения конспекта. SHA фактически использованной версии виден в шаге `Fetch latest Obsidian notes`.

Обычный checkout локально и PR-проверка используют зафиксированный commit сабмодуля, чтобы результат был воспроизводимым. Для обновления локальных конспектов из папки `site/`:

```bash
npm run notes:sync
```

Настройки `.obsidian`, плагины, `.git` и workflow внутри сабмодуля не копируются в контент и не выполняются сборкой сайта. Адреса тем по-прежнему основаны на путях `АиАЯ/semN/…`, а изображения — на `0 media/…`.

Вставки картинок `![[имя.png]]` показываются как изображения. Вставки других заметок `![[Указатели и адреса]]` показываются как ссылки на эти заметки; полное встраивание их содержимого не выполняется.

## Однократная настройка публикации после push

Git-сабмодуль сам по себе не передаёт события push в другой репозиторий. Для немедленного запуска сборки подготовлен workflow, который из репозитория Obsidian вызывает `pages.yml` сайта на ветке `main`. Расписание сайта каждые 15 минут остаётся резервным механизмом, но GitHub может задерживать его.

1. Опубликуйте изменения основного репозитория (с `.gitmodules` и обновлённым `pages.yml`) в его `main`.
2. Из папки `site/` выполните `npm run notes:setup`. Это создаст **внутри репозитория конспектов** файл `notes/.github/workflows/publish-site.yml`. Если он уже создан при подготовке изменения, повторный запуск не нужен.
3. Создайте [fine-grained personal access token](https://github.com/settings/personal-access-tokens/new). Владелец — `monkeybonbon`; доступ только к репозиторию **`hse-se-prog-seminars`**; repository permissions: **Actions → Read and write**. `Contents: write` не требуется. Установите подходящий срок действия и обновляйте secret при ротации токена.
4. В репозитории **`hse-se-prog-seminars-obsidian`** откройте **Settings → Secrets and variables → Actions → New repository secret**. Название: **`SITE_PUBLISH_TOKEN`**, значение: созданный токен. В код и чат токен не вставляется.
5. Закоммитьте и отправьте подготовленный workflow в `main` репозитория Obsidian. Из корня сайта:

```bash
git -C site/notes add .github/workflows/publish-site.yml
git -C site/notes commit -m "Trigger website publication after notes updates"
git -C site/notes push origin HEAD:main
```

Первый push этого workflow тоже запускает уведомление. После настройки достаточно обычного push конспектов или картинок в `main` репозитория Obsidian: там запустится **Update seminar website**, затем в основном репозитории — **Publish notes and submissions**. Доступность сайта зависит от времени очереди и сборки Actions.

`SITE_PUBLISH_TOKEN` храните только в репозитории конспектов, где изменять workflow могут доверенные авторы. Не добавляйте этот токен в репозиторий со студенческими ветками. Стандартный `GITHUB_TOKEN` репозитория Obsidian не даёт доступ к Actions другого репозитория. Детали: [GitHub — triggering workflows](https://docs.github.com/en/actions/how-tos/write-workflows/choose-when-workflows-run/trigger-a-workflow), [workflow dispatch permissions](https://docs.github.com/en/rest/actions/workflows#create-a-workflow-dispatch-event).

Пока secret и workflow в Obsidian не опубликованы, свежие конспекты всё равно подхватываются при push в `main` сайта, ручном **Run workflow → main** и очередном запуске по расписанию. Автоматический запуск именно по push в Obsidian заработает после шагов выше.

## Первый запуск после клонирования

```bash
git clone --recurse-submodules https://github.com/monkeybonbon/hse-se-prog-seminars.git
cd hse-se-prog-seminars/site
npm ci
npm run toolchain
npm run dev
```

Для уже клонированного репозитория из его корня: `git submodule update --init --recursive`. Из `site/` команда `npm run notes:sync` одновременно инициализирует сабмодуль и получает свежие конспекты. Сама сборка не ходит в сеть и при неинициализированном сабмодуле выдаёт инструкцию, а не публикует пустой сайт.

Прежняя локальная копия конспектов сохранена в `.local/notes-before-submodule/` основного checkout. Она игнорируется Git и не участвует в публикации.
