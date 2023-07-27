#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool is_alpha(string s) {
    if (strlen(s) == 0) return false;
    for (int i = 0, l = strlen(s); i < l; i++)
       if(!isalpha(s[i])) return false;
    return true;
}

int main(int argc, char *argv[])
{
    string word1 = "";
    string word2 = "";
    if (argc > 2) {
        word1 = argv[1];
        word2 = argv[2];
    }
    while (!is_alpha(word1) && !is_alpha(word2)) {
        word1 = get_string("Player 1: ");
        word2 = get_string("Player 2: ");
    }
    printf("%s:%s\n", word1, word2);
}

