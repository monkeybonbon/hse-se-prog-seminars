# Типы данных

Переменная — именованное место для значения. Тип определяет, какие значения и операции доступны.

## Объявление переменных

```c id=variables
#include <stdio.h>

int main(void) {
    int students = 24;
    double temperature = 21.5;
    char grade = 'A';
    printf("Студентов: %d\nТемпература: %.1f\nОценка: %c\n",
           students, temperature, grade);
    return 0;
}
```

| Тип | Пример | Формат printf |
| --- | --- | --- |
| `int` | `42` | `%d` |
| `double` | `3.14` | `%f` |
| `char` | `'A'` | `%c` |
| `size_t` | `sizeof(int)` | `%zu` |

## Арифметика

Целочисленное деление отбрасывает дробную часть. Чтобы получить вещественный результат, хотя бы один операнд должен быть вещественным.

```c id=division
#include <stdio.h>
#include <math.h>

int main(void) {
    int a = 7, b = 2;
    printf("7 / 2 = %d\n", a / b);
    printf("7.0 / 2 = %.1f\n", (double)a / b);
    printf("sqrt(49) = %.1f\n", sqrt((double)(a * a)));
    return 0;
}
```

Среднее арифметическое: $\bar{x} = \frac{1}{n}\sum_{i=1}^{n}x_i$.

> [!WARNING]
> Размер типа зависит от платформы. В wasm32 указатели имеют размер 4 байта. Не переносите это предположение в любой C-проект.

Следующая тема: [[03-input-output|Ввод и вывод]].
