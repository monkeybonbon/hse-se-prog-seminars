#include <stdio.h>

int main(void)
{
    char c[9];
    int a[] = {1, 2, 3, 4, 5};
    int *p = &a[1], i = 3;
    char *q = c;
    printf("%td\n");

    //выражение   значение   тип         меняется
    //i++         3          int         i = 4
    //++i         4          int         i = 4
    //a[i]--      4          int         a[3] = 3
    //*p++        2          int         p = &a[2]
    //++*p        3          int         a[1] = 3
    //*++p        3          int         p = &a[2]
    //p - a       1          ptrdiff_t   ничего
    //&c[8] - q   8          ptrdiff_t   ничего
    //a - q       ошибка т к разные типы указателей и разные массивы

    return 0;
}
