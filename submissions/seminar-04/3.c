#include <stdio.h>

int main(void) {
    int n, a[100], s = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        s += a[i];
    }

    printf("%d\n", s);
    return 0;
}
