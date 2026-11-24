#include <stdio.h>
int is_sorted(const int a[], size_t n) {
    if (n <= 1) {
        return 1;
    } else {
        if (a[n - 1] >= a[n - 2]) {
            return is_sorted(a, n - 1);
        } else {
            return 0;
        }
    }
}
int main(void) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int result = is_sorted(a, n);
    printf("%d", result);
    return 0;
}