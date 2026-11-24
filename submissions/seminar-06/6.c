#include <stdio.h>

void normalize(int *a, int *b, int *c) {
    if (*a > *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*b > *c) {
        int temp = *b;
        *b = *c;
        *c = temp;
    }
}

int main(void) {
    int x = 9, y = 2, z = 5;

    normalize(&x, &y, &z);
    printf("%d %d %d\n", x, y, z);

    return 0;
}