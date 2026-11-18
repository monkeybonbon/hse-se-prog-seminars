#include <stdio.h>

int main(void)
{
    int a;
    scanf("%i", &a);

    while (a != 0)
    {
        printf("%i", a % 10);
        a /= 10;
    }
    printf("\n");
    return 0;
}