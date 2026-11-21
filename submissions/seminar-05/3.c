#include <stdio.h>

int main(void)
{
    int a[16];
    int N = 16;
    for (int i = 0; i < N; i++)
    {
        a[i] = i + 1;
    }

    for (int i = 0; i < 16; i++)
    {
        printf("%i ", a[i]);
    }
    printf("\n");
    
    int *p = &a[5];
    
    for (int i = -5; i < 16-5; i++)
    {
        *(p + i) = 0;
    }
    
    for (int i = 0; i < 16; i++)
    {
        printf("%i ", a[i]);
    }
    printf("\n");
    return 0;
}