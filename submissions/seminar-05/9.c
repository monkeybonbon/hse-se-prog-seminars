#include <stdio.h>

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n][m];
    int b[m*n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            b[i*n+ = a[i][j];
        }
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            printf("%d ", b[j][i]);
        }
        printf("\n");
    }

    return 0;
}