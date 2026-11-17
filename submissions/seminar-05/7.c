#include <stdio.h>

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n][m];
    int t[m][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            t[j][i] = a[i][j];
        }
    }
    printf("Результат \n");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
    return 0;
}