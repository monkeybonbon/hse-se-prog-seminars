#include <stdio.h>
int main() {
    int n;
    printf("Razmer massiva: ");
    scanf("%d", &n);
    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int temp1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            temp1 = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp1;
        }
    }
    int temp2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            temp2 = a[i][j];
            a[i][j] = a[i][n - 1 - j];
            a[i][n - 1 - j] = temp2;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}