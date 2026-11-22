#include <stdio.h>

int main() {
    char c[9];
    int a[] = {1, 2, 3, 4, 5};
    int *p = &a[1], i = 3;
    char *q = c;

    printf("%d\n", sizeof(c));  // 9
    printf("%d\n", sizeof(a));  // 20
    printf("%d\n", sizeof(p));  // 8
    printf("%d\n", sizeof(q));  // 8
    printf("%d\n", sizeof(*p)); // 4
    printf("%d\n", sizeof(*q)); // 1

    return 0;
}
