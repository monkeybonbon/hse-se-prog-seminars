#include <stdio.h>

int main(void) {
    int arr[16];
    int i;
    int *p;
    int *s;
    for(i=0;i<16;i++){
        arr[i]=i+1;
    }
    p=&arr[5];
    s=p-5;


    for (i = 0; i < 16; i++) {
        s[i]=0;
    }
    for(i=0;i<16;i++) printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
