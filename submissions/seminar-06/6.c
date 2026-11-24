#include <stdio.h>
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
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