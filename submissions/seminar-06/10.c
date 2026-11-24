#include "stdio.h"

int is_sorted(const int a[], size_t n) {
    if (n == 1) {
        return 1;
    }

    return is_sorted(a, n - 1) && a[n - 1] >= a[n - 2];
}

int main(void) {
    int a[] = {1, 1, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);
    printf("%d\n", is_sorted(a, n));
}
