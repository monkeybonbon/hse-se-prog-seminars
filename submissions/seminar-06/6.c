#include <stdio.h>

void normalize(int *a, int *b, int *c)
{
    if (*a > *b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }

    if (*b > *c)
    {
        int t = *b;
        *b = *c;
        *c = t;
    }

    if (*a > *b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }
}

int main(void)
{
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);

    normalize(&x, &y, &z);

    printf("%d %d %d\n", x, y, z);

    return 0;
}