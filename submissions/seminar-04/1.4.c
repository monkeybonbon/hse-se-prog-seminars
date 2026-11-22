#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    unsigned char* p = (unsigned char*)&n;

    for (int i = sizeof(int) - 1; i >= 0; i--) {
        printf("%02X", p[i]);

        if (i > 0) {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}
