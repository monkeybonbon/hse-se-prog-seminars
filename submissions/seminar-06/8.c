#include "stdio.h"

void swap_arr(int a[], unsigned i, unsigned j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void rotate_right_once(int a[], size_t n) {
    for (int i = n - 1; i >= 1; --i) {
        swap_arr(a, i, i - 1);
    }
}

void rotate_right(int a[], size_t n, unsigned x) {
    for (int i = 0; i < x; ++i) {
        rotate_right_once(a, n);
    }
}


int main(void) {
    int a[] = {1, 2, 3, 4, 5};
    size_t n = sizeof(a) / sizeof(a[0]);

    rotate_right(a, n, 1);

    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
