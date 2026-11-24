#include "stdio.h"

int second_max(const int a[], size_t n)
{
    int fir = 0, sec = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > fir)
        {
            sec = fir;
            fir = a[i];
        }
        else if (a[i] > sec && a[i] != fir)
            sec = a[i];
    }

    return sec;
}

int main()
{
    int a[5] = {1, 2, 3, 5, 4};

    printf("%d\n", second_max(a, 5));
}