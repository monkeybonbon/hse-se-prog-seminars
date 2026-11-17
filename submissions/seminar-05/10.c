#include <stdio.h>
int main(void){
    int n;
    scanf("%d", &n);
    int a[n][n];
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n ;j++){
            scanf("%d", &a[i][j]);
        }
    }

    
    for (int i = 0; i<n; i++){
        for (int j = i+1; j<n ;j++){
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }


    for (int i = 0; i<n; i++){
        for (int j = 0; j<n/2; j++){
            int temp = a[i][n-1-j];
            a[i][n-1-j] = a[i][j];
            a[i][j] = temp;
        }
    }
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n ;j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }


    return 0;
} 