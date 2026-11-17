#include <stdio.h>

int main() {
    int arr[3][4];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Суммы строк: ");
    for (int i = 0; i < 3; i++) {
        int row_sum = 0;
        for (int j = 0; j < 4; j++) {
            row_sum += arr[i][j];
        }
        printf("%d ", row_sum);
    }
    printf("\n");

    printf("Суммы столбцов: ");
    for (int j = 0; j < 4; j++) {
        int col_sum = 0;
        for (int i = 0; i < 3; i++) {
            col_sum += arr[i][j];
        }
        printf("%d ", col_sum);
    }
    return 0;
}
