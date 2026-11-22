#include <stdio.h>

int main(void) {
    int n;
    int a[100];
    int sum = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    printf("%d\n", sum);

    return 0;
}
