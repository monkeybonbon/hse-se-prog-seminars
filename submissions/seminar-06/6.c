#include <stdio.h>

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void normalize(int *a, int *b, int *c) {
    if (*a > *b) {
        swap(a, b);
    }
    if (*b > *c) {
        swap(b, c);
    }
    if (*a > *b) {
        swap(a, b);
    }
}

int main(void) {
    int x = 9, y = 2, z = 5;
    normalize(&x, &y, &z);
    printf("%d %d %d", x, y, z);
    return 0;
}