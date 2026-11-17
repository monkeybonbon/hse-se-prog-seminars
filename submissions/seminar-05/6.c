#include <stdio.h>

int main(void) {
    int matrix[3][4];
    
    int sum_row1 = 0;
    int sum_row2 = 0;
    int sum_row3 = 0;

    int sum_col1 = 0;
    int sum_col2 = 0;
    int sum_col3 = 0;
    int sum_col4 = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int j = 0; j < 4; j++) {
        sum_row1 += matrix[0][j];
        sum_row2 += matrix[1][j];
        sum_row3 += matrix[2][j];
    }

    for (int i = 0; i < 3; i++) {
        sum_col1 += matrix[i][0];
        sum_col2 += matrix[i][1];
        sum_col3 += matrix[i][2];
        sum_col4 += matrix[i][3];
    }

    printf("Суммы строк: %d %d %d\n", sum_row1, sum_row2, sum_row3);
    printf("Суммы столбцов: %d %d %d %d\n", sum_col1, sum_col2, sum_col3, sum_col4);

    return 0;
}

