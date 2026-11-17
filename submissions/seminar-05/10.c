#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[j][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n/2; j++) {
            int q = a[i][j];
            a[i][j] = a[i][n - j - 1];
            a[i][n - j - 1] = q;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}