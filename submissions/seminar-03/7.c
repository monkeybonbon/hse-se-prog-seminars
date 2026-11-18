#include <stdio.h>

int main(void) {
    int n, x, m;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 1; i < n; i++) {
        scanf("%d", &x);
        if (x < m) {
            m = x;
        }
    }
    printf("%d\n", m);
    return 0;
}
