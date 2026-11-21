#include <stdio.h>

int main(void)
{
    int n,m;
    scanf("%i %i", &n, &m);
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%i", &a[i][j]);
        }
    }

    int b[m][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            b[j][i] = a[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%i ", b[i][j]);
        }
        printf("\n");
    }
    return 0;
}
