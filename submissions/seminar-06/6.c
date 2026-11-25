#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void normalize(int *a, int *b, int *c) {
    if (*a > *b) swap(a, b);
    if (*a > *c) swap(a, c);
    if (*b > *c) swap(b, c);
}

int main(void) {
    int x = 9, y = 2, z = 5;
    normalize(&x, &y, &z);
    printf("%d %d %d\n", x, y, z);
    return 0;
}
