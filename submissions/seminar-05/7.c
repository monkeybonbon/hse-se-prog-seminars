#include <stdio.h>

int main(void) {
    int n;
    int m;
    scanf("%d%d", &n, &m);

    int arr[n][m];
    int arr_tr[m][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr_tr[j][i] = arr[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr_tr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
