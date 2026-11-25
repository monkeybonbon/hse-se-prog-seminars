#include <stdio.h>

int second_max(const int a[], size_t n)
{
    int s_max = a[0];
    int max = a[0];
    int found_s = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            s_max = max;
            max = a[i];
            found_s = 1;
        }
        else if (a[i] < max && (!found_s || a[i] > s_max))
        {
            s_max = a[i];
            found_s = 1;
        }
    }

    return s_max;
}

int main(void)
{
    int a[] = {4, 8, 2, 6};
    int n1 = 4;

    int b[] = {5, 5, 3, 1};
    int n2 = 4;

    int c[] = {-1, -7, -3};
    int n3 = 3;

    printf("%i\n", second_max(a, n1));
    printf("%i\n", second_max(b, n2));
    printf("%i\n", second_max(c, n3));
    return 0;
}