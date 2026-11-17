#include "stdio.h"

int main()
{

    int n, m;
    scanf("%d %d", &n, &m);

    int s[n][m];
    int d[101];

    for (int i = 0; i < 101; i++) d[i] = 0; 

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &s[i][j]);
            d[s[i][j]]++;
        }
    }

    int ind = 100;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            while (ind >= 0 && !d[ind])
                ind--;

            if (ind < 0 || !d[ind])
                break;

            s[i][j] = ind;
            d[ind]--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }
}
