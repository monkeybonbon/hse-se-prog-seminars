#include <stdio.h>

void normalize(int *a, int *b, int *c) {
    int temp;

    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }

    if (*b > *c) {
        temp = *b;
        *b = *c;
        *c = temp;
    }

    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main(void) {
    int x = 9, y = 2, z = 5;

    normalize(&x, &y, &z);

    printf("%d %d %d\n", x, y, z);

    return 0;
}
