// Значения в А: 10 3
// Значения в B: 0

void update(int *a, int *b);

void update(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
}

int main() {
    // int x = 3, y = 7;
    // update(&x, &y);
    int x = 3;
    update(&x, &x);
    printf("%d", x);
}