#include <stdio.h>
#include <limits.h>

int second_max(const int a[], size_t n) {
    int max = a[0];
    int scnd = INT_MIN;
    for (size_t i = 1; i < n; ++i) {
        if (a[i] > max) max = a[i];
    }
    for (size_t i = 0; i < n; ++i) {
        if (a[i] < max && a[i] > scnd) scnd = a[i];
    }
    return scnd;
}

int main(void) {
    int a[] = {5, 5, 3, 1};
    printf("%d\n", second_max(a, sizeof(a) / sizeof(a[0])));
    return 0;
}
