#include "../console_utils.h"

int main() {
    // Write a program to count the total number of occurrences of a given character in the string.
    char str[100], c;
    printf("Input a string: ");
    get_line(str, 100);
    printf("Input the character to count: ");
    scanf("%c", &c);

    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == c) {
            count++;
        }
    }

    printf("%c occurs %d times in the string.\n", c, count);
}
