#include <stdio.h>

int main(void) {
    int b[4][5]; 
    int *p = &b[2][1], *q = &b[3][4];
    
    printf("а) %td\nб) %td\nв) %td\n", q - (int *)b, p - (int *)b, p - q);
    
    // а) q - (int *)b = 19 (3 * 5 + 4)
    // б) p - (int *)b = 11 (2 * 5 + 1)
    // в) p - q = -8  (11 - 19)
    return 0;
}
