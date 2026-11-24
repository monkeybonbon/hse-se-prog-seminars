#include <stdio.h>

void order_pair(int *x, int *y) {
    if (*x > *y) {
        const int temp = *x;
        *x = *y;
        *y = temp;
    }
}

void normalize(int *a, int *b, int *c) {
    order_pair(a, b);
    order_pair(b, c);
    order_pair(a, b);
}

int main(void) {
    int x = 9, y = 2, z = 5;
    normalize(&x, &y, &z);
    printf("%d %d %d\n", x, y, z);
    return 0;
}