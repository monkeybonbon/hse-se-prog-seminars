#include <stdio.h>

size_t longest_run(const int a[], size_t n){
    if (n == 0 || n == 1){
        return n;
    }

    size_t k = 1;
    size_t maxk = 1;

    for (size_t i = 0; i < n - 1; i++){
        if (a[i] == a[i+1]){
            k += 1;
            if (k > maxk){
                maxk = k;
            }
        } else {
            k = 1;
        }
    }

    return maxk;
}

// int main(void){
//     int a[4] = {2, 1, 1, 1};
//     size_t res = longest_run(a, 4);

//     printf("%zu\n", res);


//     return 0;
// }


