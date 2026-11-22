#include <stdio.h>

int main() {
    int a = 2;
    int *p = &a;
    int *q = &(*p);
    (*q)++;

    printf("%p %p %d", p, q, a);
    // адрес a, адрес a, 3

    return 0;
}
