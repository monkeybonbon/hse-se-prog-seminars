#include <stdio.h>
int max(const int a[], size_t n) {
    int mx = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > mx) {
            mx = a[i];
        }
    }
    return mx;
}
int second_max(const int a[], size_t n) {
    int mx = max(a, n);
    int mx2 = a[0];
    for (int i = 0; i < n; i++) {
        if (mx2 <= a[i] && a[i] < mx) {
            mx2 = a[i]; 
        }
    }
    return mx2;
}
int main(void) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int result = second_max(a, n);
    printf("%d", result);
    return 0;
}