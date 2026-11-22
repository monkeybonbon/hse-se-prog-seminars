#include <stdio.h>

int main(void){
    int N;
    scanf("%d",&N);
    int a[N];
    for (int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    int x,k;
    scanf("%d %d",&x,&k);
    int b[N+1];
    for(int i=0;i<k;i++){
        b[i]=a[i];
    }

    b[k]=x;
    for(int i=k;i<N;i++){
        b[i+1]=a[i];
    }

    for (int i=0;i<=N;i++){
        printf("%d%c", b[i], i == N ? '\n' : ' ');
    }
    return 0;
}