#include <stdio.h>

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (int k = 0; k < n * m - 1; k++)
    {
        int max_index = k;
        for (int t = k + 1; t < n * m; t++)
        {
            if (a[t / m][t % m] > a[max_index / m][max_index % m])
            {
                max_index = t;
            }
        }

        int temp = a[k / m][k % m];
        a[k / m][k % m] = a[max_index / m][max_index % m];
        a[max_index / m][max_index % m] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d%c", a[i][j], j == m - 1 ? '\n' : ' ');
        }
    }

    return 0;
}
