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
    int sum=0;
    for (int i=0;i<N;i++){
        sum+=a[i];
    }
    printf("%d",sum);
    return 0;

}