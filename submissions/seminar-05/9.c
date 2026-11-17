#include <stdio.h>
int main(void){
    int n,m;
    scanf("%d %d", &n, &m);
    int a[n][m];
    int num[n*m];
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m ;j++){
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i< n*m; i++){
        num[i] = *(&a[0][0]+i);
    }
    
    for (int i = 0; i< n*m; i++){
        printf("%d ", num[i]);
    } 

    for (int i = 0; i < n*m-1; i++){
        for (int j = 0; j< n*m-1-i;j++){
            if (num[j]<num[j+1]){
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
            printf("\n");

    for (int i = 0; i<n*m; i+=m){
        for (int j = 0; j<m; j++){
            printf("%d ", num[i+j]);
        }
        printf("\n");
    }
    
    return 0;
} 