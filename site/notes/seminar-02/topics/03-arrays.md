# Массивы

Массив хранит последовательность элементов одного типа. Индексы начинаются с нуля.

## Обход массива

```c id=array-sum
#include <stdio.h>

int main(void) {
    int values[] = {3, 1, 4, 1, 5};
    size_t count = sizeof(values) / sizeof(values[0]);
    int sum = 0;
    for (size_t i = 0; i < count; i++) {
        printf("values[%zu] = %d\n", i, values[i]);
        sum += values[i];
    }
    printf("Сумма: %d\n", sum);
    return 0;
}
```

## Границы

У массива из пяти элементов допустимые индексы — от `0` до `4`. Выход за границы приводит к неопределённому поведению; автоматической проверки в C нет.

## Строки

Строка C — массив символов с завершающим нулём `\0`.

```c id=strings
#include <stdio.h>
#include <string.h>

int main(void) {
    char word[32] = "hello";
    printf("%s: %zu bytes\n", word, strlen(word));
    return 0;
}
```
