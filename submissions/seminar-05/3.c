#include <stdio.h>

int main(void)
{
    int arr[16];
    int *p = &arr[5];

    for (int *i = p - 5; i < p - 5 + 16; i++)
    {
        *i = 0;
    }

    return 0;
}