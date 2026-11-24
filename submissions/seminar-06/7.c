
#include <stddef.h>

int second_max(const int a[], size_t n) {
    int max1, max2;

    if (a[0] > a[1]) {
        max1 = a[0];
        max2 = a[1];
    } else {
        max1 = a[1];
        max2 = a[0];
    }

    for (size_t i = 2; i < n; i++) {
        if (a[i] > max1) {
            max2 = max1;
            max1 = a[i];
        } else if (a[i] > max2 && a[i] < max1) {
            max2 = a[i];
        }
    }

    return max2;
}
