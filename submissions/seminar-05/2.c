#include <stdio.h>

int main(void) {
    char c[9];
    int a[] = {1, 2, 3, 4, 5};
    int *p = &a[1], i = 3;
    char *q = c;
    printf("%d\n", sizeof(c));
    printf("%d\n", sizeof(a));
    printf("%d\n", sizeof(p));
    printf("%d\n", sizeof(q));
    printf("%d\n", sizeof(*p));
    printf("%d\n", sizeof(*q));

    return 0;
}