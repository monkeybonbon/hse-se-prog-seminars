#include <stdio.h>

void normalize(int *a, int *b, int *c) {
    int vrem;

    if (*a > *b) {
        vrem = *a;
        *a = *b;
        *b = vrem;
    }

    if (*b > *c) {
        vrem = *b;
        *b = *c;
        *c = vrem;
    }

    if (*a > *b) {
        vrem = *a;
        *a = *b;
        *b = vrem;
    }
}

int main() {
    int x = 3, y = 9, z =15;

    normalize(&x, &y, &z);

    printf("%d %d %d\n", x, y, z);

    return 0;
}
