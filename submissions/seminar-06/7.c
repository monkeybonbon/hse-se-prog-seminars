#include <stdio.h>

int second_max(const int a[], size_t n){
    int max = a[0], predmax;
    int f = 0;
    for (int i = 1; i < n; i++){
        if (f == 0){
            if (a[i] > max){
                int temp = max;
                max = a[i];
                predmax = temp;
                f = 1;
            } else if (a[i] < max){
                predmax = a[i];
                f = 1;
            } else {
                continue;
            }
        } else {
            if (a[i] > max){
                int temp = max;
                max = a[i];
                predmax = temp;
            } else if (a[i] > predmax){
                predmax = a[i];
            }
        }
    }

    return predmax;
}
