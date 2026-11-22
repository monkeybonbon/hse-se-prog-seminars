#include <stdio.h>

int main() {
    int n;
    int arr[100];

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int x;
    scanf("%d", &x);

    arr[n] = x;

    for (int i = 0; i < n + 1; ++i) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
