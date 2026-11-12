# Работа с памятью

`malloc` выделяет блок памяти, а `free` освобождает его. Всегда проверяйте, удалось ли выделение.

## Динамический массив

```c id=allocation
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    size_t count = 5;
    int *values = malloc(count * sizeof(*values));
    if (values == NULL) {
        fprintf(stderr, "Недостаточно памяти\n");
        return 1;
    }
    for (size_t i = 0; i < count; i++) {
        values[i] = (int)(i * i);
        printf("%d ", values[i]);
    }
    printf("\n");
    free(values);
    return 0;
}
```

## Время жизни

После `free` обращаться к памяти через старый указатель нельзя. Не возвращайте адрес локальной переменной из функции.

> [!IMPORTANT]
> В этой среде доступно до 64 МиБ линейной памяти программы. Потоки, процессы, сеть и файловая система компьютера недоступны.
