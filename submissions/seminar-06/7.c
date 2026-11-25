#include <stddef.h>
#include <limits.h>

int second_max(const int a[], size_t n) {
    int max = a[0];
    int second = INT_MIN;

    for (size_t i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }

    for (size_t i = 0; i < n; i++) {
        if (a[i] < max && a[i] > second)
            second = a[i];
    }

    return second;
}