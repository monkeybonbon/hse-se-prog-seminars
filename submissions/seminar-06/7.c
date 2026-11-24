#include <stdio.h>

int second_max(const int a[], size_t n) {
    int max = a[0];
    for (size_t i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    int second = max;

    for (size_t i=0; i<n; i++) {
        if (a[i] != max && (second == max || a[i] > second)) {
            second = a[i];
        }
    }
    return second
}