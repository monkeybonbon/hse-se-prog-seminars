#include <stdio.h>

int is_sorted(const int a[], size_t n)
{
    if (n <= 1)
    {
        return 1;
    }

    if (a[n-2] <= a[n-1])
    {
        return is_sorted(a, n-1);
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    int a[] = {1, 2, 2, 5};
    int n1 = 4;

    int b[] = {1, 3, 2, 4};
    int n2 = 4;

    int c[] = {7};
    int n3 = 1;

    int d[] = {};
    int n4 = 0;

    printf("%i\n", is_sorted(a, n1));
    printf("%i\n", is_sorted(b, n2));
    printf("%i\n", is_sorted(c, n3));
    printf("%i\n", is_sorted(d, n4));
    return 0;
}