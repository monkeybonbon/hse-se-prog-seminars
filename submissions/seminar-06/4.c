#include <stdio.h>

size_t longest_run(const int a[], size_t n)
{
    if (n == 0)
    {
        return 0;
    }

    size_t maxr = 1, cur = 1;
    for (size_t idx = 1; idx < n; idx++)
    {
        if (a[idx] == a[idx - 1])
        {
            cur++;
        }
        else
        {
            if (cur > maxr)
            {
                maxr = cur;
                cur = 1;
            }
        }
    }

    if (cur > maxr)
    {
        maxr = cur;
    }
    
    return maxr;
}

int main(void)
{
    size_t n;
    scanf("%ld", &n);

    int arr[n];

    for (int idx = 0; idx < n; idx++)
    {
        scanf("%d", &arr[idx]);
    }

    size_t ans = longest_run(arr, n);

    printf("%ld\n", ans);

    return 0;
}