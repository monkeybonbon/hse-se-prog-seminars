#include <stdio.h>
int main(){
    int arr[16];
    int *p = &arr[5];
    for (int i = 0; i<16; i++) {
       *(p - 5 + i) = 0;
    }
}