#include <stdio.h>

void zero_array(int *p)
{
    for (int i = -5; i <= 10; i++) {
        p[i] = 0;
    }
}