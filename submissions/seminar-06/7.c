#include <stdio.h>
int second_max(const int a[], size_t n);
int main(void)
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    size_t size = sizeof(a) / sizeof(a[0]);
    printf("%d\n", second_max(a, size));
    return 0;
}

int second_max(const int a[], size_t n)
{
    int max_2 = -1000000;
    int max_1 = -1000000;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max_1)
        {
            max_1 = a[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max_2 && a[i] != max_1)
        {
            max_2 = a[i];
        }
    }
    return max_2;
}