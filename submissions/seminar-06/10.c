#include <stdio.h>

int is_sorted(const int a[], size_t n)
{
    if (n <= 1)
    {
        return 1;
    }
    
    if (a[0] > a[1])
    {
        return 0;
    }

    return is_sorted(a + 1, n - 1);
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

    int ans = is_sorted(arr, n);

    printf("%d\n", ans);

    return 0;
}