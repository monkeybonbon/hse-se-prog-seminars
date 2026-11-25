long long mult(int a, int b) {
    return a * b; // может переполниться при умножении до перевода в long long
}

int main(void) {
    mult(1, 2);
    return 0;
}
