#include <stdio.h>

int main(void) {
    int m;
    int *p = &m;
    for (int i = -5; i <= 10; i++) {
        p[i] = 0;
    }

    return 0;
}
