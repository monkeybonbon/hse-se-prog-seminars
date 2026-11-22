#include <stdio.h>

int main(void){
    char c[9];
    int a[] = {1, 2, 3, 4, 5};
    int *p = &a[1];
    char *q = c;

    printf("sizeof(c)  = %zu\n", sizeof(c));
    printf("sizeof(a)  = %zu\n", sizeof(a));
    printf("sizeof(p)  = %zu\n", sizeof(p));
    printf("sizeof(q)  = %zu\n", sizeof(q));
    printf("sizeof(*p) = %zu\n", sizeof(*p));
    printf("sizeof(*q) = %zu\n", sizeof(*q));

    return 0;
}