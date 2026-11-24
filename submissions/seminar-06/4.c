#include <stdio.h>
size_t longest_run(const int a[], size_t n);
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    size_t size = sizeof(a) / sizeof(a[0]);
    printf("%d\n", longest_run(a, size));
    return 0;
}

size_t longest_run(const int a[], size_t n)
{
    int l = 1;
    int max_l = 1;
    if (n == 1)
    {
        l = 1;
        return l;
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] == a[i + 1])
        {
            l += 1;
            if (l > max_l)
            {
                max_l = l;
            }
            else {
                l = 1;
            }
        }
    }
    return l;
}