#include <stdio.h>

int main(void){
    int a[16];
    int *p =&a[5];
    for(int i=0;i<16;i++){
        (p-5)[i]=0;
    }
    
    return 0;
}