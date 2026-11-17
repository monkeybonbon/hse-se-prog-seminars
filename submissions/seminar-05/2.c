#include <stdio.h>


#include <stdio.h>

int main(void) {
    char c[9];
    int a[] = {1, 2, 3, 4, 5};
    int *p = &a[1], i = 3;
    char *q = c;

    printf("a) sizeof(c)  = %zu\n", sizeof(c));
    printf("b) sizeof(a)  = %zu\n", sizeof(a));
    printf("c) sizeof(p)  = %zu\n", sizeof(p));
    printf("d) sizeof(q)  = %zu\n", sizeof(q));
    printf("e) sizeof(*p) = %zu\n", sizeof(*p));
    printf("f) sizeof(*q) = %zu\n", sizeof(*q));

    return 0;
}
