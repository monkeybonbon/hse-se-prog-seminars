#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void rotate_right(int a[], size_t n, unsigned x) {
    x %= n;
    if (x == 0) return;

    for (size_t i = 0, j = n - 1; i < j; ++i, --j)
        swap(&a[i], &a[j]);

    for (size_t i = 0, j = x - 1; i < j; ++i, --j)
        swap(&a[i], &a[j]);

    for (size_t i = x, j = n - 1; i < j; ++i, --j)
        swap(&a[i], &a[j]);
}

int main(void) {
    int a[] = {1, 2, 3, 4, 5};
    rotate_right(a, 5, 1);
    for (size_t i = 0; i < 5; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
