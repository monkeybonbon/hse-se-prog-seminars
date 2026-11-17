#include <stdio.h>

int main(void){

    int N, M;

    scanf("%d %d", &N, &M);
    int a[N][M];

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < N * M; i++){
        for (int j = i + 1; j < N * M; j++){
            if (a[i/M][i%M] < a[j/M][j%M]){
                int x = a[i/M][i%M];
                a[i/M][i%M] = a[j/M][j%M];
                a[j/M][j%M] = x;
            }
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}