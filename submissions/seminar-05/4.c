#include <stdio.h>

int main(void)
{
    int b[4][5];
    int *p = &b[2][1], *q = &b[3][4];
    printf("+--------------+-------+\n");
    printf("| Expression   | Value |\n");
    printf("+--------------+-------+\n");
    printf("| q - (int *)b | %5td |\n", q - (int *)b);
    printf("| p - (int *)b | %5td |\n", p - (int *)b);
    printf("| p - q        | %5td |\n", p - q);
    printf("+--------------+-------+\n");

    return 0;
}
