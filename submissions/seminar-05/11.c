#include <stdio.h>

int main(void) {
    int a[100][100];

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            a[i][j] = 0;
        }  
    }

    for(int k = 0; k < n*m; k++){

    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }




    return 0;
}