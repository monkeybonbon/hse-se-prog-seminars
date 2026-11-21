#include <stdio.h>

int main(void)
{
    int a[3][4];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%i", &a[i][j]);
        }
    }

    printf("Суммы строк: ");
    for (int row = 0; row < 3; row++)
    {
        int sum_row = 0;
        for (int j = 0; j < 4; j++)
        {
            sum_row += a[row][j];
        }
        printf("%i ", sum_row);
    }
    printf("\nСуммы столбцов: ");

    for (int col = 0; col < 4; col++)
    {
        int sum_col = 0;
        for (int j = 0; j < 3; j++)
        {
            sum_col += a[j][col];
        }
        printf("%i ", sum_col);
    }
    printf("\n");
    return 0;
}