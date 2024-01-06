#include "../console_utils.h"

int main() {
    // Write a program in C that removes leading and trailing spaces from a string.
    char str[100], final_str[100];
    printf("Input a string: ");
    get_line(str, 100);

    int start = 0;
    while (str[start] == ' ') {
        start++;
    }

    int end = strlen(str) - 1;
    while (str[end] == ' ') {
        end--;
    }

    for (int i = start; i <= end; i++) {
        final_str[i - start] = str[i];
    }
    final_str[end + 1] = '\0';

    printf("The final string is: |%s|\n", final_str);
}
