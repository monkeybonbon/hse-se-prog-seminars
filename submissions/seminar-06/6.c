#include <stdio.h>

void normalize(int *a, int *b, int *c){
    int t;
    if (*a > *b){
        t = *a;
        *a = *b;
        *b = t;

    }
    if (*b > *c){
        t = *b;
        *b = *c;
        *c = t; 
    }
    if (*a > *b){
        t = *a;
        *a = *b;    
        *b = t;
    }
    


}
