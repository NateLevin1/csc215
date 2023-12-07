#include <stdio.h>

// Write a program to read an integer.
// Display the value of that integer in decimal, octal, and hexadecimal notation.
int main() {
    int num;
    printf("Enter integer: ");
    scanf("%d", &num);

    printf("Decimal: %d\n", num);
    printf("Octal: %o\n", num);
    printf("Hex: %x\n", num);
}