#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

long read_number() {
    return get_long("Number: ");
}

int digit_value(int n) {
    return (n % 10) + (n / 10);
}

int luhn_value(long cc) {
    int odds = 0;
    int evens = 0;
    while (cc > 0) {
        odds += cc % 10;
        cc /= 10;
        evens += digit_value((cc % 10) * 2);
        cc /= 10;
    }
    return (odds + evens) % 10;
}

/*
All American Express numbers start with 34 or 37; most MasterCard numbers start with 51, 52, 53, 54, or 55 (they also have some other potential starting numbers which we won’t concern ourselves with for this problem); and all Visa numbers start with 4.
}
 */
char *validate_card(long cc)
{
    int lv = luhn_value(cc);
    /* printf("%ld %d\n", cc, lv); */
    if (lv != 0) {
        return "INVALID";
    }
    while (cc > 99) cc /= 10;
    /* printf("cc: %ld\n", cc); */
    if (cc == 34 || cc == 37) return "AMEX";
    if (cc >= 51 && cc <= 55) return "MASTERCARD";
    cc /= 10;
    /* printf("cc: %ld\n", cc); */
    if (cc == 4) return "VISA";
    return "INVALID";
}


int main(int argc, char *argv[])
{
    long cc = 0;
    if (argc > 1) cc = atol(argv[1]);
    if (cc < 1) cc = read_number();
    char *card = validate_card(cc);
    printf("%s\n", card);
}

