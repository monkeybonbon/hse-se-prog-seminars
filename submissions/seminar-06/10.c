#include <stdio.h>

int is_sorted(const int a[], size_t n) {
    if (n <= 1) return 1;
    return a[n - 2] <= a[n - 1] && is_sorted(a, n - 1);
}

int main(void) {
    int a[] = {1, 2, 2, 5};
    printf("%d\n", is_sorted(a, sizeof(a) / sizeof(a[0])));
    return 0;
}
