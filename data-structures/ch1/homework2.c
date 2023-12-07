#include <stdio.h>

// Write a program to read a floating point number.
// Display the rightmost digit of the integral part of the number.
int main() {
    float num;
    printf("Enter float: ");
    scanf("%f", &num);

    int integral_part = (int) num;
    int rightmost = integral_part % 10;
    printf("%d\n", rightmost);

    return 0;
}