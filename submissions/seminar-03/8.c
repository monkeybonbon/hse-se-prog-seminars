#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    int mid = a / 2;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            if (i == mid && j == mid) {
                printf("X");
            } else if (i == j) {
                printf("\\");
            } else if (i + j == a - 1) {
                printf("/");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }

    return 0;
}
