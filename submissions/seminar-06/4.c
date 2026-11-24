#include <stdio.h>

size_t longest_run(const int a[], size_t n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        size_t  cur = 1;
        size_t  sum = 1;
        for (size_t i = 1; i < n; i++)  {
            if (a[i-1] == a[i]) {
                cur++;
            } else {
                cur = 1;
            }
            if (cur > sum) {
                sum = cur;
            }
        }
        return sum;
    }
    
}


int main(void) {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        puts("0");
        return 0;
    }
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("%zu\n", longest_run(a, n));
}
