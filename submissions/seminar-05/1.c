
/*
3       int     i -> 4
4       int     i -> 4
4       int     a[i] = 3
2       int     p сдвиг на a[2]
3       int         a[1] = 3
3       int         p сдвиг на a[2]
1(1 int)    ptrdiff_t    -
8           ptrdiff_t    -
ошибка (тфм за пред массива выйдет)

*/