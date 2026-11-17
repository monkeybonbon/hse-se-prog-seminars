#include <stdio.h>

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int *p = &a[0][0];
    for (int i = 0; i < (n * m - 1); i++) {
        for (int j = 0; j < (n * m - i - 1); j++) {
            if (p[j] < p[j + 1]) {
                int t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
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