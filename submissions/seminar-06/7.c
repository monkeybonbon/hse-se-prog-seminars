#include <stdio.h>
#include <limits.h>

int second_max(const int a[], size_t n){
    int max_1 = a[0];
    for (size_t i = 0; i < n; i++){
        if (a[i] > max_1){
            max_1 = a[i];
        }
    }

    int max_2 = INT_MIN;

    for (size_t i = 0; i < n; i++){
        if (a[i] > max_2 && a[i] != max_1){
            max_2 = a[i];
        }
    }
    return max_2;

}