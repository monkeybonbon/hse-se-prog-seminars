#include <stdio.h>
int main() {
    int n,m;
    printf("Razmer massiva: ");
    scanf("%d %d", &n, &m);
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int b[m][n];
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            b[j][i] = a[i][j];
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