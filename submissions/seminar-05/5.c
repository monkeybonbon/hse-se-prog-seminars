int a[10];

size_t count =
    sizeof(a) / sizeof(int); /* я только не совсем понял в чём сложность ну если
                                бы не было написано инт или не дано а я бы
                                наверное написал sizeof(a) / sizeof(a[0])*/

printf("%zu\n", count)
