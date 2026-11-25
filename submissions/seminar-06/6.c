#include <stdio.h>
void normalize(int *a, int*b, int*c){
    if (*a>*b){
        int old = *a;
        *a = *b;
        *b = *old;
    }

    if (*b>*c){
        int old = *b;
        *b = *c;
        *c = *old
    }
    if (*a>*b){
        int old = *a;
        *a = *b;
        *b = *old;
    }
}