#include "stdio.h"

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n][m];
    int i[] = {};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i][j] = a[n - j - 1][i];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
}