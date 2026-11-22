#include <stdio.h>

int main() {
    int n;
    int arr[100];
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int s = 0; // можно было вообще без массива

    for (int i = 0; i < n; ++i) {
        s += arr[i];
    }

    printf("%d\n", s);

    return 0;
}
