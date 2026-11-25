#include <stdio.h>

int is_sorted(const int a[], size_t n) {
    if (n <= 1) {
        return 1;
    }

    if (a[n - 2] > a[n - 1] || !is_sorted(a, n - 1)) {
        return 0;
    }
    return 1;
}

int main(void) {
    int a[4] = {1, 3, 2, 5};
    printf("%d\n", is_sorted(a, 4));
}
