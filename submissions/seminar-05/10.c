#include <stdio.h>

int main(void){

    int N;

    scanf("%d", &N);

    int a[N][N];

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            scanf("%d", &a[i][j]);
        }
    }

    // int b[N][N];

    // for (int i = 0; i < N; i++){
    //     for (int j = 0; j < N; j++){
    //         b[j][N - 1 - i] = a[i][j];
    //     }
    // }

    // for (int i = 0; i < N; i++){
    //     for (int j = 0; j < N; j++){
    //         printf("%d ", b[i][j]);
    //     }
    //     printf("\n");
    // }

    for (int i = 0; i < N/2; i++){
        for (int j = 0; j < N; j++){
            int temp = a[N-1-i][j];
            a[N-1-i][j] = a[i][j];
            a[i][j] = temp;
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = i; j < N; j++){
            int temp = a[j][i];
            a[j][i] = a[i][j];
            a[i][j] = temp;
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}