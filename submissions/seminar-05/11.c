#include <stdio.h>

int main(void){

    int N, M;
    int ch = 1;

    scanf("%d %d", &N, &M);

    int a[N][M];

    if (N <= M){
        for (int i = 0; i < (N/2 + N%2); i++){

            for (int j = i; j < M - i; j++){
                a[i][j] = ch;
                ch += 1;
            }

            if ((N % 2 == 1) && (i == N/2 + N%2 - 1)){
                for (int k = 0; k < N; k++){
                    for (int l = 0; l < M; l++){
                        printf("%d ", a[k][l]);
                    }
                    printf("\n");
                }

                return 0;
            }

            for (int z = i; z < N - i; z++){
                if (z != i){
                    a[z][M-1-i] = ch;
                    ch += 1;
                }
            }

            for (int w = M - 1 - i; w >= i; w--){
                if (w != M - 1 - i){
                    a[N-1-i][w] = ch;
                    ch += 1;
                }
            }
            for (int v = N - 1 - i; v > i; v--){
                if (v != N - 1 - i){
                    a[v][i] = ch;
                    ch += 1;
                }
            }
        }
    } else{
        int b[M][N];
        
        for (int i = 0; i < (M/2 + M%2); i++){

            for (int v = M - 1 - i; v >= i; v--){
                b[v][i] = ch;
                ch += 1;
            }

            for (int j = i; j < N - i; j++){
                if (j != i){
                    b[i][j] = ch;
                    ch += 1;
                }
            }

            if ((M % 2 == 1) && (i == M/2 + M%2 - 1)){
                for (int l = 0; l < M; l++){
                    for (int k = 0; k < N; k++){
                        a[k][M - 1 - l] = b[l][k];
                    }      
                }   
                
                for (int k = 0; k < N; k++){
                    for (int l = 0; l < M; l++){
                        printf("%d ", a[k][l]);
                    }
                    printf("\n");
                }

                return 0;
            }

            for (int z = i; z < M - i; z++){
                if (z != i){
                    b[z][N-1-i] = ch;
                    ch += 1;
                }
            }

            for (int w = N - 1 - i; w > i; w--){
                if (w != N - 1 - i){
                    b[M-1-i][w] = ch;
                    ch += 1;
                }
            }

        }

        for (int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                a[j][M - 1 - i] = b[i][j];
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