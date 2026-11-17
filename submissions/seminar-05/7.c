#include <stdio.h>

int main(void) {
    int n, m;

    if (scanf("%d%d", &n, &m) != 2 || n <= 0 || m <= 0) {
        return 1;
    }

    int a[n][m];
    int b[m][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &a[i][j]) != 1) {
                return 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[j][i] = a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", b[i][j]);
        }

        printf("\n");
    }

    return 0;
}