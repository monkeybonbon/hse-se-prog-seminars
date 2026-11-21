#include <stdio.h>

// 1. Все выражения отдельно, i = 3, p = &a[1], q = c.

// i++       3, int, i = 4
// ++i       4, int, i = 4
// a[i]--    4, int, a[3] = 3
// *p++      2, int, p = &a[2]
// ++*p      3, int, a[1] = 3
// *++p      3, int, p = &a[2]
// p - a     1, ptrdiff_t, ничего
// &c[8] - q 8, ptrdiff_t, ничего
// a - q     ошибка, разные типы указателей

int main(void) {
    return 0;
}
