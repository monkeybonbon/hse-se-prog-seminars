#include <stdio.h>
int main()
{
    int a[10];
    
    size_t count = sizeof(a) / sizeof(int);
    
    printf("%zu\n", count); 

    return 0;
}