#include <stdio.h>
#include "homework1.h"
#include <stdbool.h>

bool is_vowel(char ch)
{
    bool vowel = false;

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        vowel = true;
    }
    else if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
        vowel = true;
    }

    return vowel;
}

int num_vowels(char s[])
{
    int count = 0;

    int i = 0;
    while(s[i] != '\0') {
        if (is_vowel(s[i])) {
            count++;
        }
        i++;
    }
    return count;
}