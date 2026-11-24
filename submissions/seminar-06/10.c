#include <stdio.h>

int is_sorted(const int a[], size_t n) {
    if (n < 2) {
        return 1;
    }

    return a[0] <= a[1] && is_sorted(a + 1, n - 1);
}

int read_array(int a[], size_t n) {
    if (n == 0) {
        return 1;
    }

    if (scanf("%d", a) != 1) {
        return 0;
    }

    return read_array(a + 1, n - 1);
}

int main(void) {
    size_t n;

    if (scanf("%zu", &n) != 1) {
        return 1;
    }

    int a[n == 0 ? 1 : n];

    if (!read_array(a, n)) {
        return 1;
    }

    printf("%d\n", is_sorted(a, n));

    return 0;
}