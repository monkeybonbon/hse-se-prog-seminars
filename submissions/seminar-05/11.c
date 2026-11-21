#include <stdio.h>

int main(void)
{
    int n, m;
    scanf("%i %i", &m, &n);
    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = -1;
        }
    }
    

    int s = 1;
    for (int k = 0; k < m - k && k < n - k; k++)
    {
        for (int i = k; i < n - k; i++)
        {
            a[k][i] = s;
            s++;
        }

        for (int i = k + 1; i < m-k; i++)
        {
            a[i][n-k-1] = s;
            s++;
        }

        if (k < m - k - 1)
        {
            for (int i = n - k - 2; i >= k; i--)
            {
                a[m-k-1][i] = s;
                s++;
            }
        }

        if (k < n - k - 1)
        {
            for (int i = m - k - 2; i > k; i--)
            {
                a[i][k] = s;
                s++;
            }
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3i ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
