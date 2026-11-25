#include <stdio.h>

void process(int n) {
    if (n <= 0) // Базовый случай: остановка при n <= 0
        return;

    printf("A%d ", n); // Прямой ход: вывод до вызова
    process(n - 2);    // Рекурсивный вызов с шагом -2
    printf("B%d ", n); // Обратный ход: вывод после возврата
}

int main(void) {
    process(5); // Вывод: A5 A3 A1 B1 B3 B5 
    return 0;
}
