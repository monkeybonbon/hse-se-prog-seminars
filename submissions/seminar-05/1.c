/*
1) i++       : 3, int, i = 4
2) ++i       : 4, int, i = 4
3) a[i]--    : 4, int, a[3] = 3
4) *p++      : 2, int, p = &a[2]
5) ++*p      : 3, int, a[1] = 3
6) *++p      : 3, int, p = &a[2]
7) p - a     : 1, ptrdiff_t, нет
8) &c[8] - q : 8, ptrdiff_t, нет
9) a - q     : ошибка, несовместимые типы указателей
*/

int main(void) {
    return 0;
}