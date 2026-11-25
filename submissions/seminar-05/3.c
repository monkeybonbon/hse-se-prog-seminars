#include <stdio.h>

int main(void) {
    // int arr[16];
    int *p = NULL; // типа 5 элемент

    for (int i = 0; i < 16; i++) {
        *(p - 5 + i) = 0;
    }

    return 0;
}
