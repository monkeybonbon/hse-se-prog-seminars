#include <stdio.h>
#include <stddef.h>

size_t longest_run(const int a[], size_t n) {
    if (n == 0)
        return 0;

    size_t best = 1;
    size_t cur = 1;

    for (size_t i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            cur++;
        } else {
            cur = 1;
        }
        if (cur > best)
            best = cur;
    }
    return best;
}

int main(void) {
    const int t1[] = {1, 1, 2, 2, 2, 3};
    const int t2[] = {5, 5, 5, 5};
    const int t3[] = {1, 2, 3, 4};

    printf("%zu\n", longest_run(t1, sizeof t1 / sizeof t1[0])); 
    printf("%zu\n", longest_run(t2, sizeof t2 / sizeof t2[0])); 
    printf("%zu\n", longest_run(t3, sizeof t3 / sizeof t3[0]));
    printf("%zu\n", longest_run(NULL, 0));                      
    return 0;
}