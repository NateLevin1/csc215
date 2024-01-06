#include "../console_utils.h"

int main() {
    // Write a program in C that replaces a given character with another character in a string
    char str[100], c1, c2;
    printf("Input a string: ");
    get_line(str, 100);
    printf("Input the character to replace: ");
    scanf("%c", &c1);
    printf("Input the character to replace with: ");
    scanf(" %c", &c2);

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == c1) {
            str[i] = c2;
        }
    }

    printf("The final string is: %s\n", str);
}
