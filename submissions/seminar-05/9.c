#include <stdio.h>

int main(void) {
    int n, m;

    if (scanf("%d%d", &n, &m) != 2 || n <= 0 || m <= 0) {
        return 1;
    }

    int a[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &a[i][j]) != 1) {
                return 1;
            }
        }
    }

    for (int i = 0; i < n * m - 1; i++) {
        for (int j = i + 1; j < n * m; j++) {
            if (a[i / m][i % m] < a[j / m][j % m]) {
                int t = a[i / m][i % m];
                a[i / m][i % m] = a[j / m][j % m];
                a[j / m][j % m] = t;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }

        printf("\n");
    }

    return 0;
}