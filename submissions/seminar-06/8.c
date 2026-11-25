#include <stdio.h>

void rotate_right(int a[], size_t n, unsigned x) {
    if (!a || n <= 1) {
        return;
    }
    x %= n;
    if (x == 0) {
        return;
    }
    for (size_t l = 0, r = n - 1; l < r; l++, r--) {
        int tmp = a[l];
        a[l] = a[r];
        a[r] = tmp;
    }
    for (size_t l = 0, r = x - 1; l < r; l++, r--) {
        int tmp = a[l];
        a[l] = a[r];
        a[r] = tmp;
    }
    for (size_t l = x, r = n - 1; l < r; l++, r--) {
        int tmp = a[l];
        a[l] = a[r];
        a[r] = tmp;
    }
}

int main(void) {
    size_t n;
    unsigned x;
    if (scanf("%zu", &n) != 1) {
        return 1;
    }
    if (n == 0) {
        scanf("%u", &x);
        return 0;
    }
    int m[n];
    for (size_t i = 0; i < n; i++) {
        scanf("%d", &m[i]);
    }
    if (scanf("%u", &x) != 1) {
        return 1;
    }
    rotate_right(m, n, x);
    for (size_t i = 0; i < n; i++) {
        printf("%d ", m[i]);
    }
    printf("\n");
    return 0;
}
