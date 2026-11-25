#include <stdio.h>

size_t longest_run(const int a[], size_t n)
{
    if (n <= 0)
    {
        return 0;
    }
    int current_num = a[0];
    size_t current_count = 0;
    size_t max_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (current_num == a[i])
        {
            current_count++;
        }
        else
        {
            current_num = a[i];
            max_count = current_count > max_count ? current_count : max_count;
            current_count = 1;
        }
    }

    return current_count > max_count ? current_count : max_count;
}

int main(void)
{
    int a[] = {1, 1, 2, 2, 2, 3};
    size_t n1 = 6;
    printf("%zu\n", longest_run(a, n1));

    int b[] = {5, 5, 5, 5};
    size_t n2 = 4;
    printf("%zu\n", longest_run(b, n2));

    int c[] = {1, 2, 3, 4};
    size_t n3 = 4;
    printf("%zu\n", longest_run(c, n3));

    int d[] = {};
    size_t n4 = 0;
    printf("%zu\n", longest_run(d, n4));

    
    return 0;
}