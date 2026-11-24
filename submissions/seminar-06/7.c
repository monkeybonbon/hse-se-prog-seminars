#include <stdio.h>

int second_max(const int a[], size_t n)
{
    int first_max = a[0];
    for (int i = 0; i < n; i++)
    {
        first_max = first_max > a[i] ? first_max : a[i];
    }

    int sec_max = a[0];
    for (int i = 0; i < n; i++)
    {
        sec_max = first_max > a[i] ? first_max : a[i];
    }
};

int main(void)
{
    int example1[] = {4, 8, 2, 6};
    printf("%d\n", second_max(example1, 4));
    return 0;
}
