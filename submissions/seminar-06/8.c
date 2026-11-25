#include <stdio.h>

void rotate_right(int a[], size_t n, unsigned x)
{
    for (int j = 0; j < x % n; j++)
    {
        for (int i = n-1; i > 0; i--)
        {
            int tmp = a[i];
            a[i] = a[i-1];
            a[i-1] = tmp;
        }
    }    
}

int main(void)
{
    int a[] = {1, 2, 3, 4, 5};
    int n = 5;

    rotate_right(a, n, 4);
    
    for (int i = 0; i < n; i++)
    {
        printf("%i ", a[i]);
    }
    printf("\n");
    return 0;
}
