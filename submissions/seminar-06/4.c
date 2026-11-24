#include "stdio.h"

size_t longest_run(const int a[], size_t n)
{
    if (n == 0)
        return 0;

    int len = 1, max_len = 1;

    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
            len++;
        else
            len = 1;

        max_len = len > max_len ? len : max_len;
    }

    return max_len;
}

int main()
{
    int a[4] = {};

    printf("%d ", (int)longest_run(a, 0));
}