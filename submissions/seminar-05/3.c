#include <stdio.h>
int main(void){
    int arr[16];
    int* p = &arr[5];

    for (int i = -5; i<16-5; i++){
        *(p+i) = 0;
    }

    return 0;
} 