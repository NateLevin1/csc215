#include "../console_utils.h"

int main() {
    // Write a program in C that compares first n characters of one string with first n characters of another string
    char str1[100], str2[100];
    int n;

    printf("Input the first string: ");
    get_line(str1, 100);
    printf("Input the second string: ");
    get_line(str2, 100);

    printf("Input the number of characters to compare: ");
    scanf("%d", &n);

    int i;
    for (i = 0; i < n; i++) {
        if (str1[i] != str2[i]) {
            break;
        }
    }

    if (i == n) {
        printf("The first %d characters of the two strings are equal.\n", n);
    } else {
        printf("The first %d characters of the two strings are not equal.\n", n);
    }
}
