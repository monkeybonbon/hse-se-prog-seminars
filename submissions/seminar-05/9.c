#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int total = n * m;
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - 1 - i; j++) {
            if (a[j / m][j % m] < a[(j + 1) / m][(j + 1) % m]) {
                int tmp = a[j / m][j % m];
                a[j / m][j % m] = a[(j + 1) / m][(j + 1) % m];
                a[(j + 1) / m][(j + 1) % m] = tmp;
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
