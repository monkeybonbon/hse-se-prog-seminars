#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    unsigned char *bytes = (unsigned char *)&n;
    int size = sizeof(n);

    for (int i = size - 1; i >= 0; i--) {
        unsigned int byte = bytes[i];
        printf("%02X", byte);

        if (i > 0) {
            printf(" ");
        }
    }

    printf("\n");
    return 0;
}