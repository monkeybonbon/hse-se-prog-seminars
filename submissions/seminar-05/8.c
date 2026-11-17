#include <stdio.h>

int main(void)
{
    char a[8][8];
    int c = 0, r = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            scanf(" %c", &a[i][j]);
            if (a[i][j] == 'R')
            {
                c = i;
                r = j;
            }
        }
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((i == c || j == r) && a[i][j] != 'R')
            {
                a[i][j] = '*';
            }
        }
    }
    printf("Вывод \n");
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