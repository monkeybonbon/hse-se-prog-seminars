#include "stdio.h"

int min_val(const int a[], size_t n) {
    int ans = a[0];
    for (int i = 0; i < n; ++i) {
        ans = ans < a[i] ? ans : a[i];
    }
    return ans;
}

int second_max(const int a[], size_t n) {
    int mx = a[0], secmx = min_val(a, n);

    for (int i = 0; i < n; i++) {
        if (a[i] > mx) {
            secmx = mx;
            mx = a[i];
        } else if (mx > a[i] && a[i] > secmx) {
            secmx = a[i];
        }
    }
    return secmx;
}

int main(void) {
    int a[] = {-1, -7, -3};
    size_t n = sizeof(a) / sizeof(a[0]);

    printf("%d\n", second_max(a, n));
    return 0;
}
