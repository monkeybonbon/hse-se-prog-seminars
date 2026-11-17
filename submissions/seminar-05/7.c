#include <stdio.h>

int main(void) {
    int a[100][100];

    int n, m;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int sum = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }

}