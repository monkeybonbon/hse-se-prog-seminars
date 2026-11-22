#include <stdio.h>

int main() {
    int n = 3, m = 4;
    int arr[n][m];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }

    int s = 0;
    printf("Суммы строк: ");
    for (int i = 0; i < n; ++i) {
        s = 0;
        for (int j = 0; j < m; ++j) {
            s += arr[i][j];
        }
        printf("%d ", s);
    }

    printf("\nСуммы столбцов: ");
    for (int j = 0; j < m; ++j) {
        s = 0;
        for (int i = 0; i < n; ++i) {
            s += arr[i][j];
        }
        printf("%d ", s);
    }
    printf("\n");

    return 0;
}
