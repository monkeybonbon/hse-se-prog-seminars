#include <stdio.h>

void normalize_two(int *a, int *b) {
    if (*a > *b) {
        int t = *a;
        *a = *b;
        *b = t;
    }
}

void normalize(int *a, int *b, int *c) {
    normalize_two(a, b);
    normalize_two(b, c);
    normalize_two(a, b);
}

int main(void) {
    int x = 9;
    int y = 2;
    int z = 5;

    normalize(&x, &y, &z);

    printf("%d %d %d\n", x, y, z); /* x = 2, y = 5, z = 9 */
}
