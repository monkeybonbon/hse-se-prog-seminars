#include <stddef.h>

static void reverse(int a[], size_t n) {
    for (size_t i = 0; i < n / 2; i++) {
        int temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }
}

void rotate_right(int a[], size_t n, unsigned x) {
    if (n == 0)
        return;

    size_t k = x % n;

    if (k == 0)
        return;

    reverse(a, n);
    reverse(a, k);
    reverse(a + k, n - k);
}