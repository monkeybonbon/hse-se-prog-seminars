#include <stdio.h>

static void swap(int *p, int *q) {
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

void normalize(int *a, int *b, int *c) {
    if (*a > *b)
        swap(a, b);
    if (*b > *c)
        swap(b, c);       
    if (*a > *b)
        swap(a, b);       
}

int main(void) {
    int x = 9, y = 2, z = 5;
    normalize(&x, &y, &z);
    printf("x = %d, y = %d, z = %d\n", x, y, z);
            
    return 0;
}