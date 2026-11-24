#include <stdio.h>

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
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
    printf("%d %d %d\n", x, y, z);
}


/* x = 2, y = 5, z = 9 */