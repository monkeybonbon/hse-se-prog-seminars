#include <stdio.h>


static void reverse(int a[], int l, int r)
{
    while (l < r)
    {
        int t = a[l];
        a[l] = a[r];
        a[r] = t;
        l++;
        r--;
    }
}

void rotate_right(int a[], size_t n, unsigned x)
{
    if (n <= 1)
    {
        return;
    }

    x = x % n;

    if (x < 0)
    {
        x += n;
    }

    if (x == 0)
    {
        return;
    }

    reverse(a, 0, n - 1);
    reverse(a, 0, x - 1);
    reverse(a, x, n - 1);
}

int main(void)
{
    size_t n = 0;
    unsigned x = 0;
    scanf("%ld %d", &n, &x);

    int arr[n];

    for (int idx = 0; idx < n; idx++)
    {
        scanf("%d", &arr[idx]);
    }

    rotate_right(arr, n, x);

    for (int idx = 0; idx < n; idx++)
    {
        printf("%d ", arr[idx]);
    }

    return 0;
}