#include <stddef.h>
#include <limits.h>

int second_max(const int a[], size_t n) {
    int max = INT_MIN;
    int second = INT_MIN;

    for (size_t i = 0; i < n; i++) {
        if (a[i] > max) {
            second = max;
            max = a[i];
        } else if (a[i] < max && a[i] > second) {
            second = a[i];
        }
    }

    return second;
}