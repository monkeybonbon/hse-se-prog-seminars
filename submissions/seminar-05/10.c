#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    int a[100][100];
    int x;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d" , &x);
            a[i][j] = x;

        }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n ; j++){
            int t = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = t;
        }
    }

for (int i = 0; i < n; i++){
    for (int j = 0; j < n / 2; j++){
        int t = a[i][j];
        a[i][j] = a[i][n - j -1];
        a[i][n - j -1] = t;
    }
}

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}