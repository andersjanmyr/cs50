#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


bool is_empty(string s) {
    return strlen(s) == 0;
}

int count_letters(string s) {
    int v = 0;
    for (int i = 0, l = strlen(s); i < l; i++)
       if (isalpha(s[i])) v += 1;
    return v;
}

int count_words(string s) {
    int v = 1;
    for (int i = 0, l = strlen(s); i < l; i++)
       if (s[i] == ' ') v += 1;
    return v;
}

int count_sentences(string s) {
    int v = 0;
    for (int i = 0, l = strlen(s); i < l; i++)
       if (s[i] == '.' || s[i] == '!' || s[i] == '?') v += 1;
    return v;
}

int coleman_liau_index(float l, float s) {
    return round((0.0588 * l) - (0.296 * s) - 15.8);
}

int main(int argc, char *argv[])
{
    string text = "";
    if (argc > 1) {
        text = argv[1];
    }
    while (is_empty(text)) {
        text = get_string("Text: ");
    }
    float letter_count = (float)count_letters(text);
    float word_count = (float)count_words(text);
    float sentence_count = (float)count_sentences(text);
    float l = 100 * letter_count / word_count;
    float s = 100 * sentence_count / word_count;
    int cl_index = coleman_liau_index(l, s);
    if (cl_index < 1)
        printf("Before grade 1\n");
    else if (cl_index > 16)
        printf("Grade 16+\n");
    else
        printf("Grade %d\n", cl_index);
}

