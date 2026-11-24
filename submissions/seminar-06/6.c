#include "stdio.h"

int max(const int *a, const int *b, const int *c) {
    int ans = *a > *b ? *a : *b;
    ans = ans > *c ? ans : *c;
    return ans;
}

int min(const int *a, const int *b, const int *c) {
    int ans = *a < *b ? *a : *b;
    ans = ans < *c ? ans : *c;
    return ans;
}

void normalize(int *a, int *b, int *c) {
    int mn = min(a, b, c);
    int mx = max(a, b, c);
    int sm = *a + *b + *c;

    *a = mn;
    *b = sm - mx - mn;
    *c = mx;
}

int main(void) {
    int x = 9, y = 2, z = 5;

    normalize(&x, &y, &z);

    printf("%d %d %d\n", x, y, z);
    return 0;
}
