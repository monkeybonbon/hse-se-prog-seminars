#include <stdio.h>

int main(void)
{
    char a[8][8];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            scanf(" %c", &a[i][j]);
        }
    }

    int index_i, index_j = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (a[i][j] == 'R')
            {
                index_i = i;
                index_j = j;
            }
        }
    }

    for (int i = 0; i < 8; i++)
    {
        if (a[i][index_j] != 'R')
        {
            a[i][index_j] = '*';
        }
        if (a[index_i][i] != 'R')
        {
            a[index_i][i] = '*';
        }
    }

    printf("\n");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}