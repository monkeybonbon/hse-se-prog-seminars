#include <stdio.h>

int main(void)
{
    int n;
    scanf("%i", &n);
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%i", &a[i][j]);
        }
    }
    printf("\n");

    // транспонируем
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int tmp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = tmp;
        }
    }

    // переворачиваем каждую строку
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n/2; j++)
        {
            int tmp = a[i][j];
            a[i][j] = a[i][n-j-1];
            a[i][n-j-1] = tmp;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%i ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}