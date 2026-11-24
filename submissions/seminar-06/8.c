#include "stdio.h"

void rotate_right(int a[], int n, unsigned x)
{
    x = x % n;
    if (n == 0)
        return;

    int b[n];

    for (int i = 0; i < n; i++)
    {
        b[i] = a[(i - x + n) % n];
    }

    for (int i = 0; i < n; i++)
        a[i] = b[i];
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};

    rotate_right(a, 5, 5);

    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n"); 
}