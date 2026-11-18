#include <stdio.h>

int main(void)
{
    int n;
    scanf("%i", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == n / 2 && j == n / 2)
            {
                printf("X");
            }
            else if (i + j == n - 1)
            {
                printf("/");
            }
            else if (i == j)
            {
                printf("\\");
            }
            else
            {
                printf("-");
            }
        }
        printf("\n");
    }
    return 0;
}