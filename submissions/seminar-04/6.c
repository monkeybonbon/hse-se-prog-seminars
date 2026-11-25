#include <stdio.h>

int main(void) {
    int n;
    int arr[100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    scanf("%d", &x);

    int ind = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            ind = i;
            break;
        }
    }

    printf("%d\n", ind);

    return 0;
}
