#include "stdio.h"

int min(int a, int b)
{
    return a < b ? a : b;
}

int sorted(const int a[], size_t n)
{
    if (n == 0)
        return 1;

    return min(sorted(a, n - 1), (int)(a[n - 1] <= a[n]));
}

int main()
{
    int a[4] = {1, 2, 2, 4};
    size_t n = sizeof(a) / sizeof(a[0]) - 1;
    printf("%d\n", sorted(a, n));
}
