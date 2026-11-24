#include <stdio.h>

void reverse(int a[], size_t n) {
    for (size_t i = 0; i < n / 2; i++) {
        int t = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = t;
    }
}

void rotate_right(int a[], size_t n, unsigned x) {
    if (n == 0) {
        return;
    }

    size_t k = x % n;

    if (k == 0) {
        return;
    }

    reverse(a, n);
    reverse(a, k);
    reverse(a + k, n - k);
}

int main(void) {
    size_t n;
    unsigned x;

    if (scanf("%zu", &n) != 1) {
        return 1;
    }

    int a[n == 0 ? 1 : n];

    for (size_t i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 1;
        }
    }

    if (scanf("%u", &x) != 1) {
        return 1;
    }

    rotate_right(a, n, x);

    for (size_t i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");

    return 0;
}