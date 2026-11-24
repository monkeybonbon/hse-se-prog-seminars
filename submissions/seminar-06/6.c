#include <stdio.h>
void normalize(int *x, int *y, int *z)
{
    int temp;

    if (*x > *y)
    {
        temp = *x;
        *x = *y;
        *y = temp;
    }

    if (*y > *z)
    {
        temp = *y;
        *y = *z;
        *z = temp;
    }

    if (*x > *y)
    {
        temp = *x;
        *x = *y;
        *y = temp;
    }
}
int main(void)
{
    int x = 9, y = 2, z = 5;
    normalize(&x, &y, &z);
    printf("x = %d, y = %d, z = %d\n", x, y, z);
    return 0;
}
