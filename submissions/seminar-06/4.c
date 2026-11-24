#include <stdio.h>
size_t longest_run(const int a[], size_t n)
{
    if (n == 0)
        return 0;
    size_t lng = 1, cur = 1;
    for (size_t i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
            cur++;
        else
            cur = 1;
        if (cur > lng)
            lng = cur;
    }
    return lng;
}
int main(void)
{
    int a[] = {1, 1, 2, 2, 2, 3};
    int b[] = {5, 5, 5, 5};
    int c[] = {1, 2, 3, 4};
    printf("%zu\n", longest_run(a, 6));
    printf("%zu\n", longest_run(b, 4));
    printf("%zu\n", longest_run(c, 4));
    printf("%zu\n", longest_run(a, 0));
    return 0;
}