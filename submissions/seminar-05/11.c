#include <stdio.h>

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n][m];

    int t = 0, b = n - 1;
    int l = 0, r = m - 1;
    int num = 1;

    while (t <= b && l <= r)
    {
        for (int i = l; i <= r; i++)
        {
            arr[t][i] = num++;
        }
        t++;

        for (int i = t; i <= b; i++)
        {
            arr[i][r] = num++;
        }
        r--;

        if (t <= b)
        {
            for (int i = r; i >= l; i--)
            {
                arr[b][i] = num++;
            }
            b--;
        }

        if (l <= r)
        {
            for (int i = b; i >= t; i--)
            {
                arr[i][l] = num++;
            }
            l++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}