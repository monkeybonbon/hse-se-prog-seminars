#include <stdio.h>

int main(void) {
  int matrix[3][4];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
  int r_sum;
  int c_sum;
  printf("Суммы строк:");
  for (int k = 0; k < 3; k++) {
    r_sum = 0;
    for (int l = 0; l < 4; l++) {
      r_sum += matrix[k][l];
    }
    printf(" %d", r_sum);
  }
  printf("\n");
  printf("Суммы столбцов:");
  for (int j = 0; j < 4; j++) {
    c_sum = 0;
    for (int i = 0; i < 3; i++) {
      c_sum += matrix[i][j];
    }
    printf(" %d", c_sum);
  }
  return 0;
}
