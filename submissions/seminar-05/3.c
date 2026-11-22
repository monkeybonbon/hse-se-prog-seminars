#include <stdio.h>

int main(void)
{
    int a[16];
    int *p = &a[5];

    for (int i = 0; i < 16; i++)
    {
        a[i] = 0;
    }
    
    for (int j = 0; j < 16; j++)
    {
        printf("%d\n", a[j]);
    }
 
    return 0;
}