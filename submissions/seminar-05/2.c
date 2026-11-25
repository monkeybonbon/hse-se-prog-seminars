#include <stdio.h>

int main(void) {
    char c[9];
    int a[] = {1, 2, 3, 4, 5};
    int *p = &a[1];
    char *q = c;
    // int i = 3;

    printf("%zu\n", sizeof(c));  // 9
    printf("%zu\n", sizeof(a));  // 20
    printf("%zu\n", sizeof(p));  // 8
    printf("%zu\n", sizeof(q));  // 8
    printf("%zu\n", sizeof(*p)); // 4
    printf("%zu\n", sizeof(*q)); // 1

    return 0;
}
