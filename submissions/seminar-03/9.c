#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);

    if (a == 0)
    {
        printf("0\n");
        return 0;
    }

    while (a > 0)
    {
        int d = a % 10;
        a /= 10;
        printf("%d", d);
    }
    printf("\n");

    return 0;
}
