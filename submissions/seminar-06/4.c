#include <stdio.h>

size_t longest_run(const int a[], size_t n) {
    if (n == 0) {
        return 0;
    }

    size_t m = 1, k = 1;

    for (size_t i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            k++;
        } else {
            k = 1;
        }

        if (k > m) {
            m = k;
        }
    }

    return m;
}

int main(void) {
    size_t n;

    if (scanf("%zu", &n) != 1) {
        return 1;
    }

    int a[n == 0 ? 1 : n];

    for (size_t i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 1;
        }
    }

    printf("%zu\n", longest_run(a, n));

    return 0;
}