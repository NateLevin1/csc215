#include "../console_utils.h"

int main() {
    // Write a program to count the total number of occurrences of a word in the text.
    char text[100], word[20];
    printf("Input a text: ");
    get_line(text, 100);
    printf("Input the word to count: ");
    get_line(word, 20);

    int count = 0;
    for (int i = 0; i < strlen(text); i++) {
        int j = 0;
        for (j = 0; j < strlen(word); j++) {
            if (text[i + j] != word[j]) {
                break;
            }
        }
        if (j == strlen(word)) {
            count++;
        }
    }

    printf("'%s' occurs %d times in the text.\n", word, count);
}
