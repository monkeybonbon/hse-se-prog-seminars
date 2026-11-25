#include <stdio.h>

int is_sorted(const int a[], size_t n) {
    if (n <= 1) {
        return 1;
    }
    if (a[0] > a[1]) {
        return 0;
    }
    return is_sorted(a + 1, n - 1);
}

int main(void) {
    size_t n;
    scanf("%zu", &n);
    int m[n];
    for (size_t i = 0; i < n; i++) {
        scanf("%d", &m[i]);
    }
    printf("%d\n", is_sorted(m, n));
    return 0;
}
