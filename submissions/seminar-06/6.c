#include "stdio.h"

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int min3(int a, int b, int c)
{
    return min(min(a, b), c);
}

int max3(int a, int b, int c)
{
    return max(max(a, b), c);
}

void normalize(int *a, int *b, int *c)
{
    int fir = min3(*a, *b, *c);
    int sec = *a + *b + *c - min3(*a, *b, *c) - max3(*a, *b, *c);
    int third = max3(*a, *b, *c);

    *a = fir;
    *b = sec;
    *c = third;

    printf("%d %d %d", *a, *b, *c);
}

int main()
{
    int x = 9, y = 2, z = 5;
    normalize(&x, &y, &z);
}