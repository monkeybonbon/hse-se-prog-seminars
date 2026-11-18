#include <stdio.h>

int main(void)
{
    int x;
    scanf("%i", &x);
    int n = 0;
    int xcopy = x;
    while (xcopy > 0)
    {
        n++;
        xcopy /= 10;
    }

    for (int i = n; i > 0; i--)
    {
        xcopy = x;
        for (int j = 0; j < i-1; j++)
        {
            xcopy /= 10;
        }
        printf("%i ", xcopy % 10);
    }
    printf("\n");
    return 0;
}