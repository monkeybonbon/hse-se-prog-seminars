#include <stdio.h>

size_t longest_run(const int a[], size_t n) {
    if (n==0)
        return 0;
    size_t current = 1;
    size_t longest = 1;
    for (size_t i = 1; i<n; i++) {
        if (a[i] == a[i-1])
            current++;
        else
            current = 1;
        if (current > longest) {
            longest = current;
        }
    }
    return longest;
}


int main(void) {
    int a[] = {1, 1, 2, 2, 2, 3};
    printf("%d", longest_run(a, sizeof(a)/sizeof(a[0])));
}