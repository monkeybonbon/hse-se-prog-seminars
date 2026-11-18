#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    if (n % 2 == 0) {
        printf("Error: n must be odd\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == n / 2 && j == n / 2)
                printf("X");
            else if (i == j)
                printf("\\");
            else if (i + j == n - 1)
                printf("/");
            else
                printf("-");
        }
        printf("\n");
    }

    return 0;
}