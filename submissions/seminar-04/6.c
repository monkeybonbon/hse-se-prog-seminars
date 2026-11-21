#include <stdio.h>

int main(void) {
    int n, x, ans = -1;
    int m[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m[i]);
    }
    scanf("%d", &x);

    for (int i = 0; i < n; i++) {
        if (m[i] == x) {
            ans = i;
            break;
        }
    }
    printf("%d", ans);
    return 0;
}
