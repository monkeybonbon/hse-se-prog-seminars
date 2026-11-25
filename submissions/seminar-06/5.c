unsigned digit_sum(unsigned n) {
    if (n == 0)
        return 0;

    return n % 10 + digit_sum(n / 10);
}

int main (void){

    digit_sum(123321);

    return 0;
}