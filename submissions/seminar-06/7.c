#include <stdio.h>
int second_max(const int a[], size_t n)
{
    int mx = a[0], mn = a[0];
    for (size_t i = 1; i < n; i++)
    {
        if (a[i] > mx)
            mx = a[i];
        if (a[i] < mn)
            mn = a[i];
    }
    int rez = mn;
    for (size_t i = 0; i < n; i++)
        if (a[i] < mx && a[i] > rez)
            rez = a[i];
    return rez;
}
int main(void)
{
    int a[] = {4, 8, 2, 6};
    int b[] = {5, 5, 3, 1};
    int c[] = {-1, -7, -3};
    printf("%d\n", second_max(a, 4));
    printf("%d\n", second_max(b, 4));
    printf("%d\n", second_max(c, 3));
    return 0;
}