#include <stdio.h>

int main(void){
    int n, a[100], x, k;
    if (scanf("%d", &n) != 1 || n < 0 || n >= 100) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 1;
        }
    }
    if (scanf("%d %d", &x, &k) != 2 || k < 0 || k > n) {
        return 1;
    }
    for (int i = n; i > k; i--) {
        a[i] = a[i - 1];
    }
    a[k] = x;
    n++;
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}