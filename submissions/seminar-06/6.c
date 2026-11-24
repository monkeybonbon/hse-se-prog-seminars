#include <stdio.h>

void normalize(int *a, int *b, int *c)
{
    int tmp;

    if (*a > *b)
    {
        tmp = *a;
        *a = *b;
        *b = tmp;
    }

    if (*b > *c)
    {
        tmp = *b;
        *b = *c;
        *c = tmp;
    }

    if (*a > *b)
    {
        tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

int main(void)
{
    int x = 9, y = 2, z = 5;

    normalize(&x, &y, &z);

    printf("x = %d, y = %d, z = %d\n", x, y, z);

    return 0;
}
