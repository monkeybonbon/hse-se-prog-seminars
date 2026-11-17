
#include <stdio.h>

int main(void) {
    int a[3][4];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        int sum = 0;

        for (int j = 0; j < 4; j++) {
            sum += a[i][j];
        }
        printf("%d ", sum);
    }
 
    printf("\n");

    for (int j = 0; j < 4; j++) {
        int sum = 0;

        for (int i = 0; i < 3; i++) {
            sum += a[i][j];
        }
        printf("%d ", sum);
    }

    printf("\n");

    return 0;
}
