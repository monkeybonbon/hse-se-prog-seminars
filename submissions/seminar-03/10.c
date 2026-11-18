#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);

    if (a == 0)
    {
        printf("0");
        return 0;
    }

    int n = 0;
    for (int i = 1; i <= a; i *= 10)
    {
        ++n;
    }

    int pow = 1;
    for (int i = 0; i < n - 1; i++)
    {
        pow *= 10;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a / pow % 10);
        pow /= 10;
    }

    printf("\n");

    return 0;
}
