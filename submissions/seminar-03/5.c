#include <stdio.h>

int main(void) {
    int n, x, s = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        s += x;
    }

    printf("%d\n", s);
    return 0;
}
