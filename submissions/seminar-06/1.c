void update(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
}

// Случай А:
int x = 3, y = 7;
update(&x, &y); // x = 10, y = 3

// Случай Б:
int x = 3;
update(&x, &x); // x = 0 (y не используется)
