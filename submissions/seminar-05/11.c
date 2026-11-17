#include <stdio.h>

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);

    int a[n][m];
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;
    int value = 1;

    while (top <= bottom && left <= right)
    {
        for (int j = left; j <= right; j++)
        {
            a[top][j] = value++;
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            a[i][right] = value++;
        }
        right--;

        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
            {
                a[bottom][j] = value++;
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                a[i][left] = value++;
            }
            left++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
