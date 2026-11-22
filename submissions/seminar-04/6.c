#include <stdio.h>

int main(void) {
    int n;
    int a[100];
    int x;
    int index = -1;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &x);

    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            index = i;
            break;
        }
    }

    printf("%d\n", index);

    return 0;
}
