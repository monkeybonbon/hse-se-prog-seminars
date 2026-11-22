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

    int c = a;
    int n = 0;
    while (c > 0)
    {
        c /= 10;
        ++n;
    }

    int dec = 1;
    for (int i = 0; i < n - 1; i++) {
        dec *= 10;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a / dec % 10);
        dec /= 10;
    }

    printf("\n");

    return 0;
}
