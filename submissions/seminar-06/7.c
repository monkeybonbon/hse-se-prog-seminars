#include <stdio.h>

int second_max(const int a[], size_t n)
{
    int max1 = a[0];

    size_t idx = 1;
    while (idx < n && a[idx] == max1)
    {
        idx++;
    }

    int max2;
    if (a[idx] > max1)
    {
        max2 = max1;
        max1 = a[idx];
    }
    else
    {
        max2 = a[idx];
    }
    idx++;

    for (; idx < n; idx++)
    {
        if (a[idx] > max1)
        {
            max2 = max1;
            max1 = a[idx];
        }
        else if (a[idx] != max1 && a[idx] > max2)
        {
            max2 = a[idx];
        }
    }
    
    return max2;
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

    int ans = second_max(arr, n);

    printf("%d\n", ans);

    return 0;
}