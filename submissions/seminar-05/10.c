#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);

    int a[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);          
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            int trans = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = trans;
        }

    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n/2; j++){
            int menmes= a[i][j];
            a[i][j] = a[i][n -1 - j];
            a[i][n - 1 - j] = menmes;
        }
    }

    return 0;
}