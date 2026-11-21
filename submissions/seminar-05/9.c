#include <stdio.h>

int main()
{
    int n, m;
    scanf("%i %i", &n, &m);

    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%i", &a[i][j]);
        }
    }
    printf("\n");

    for (int k = 0; k < n*m; k++)
    {
        int swapped = 0;
        for (int q = 0; q < n*m - k - 1; q++)
        {
            int i_1 = q / n;
            int j_1 = q % n;

            int i_2 = (q + 1) / n;
            int j_2 = (q + 1) % n;

            if (a[i_1][j_1] < a[i_2][j_2])
            {
                int tmp = a[i_1][j_1];
                a[i_1][j_1] = a[i_2][j_2];
                a[i_2][j_2] = tmp;
                swapped = 1;
            }
        }
        if (swapped == 0)
        {
            break;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%i ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}