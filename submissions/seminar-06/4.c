#include <stdio.h>
size_t longest_run(const int a[], size_t n) {
    int r = 0;
    int mx = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            r += 1;
            if (mx < r) {
                mx = r;
            }
        }
        else {
            r = 1;
        }
    }
    return mx;
}
int main(void) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int result = longest_run(a, n);
    printf("%d", result);
    return 0;
}