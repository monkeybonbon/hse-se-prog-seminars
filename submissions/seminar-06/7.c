#include <stddef.h>

int second_max(const int a[], size_t n) {
    int max1 = a[0];
    int max2 = a[0];
    int has_second = 0;

    for (size_t i = 1; i < n; ++i) {
        if (a[i] > max1) {
            max2 = max1;
            max1 = a[i];
            has_second = 1;
        } else if (a[i] < max1 && (!has_second || a[i] > max2)) {
            max2 = a[i];
            has_second = 1;
        }
    }

    return max2;
}