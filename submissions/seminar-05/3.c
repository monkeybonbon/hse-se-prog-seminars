#include <stdio.h>


int main(void)
{
    int a[16] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int *p = &a[5];
    for (int i = -5; i < 11; i++)
    {
        *(p + i) = 0;
    }
    return 0;
}