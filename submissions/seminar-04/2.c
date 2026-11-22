#include <stdio.h>

int main(void){
    int N;
    scanf("%d",&N);
    int a[N];
    int k;   
    for (int i=0;i<N;i++){
        scanf("%d",&k);
        a[i]=k;
    }
    int c[N];
    int j =0;
    for (int i=N-1;i>-1;i--){
        c[j]=a[i];
        j++;
        
        
    }
    for (int i=0;i<N;i++){
        printf("%d%c", c[i], i == N - 1 ? '\n' : ' ');
    }

    return 0;
}