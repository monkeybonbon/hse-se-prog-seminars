#include <stdio.h>
#include <limits.h>

int second_max(const int a[], size_t n) {
    int last = INT_MIN;
    int last_2 = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (a[i] > last) {
            last = a[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] > last_2 & a[i] != last) {
            last_2 = a[i];
        }
    }
    return last_2;
}