#include <stdio.h>


size_t longest_run(const int a[], size_t n) {


    size_t current = 1;
    size_t max = 1;
    if (n == 0) {
        return 0;
    }

    for (size_t i = 1; i < n; i++) 
    {
        if (a[i] == a[i-1]) 
        {
            current += 1;
        } 

        else {
            current = 1;
        }
        if (current > max) 
            {
                max = current;
            }
        
    }
    return max;
}