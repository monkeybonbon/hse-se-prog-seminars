#include "stdio.h"

int main()
{
    int a[10];

    size_t count = sizeof(a) / sizeof(int); // Ваше выражение

    printf("%zu\n", count);
}
