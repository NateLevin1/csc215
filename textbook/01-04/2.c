#include "../console_utils.h"

int main() {
    // Write a program in C to concatenate first n characters of a string with another string.
    char str1[100], str2[100], final_str[200];
    int n;

    printf("Input the first string: ");
    get_line(str1, 100);
    printf("Input the second string: ");
    get_line(str2, 100);

    printf("Input the number of characters to concatenate: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        final_str[i] = str1[i];
    }

    for (int i = 0; i < strlen(str2); i++) {
        final_str[n + i] = str2[i];
    }
    final_str[n + strlen(str2)] = '\0';

    printf("The concatenated string is: %s\n", final_str);
}
