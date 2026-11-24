#include <stdio.h>

void rotate_right(int a[], size_t n, unsigned x) {
    if (n == 0) {
        return;
    }

    size_t shift = x % n;

    for (size_t step = 0; step < shift; ++step) {
        int last = a[n - 1];

        for (size_t i = n - 1; i > 0; --i) {
            a[i] = a[i - 1];
        }

        a[0] = last;
    }
}

int main(void) {
    int a[] = {1, 2, 3, 4, 5};
    const size_t n = sizeof(a) / sizeof(a[0]);

    rotate_right(a, n, 1);

    for (size_t i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}