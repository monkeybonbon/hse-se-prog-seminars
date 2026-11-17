#include "stdio.h"

int main()
{
    int n, m;
    n = 3, m = 4;

    int s[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &s[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum += s[i][j];
        }

        printf("%d ", sum);
    }

    printf("\n");

    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += s[j][i];
        }

        printf("%d ", sum);
    }

    printf("\n");
}
