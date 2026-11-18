#include <stdio.h>

int main(void)
{
    int a;
    int sum = 0;
    do
    {
        scanf("%i", &a);
        sum += a;
    } while (a != 0);

    printf("%i\n", sum);
    return 0;
}