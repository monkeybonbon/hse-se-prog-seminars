import config from '../../site.config.json';
export function GitInstructions({ seminar = 'seminar-01' }: { seminar?: string }) {
  return <section className="git-instructions"><span className="eyebrow">СДАЧА ЧЕРЕЗ GIT</span><h2 id="how-to-submit">Как сдать задания</h2>
    <p>Получите у преподавателя право записи в репозиторий. Без него создать свою ветку в этом репозитории не получится — обратитесь к преподавателю.</p>
    <p>Работайте из корня репозитория: решения лежат в <code>submissions/</code>. Папку <code>site/</code> для сдачи менять не нужно.</p>
    <ol><li>Клонируйте репозиторий и создайте свою ветку.</li><li>Сохраните решения в <code>submissions/{seminar}/</code>: <code>1.c</code>, <code>2.c</code> и так далее, по номеру задания.</li><li>Сделайте commit и отправьте ветку.</li></ol>
    <pre>{`git clone https://github.com/${config.repository}.git\ncd ${config.repository.split('/')[1]}\ngit switch -c BPI2412_Ivanov\nmkdir -p submissions/${seminar}\n\n# Поместите сюда файлы решений\ngit add submissions/${seminar}/\ngit commit -m "Submit ${seminar} tasks"\ngit push -u origin BPI2412_Ivanov`}</pre>
    <p>В Windows команды можно выполнить в Git Bash. Название ветки: <code>BPI&lt;номер группы&gt;_&lt;Фамилия латиницей&gt;</code>, например <code>BPI2413_Sidorov</code>. Регулярное выражение: <code>{config.branchPattern}</code>.</p>
    <p>Сдавайте в своей ветке. Pull Request и merge не требуются. Таблица обновляется примерно каждые 15 минут; GitHub Actions может задержать обновление. Статус «Загружено» означает наличие файла, а не принятую работу.</p>
  </section>;
}
