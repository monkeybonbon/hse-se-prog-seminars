#include <stddef.h>

static void reverse_range(int a[], size_t left, size_t right) {
    while (left < right) {
        int tmp = a[left];
        a[left] = a[right];
        a[right] = tmp;
        ++left;
        --right;
    }
}

void rotate_right(int a[], size_t n, unsigned x) {
    if (n == 0) {
        return;
    }

    size_t shift = (size_t)x % n;
    if (shift == 0) {
        return;
    }

    reverse_range(a, 0, n - 1);
    reverse_range(a, 0, shift - 1);
    reverse_range(a, shift, n - 1);
}