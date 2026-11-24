#include <stdio.h>
int is_sorted(const int a[], size_t n)
{
    if (n < 2)
        return 1;
    if (a[0] > a[1])
        return 0;
    return is_sorted(a + 1, n - 1);
}
int main(void)
{
    int a[] = {1, 2, 2, 5};
    int b[] = {1, 3, 2, 4};
    int c[] = {7};
    printf("%d\n", is_sorted(a, 4));
    printf("%d\n", is_sorted(b, 4));
    printf("%d\n", is_sorted(c, 1));
    printf("%d\n", is_sorted(a, 0));
    return 0;
}