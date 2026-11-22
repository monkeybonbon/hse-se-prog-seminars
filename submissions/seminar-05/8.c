#include <stdio.h>

int main() {
    int n = 8;
    char arr[n][n];

    int rook_i = 0;
    int rook_j = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf(" %c", &arr[i][j]);
            if (arr[i][j] == 'R') {
                rook_i = i;
                rook_j = j;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] != 'R' && (i == rook_i || j == rook_j)) {
                printf("*");
            } else {
                printf("%c", arr[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
