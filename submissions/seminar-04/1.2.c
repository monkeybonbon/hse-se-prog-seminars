#include <stdio.h>

int main(void) {
    int a = 2;
    int *p = &a;
    
    int *q = &(*p);
    (*q)++;

    printf("%p %p %d\n", (void *)p, (void *)q, a);
    // адрес a, адрес a, 3

    return 0;
}
