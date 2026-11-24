#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
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
    int x, y, z;

    if (scanf("%d%d%d", &x, &y, &z) != 3) {
        return 1;
    }

    normalize(&x, &y, &z);

    printf("%d %d %d\n", x, y, z);

    return 0;
}