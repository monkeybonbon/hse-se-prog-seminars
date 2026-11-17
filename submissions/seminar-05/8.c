#include <stdio.h>

int main(void) {
    char a[8][8];
    char b[8][8];
    int li, lj;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%d", &a[i][j]);
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