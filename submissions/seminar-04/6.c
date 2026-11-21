#include <stdio.h>

int main(void) {
    int n, a[100], x, ans = -1;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &x);
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            ans = i;
            break;
        }
    }

    printf("%d\n", ans);
    return 0;
}
