#include <stdio.h>

size_t longest_run(const int a[], size_t n)
{
    size_t curr_count = 0;
    int prev = 0;
    _Bool first_call = 1;
    size_t max = 0;

    for (size_t i = 0; i < n; i++)
    {
        if (first_call == 1)
        {
            prev = a[i];
            curr_count += 1;
            first_call = 0;
            continue;
        }

        if (a[i] == prev)
        {
            curr_count += 1;
        }
        else
        {
            max = curr_count > max ? curr_count : max;
            curr_count = 1;
            prev = a[i];
        }
    }
    max = curr_count > max ? curr_count : max;
    return max;
}

int main(void)
{

    int example1[6] = {1, 1, 2, 2, 2, 3};
    printf("%zu\n", longest_run(example1, 6));

    int example2[4] = {5, 5, 5, 5};
    printf("%zu\n", longest_run(example2, 4));

    int example3[4] = {1, 2, 3, 4};
    printf("%zu\n", longest_run(example3, 4));

    printf("%zu\n", longest_run(NULL, 0));

    return 0;
}
