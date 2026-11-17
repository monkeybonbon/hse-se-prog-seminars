#include <stdio.h>

int main(void) {
    int n, x, k;
    int a[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d %d", &x, &k);
    for (int i = n; i > k; i--) {
        a[i] = a[i - 1];
    }
    a[k] = x;
    for (int i = 0; i < n + 1; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
