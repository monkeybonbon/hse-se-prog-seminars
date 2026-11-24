#include <stdio.h>

int second_max(const int a[], size_t n)
{
    int first_max = a[0];
    for (size_t i = 1; i < n; i++)
    {
        first_max = a[i] > first_max ? a[i] : first_max;
    }

    int sec_max = a[0];
    for (size_t i = 1; i < n; i++)
    {
        if (a[i] != first_max && (sec_max == first_max || a[i] > sec_max))
        {
            sec_max = a[i];
        }
    }

    return sec_max;
}

int main(void)
{
    int example1[] = {4, 8, 2, 6};
    printf("%d\n", second_max(example1, 4));

    int example2[] = {5, 5, 3, 1};
    printf("%d\n", second_max(example2, 4));

    int example3[] = {-1, -7, -3};
    printf("%d\n", second_max(example3, 3));

    return 0;
}
