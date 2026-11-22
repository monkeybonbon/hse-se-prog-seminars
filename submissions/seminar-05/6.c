#include <stdio.h>

int main(void)
{
    int a[3][4];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int sum_line_1 =0;
    int sum_column_1 = 0;
    int sum_line_2 = 0;
    int sum_column_2 = 0;
    int sum_line_3 = 0;
    int sum_column_3 = 0;
    int sum_column_4 = 0;

    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            for (int j = 0; j < 4; j++)
            {
                sum_line_1 += a[i][j];
                sum_column_1 += a[j][i];
            }
        }
        else if (i == 1){
            for (int j = 0; j < 4; j++)
            {
                sum_line_2 += a[i][j];
                sum_column_2 += a[j][i];
            }
        }
        else if (i == 2){
            for (int j = 0; j < 4; j++)
            {
                sum_line_3 += a[i][j];
                sum_column_3 += a[j][i];
            }
        }
        else if (i == 3){
            for (int j = 0; j < 4; j++)
            {
                sum_column_4 += a[j][i];
            }
        }
        
    }

        
        printf("\n");

    printf("Sum of lines: %d %d %d\n", sum_line_1, sum_line_2, sum_line_3);
    printf("Sum of columns: %d %d %d %d\n", sum_column_1, sum_column_2, sum_column_3, sum_column_4);


    return 0;
}