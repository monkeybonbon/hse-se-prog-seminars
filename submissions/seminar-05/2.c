#include <stdio.h>

int main(void) {
    char c[9];
    int a[] = {1, 2, 3, 4, 5};
    int *p = &a[1];
    char *q = c;

    printf("%zu\n", sizeof(c));
    printf("%zu\n", sizeof(a));
    printf("%zu\n", sizeof(p));
    printf("%zu\n", sizeof(q));
    printf("%zu\n", sizeof(*p));
    printf("%zu\n", sizeof(*q));

    return 0;
}
