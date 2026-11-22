#include <stdio.h>

int main(void){
    int N;
    scanf("%d",&N);
    int a[N];
    int k;
    for(int i=0;i<N;i++){
        scanf("%d",&k);
        a[i]=k;
    }
    int x;
    scanf("%d",&x);
    int c[N+1];
    for(int i=0;i<N;i++){
        c[i]=a[i];
        }
    c[N]=x;
    for (int i =0;i<=N;i++){
        printf("%d%c", c[i], i == N ? '\n' : ' ');
    }
    return 0;
}