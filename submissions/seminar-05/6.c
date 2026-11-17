#include <stdio.h>

int main(void)
{
    int n = 3;
    int m = 4;

    int arr[3][4];
    int sum_l[] = {0, 0, 0};
    int sum_c[] = {0, 0, 0, 0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
            sum_l[i] += arr[i][j];
        }
    }

    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            sum_c[j] += arr[i][j];
        }
    }

    printf("Суммы строк: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", sum_l[i]);
    }

    printf("\nСуммы столбцов: ");

    for (int i = 0; i < m; i++)
    {
        printf("%d ", sum_c[i]);
    }

    return 0;
}