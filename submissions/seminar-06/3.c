int mysrety(int n) {
    if (n <= 1)
        return 1;

    int a = mystery(n-1);
    return a + n;
}
/*
mystery(4) => mystery(3) => mystery(2) => mystery(1)
Максимальная глубина 4 вызова
При n = 1 сразу возвращается единица 
При n = 2 a=1 Выводится 3
При n = 3 a=3 Выводится 6
При n = 4 a=6 Выводится 10
При 
*/