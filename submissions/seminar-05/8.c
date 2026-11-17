#include <stdio.h>

int main() {
    char a[8][8];
    int x, y;

    printf("Введите шахматную доску:\n");

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            scanf(" %c", &a[i][j]);

            if (a[i][j] == 'R') {
                x = i;
                y = j;
            }
        }
    }

    for (int i = 0; i < 8; i++) {
        if (i != x) {
            a[i][y] = '*';
        }
    }

    for (int j = 0; j < 8; j++) {
        if (j != y) {
            a[x][j] = '*';
        }
    }

    printf("\nШахматная доска после отметки атакуемых клеток:\n");

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}