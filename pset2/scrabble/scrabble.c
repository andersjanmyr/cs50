#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const int values[] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };

bool is_empty(string s) {
    return strlen(s) == 0;
}

int value_char(char c) {
    if (isalpha(c)) {
        return values[toupper(c) - 'A'];
    }
    return 0;
}

int value(string s) {
    int v = 0;
    for (int i = 0, l = strlen(s); i < l; i++)
       v += value_char(s[i]);
    return v;
}

int main(int argc, char *argv[])
{
    string word1 = "";
    string word2 = "";
    if (argc > 2) {
        word1 = argv[1];
        word2 = argv[2];
    }
    while (is_empty(word1) || is_empty(word2)) {
        word1 = get_string("Player 1: ");
        word2 = get_string("Player 2: ");
    }
    int v1 = value(word1);
    int v2 = value(word2);
    if (v1 == v2)
        printf("Tie!\n");
    else if (v1 > v2)
        printf("Player 1 wins!\n");
    else
        printf("Player 2 wins!\n");

}

