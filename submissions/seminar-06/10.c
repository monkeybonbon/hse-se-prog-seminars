#include <stdio.h>

int is_sorted(const int a[], size_t n)
{
    if (n < 2)
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
    int ex1[] = {1, 3, 2, 4};
    printf("%d\n", is_sorted(ex1, 4)); // 0

    int ex2[] = {1, 2, 2, 5};
    printf("%d\n", is_sorted(ex2, 4)); // 1

    int ex3[] = {7};
    printf("%d\n", is_sorted(ex3, 1)); // 1
    printf("%d\n", is_sorted(NULL, 0)); // 1

    int ex4[] = {3, 1, 2};
    printf("%d\n", is_sorted(ex4, 3)); // 0

    int ex5[] = {1, 2, 3, 2};
    printf("%d\n", is_sorted(ex5, 4)); // 0

    int ex6[] = {4, 4, 4};
    printf("%d\n", is_sorted(ex6, 3)); // 1

    int ex7[] = {-5, -2, 0, 3};
    printf("%d\n", is_sorted(ex7, 4)); // 1

    return 0;
}
