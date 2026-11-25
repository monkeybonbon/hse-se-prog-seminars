#include <stdio.h>

int second_max(const int a[], size_t n) {
    int mx1 = a[0];
    int mx2 = a[0];
    int h_se = 0;

    for (size_t i = 1; i < n; i++) {
        if (a[i] > mx1) {
            mx2 = mx1;
            mx1 = a[i];
            h_se = 1;
        } else if (a[i] < mx1) {
            if (!h_se || a[i] > mx2) {
                mx2 = a[i];
                h_se = 1;
            }
        }
    }

    return mx2;
}


int main() {
    size_t n;
    scanf("%zu", &n);
    int m[n];
    for (size_t i = 0; i < n; i++) {
        scanf("%d", &m[i]);
    }
    printf("%d",second_max(m, n));
    return 0;
}
