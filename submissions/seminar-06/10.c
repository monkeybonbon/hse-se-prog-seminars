#include <stddef.h>

int is_sorted(const int a[], size_t n) {
    if (n <= 1)
        return 1;

    if (a[0] > a[1])
        return 0;

    return is_sorted(a + 1, n - 1);
}