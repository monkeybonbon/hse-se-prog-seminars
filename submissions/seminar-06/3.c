#include <stdio.h>

int mystery(int n)
{
    if (n <= 1)
        return 1;

    int a = mystery(n - 1);
    return a + n;
}

int main(void)
{
    // 1. Всего 4 вызова: mystery(4), mystery(3), mystery(2), mystery(1).
    // 2. Максимальная глубина: 4 одновременно активных вызова.
    // 3. При возврате: для n = 2 получаем a = 1, для n = 3 получаем a = 3,
    //    для n = 4 получаем a = 6. При n = 1 функция сразу возвращает 1.
    // 4. Первоначальный вызов возвращает 6 + 4 = 10.
    printf("%d\n", mystery(4));
    return 0;
}
