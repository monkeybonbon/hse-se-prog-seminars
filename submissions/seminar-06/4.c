#include <stdio.h>

size_t longest_run(const int a[], size_t n) {
    if (n == 0) return 0;
    size_t cur = 1;
    size_t lgst = 1;
    for (size_t i = 0; i < n - 1; ++i) {
        if (a[i] == a[i + 1]) cur++;
        else cur = 1;
        lgst = lgst > cur ? lgst : cur;
    }
    return lgst;
}

int main(void) {
    int a[] = {5, 5, 5, 5};
    printf("%zu\n", longest_run(a, sizeof(a) / sizeof(a[0])));
    return 0;
}
