#include <stdio.h>

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    int a[n][m];
    int b[m][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            b[i][j] = a[j][i];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("%d", b[i][j]);
        }
        printf("\n");
    }

    return 0;
}