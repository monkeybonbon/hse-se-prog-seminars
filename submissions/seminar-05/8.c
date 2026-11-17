#include <stdio.h>

int main(void)
{
    char arr[8][8];

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            scanf(" %c", &arr[i][j]);
        }
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (arr[i][j] == 'R')
            {
                for (int n = 0; n < 8; n++)
                {
                    if (n != j)
                    {
                        arr[i][n] = '*';
                    }
                    if (n != i)
                    {
                        arr[n][j] = '*';
                    }
                }
            }
        }
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}