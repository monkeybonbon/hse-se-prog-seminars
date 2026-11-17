#include <stdio.h>

int main(void)
{
    int a[3][4];
    int sum_r[3] = {0};
    int sum_c[4] = {0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &a[i][j]);
            sum_r[i] += a[i][j];
            sum_c[j] += a[i][j];
        }
    }

    printf("Суммы строк: ");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", sum_r[i]);
    }
    printf("\n");
    printf("Суммы столбцов: ");
    for (int j = 0; j < 4; j++)
    {
        printf("%d ", sum_c[j]);
    }
    printf("\n");

    
    return 0;
}