# Указатели и адреса

Указатель хранит адрес объекта. Оператор `&` получает адрес, а `*` позволяет обратиться к значению по адресу.

## Изменение через указатель

```c id=pointer
#include <stdio.h>

int main(void) {
    int value = 42;
    int *pointer = &value;
    printf("До: %d\n", value);
    *pointer = 100;
    printf("После: %d\n", value);
    printf("Адрес: %p\n", (void *)pointer);
    return 0;
}
```

## Передача в функцию

В C аргументы передаются по значению. Чтобы изменить переменную вызывающей функции, передайте её адрес.

```c id=swap
#include <stdio.h>

void swap(int *a, int *b) {
    int temporary = *a;
    *a = *b;
    *b = temporary;
}

int main(void) {
    int a = 3, b = 7;
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);
    return 0;
}
```

Теперь можно перейти к [[02-memory|динамической памяти]].
