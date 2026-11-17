#include <stdio.h>
int main() {
    int arr[3][4];
    int rows[3] = {0};
    int cols[4] = {0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &arr[i][j]);

            rows[i] += arr[i][j];
            cols[j] += arr[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        printf("%d ", rows[i]);
    }

    printf("\n");

    for (int j = 0; j < 4; j++) {
        printf("%d ", cols[j]);
    }


}