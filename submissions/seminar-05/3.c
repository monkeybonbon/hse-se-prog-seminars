#include "stdio.h"

int main()
{
    int a[16];

    for (int i = 0; i < 16; i++)
        a[i] = i + 1;

    int *p = &a[0] + 4;
    p = p - 4;
    for (int i = 0; i < 16; i++)
    {
        *p = 0;
        p += 1;
    }

    for (int i = 0; i < 16; i++)
        printf("%d ", a[i]);
}
