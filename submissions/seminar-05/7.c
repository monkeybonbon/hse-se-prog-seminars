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
    int transp_a[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            transp_a[i][j] = a[j][i];
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }
    return 0;
}