/*
Author: Edward Welch 

Date: 9 November 2023

Description:
   This program is a solution to Exercise 2-7 from The C Programming Language,
   2nd Edition, by Brian kernighan and Dennis Ritchie.

   The task is to write a function invert(x, p, n) that returns x with n bits
   that begin a position p (starting with 0) inverted, leaving other bits
   unchanged.

Example:
   The unsigned short 169 will be stored in binary as 10101001. Calling
   invert(169, 5, 3) should return 10010001, or 145. It does this by
   creating a mask in two steps: first set the low order n bits to 1, leaving
   the other bits 0 (using ~(~0 << n)), and then left shifting these 1 bits
   by p. The resulting mask in this example will be 00111000.  Using the
   bitwise exclusive or (^) operator "flips the bits" wherever there are
   1s in the mask (since 0 ^ 1 is 1 and 1 ^ 1 is 0), while leaving the byte
   unchanged where there are 0s in the mask (1 ^ 0 is 1 and 0 ^ 0 is 0). 
*/
#include <stdio.h>
#include "bit_tools.h"

unsigned char invert(unsigned char x, unsigned char p, unsigned char n) {
    return x ^ (~(~0 << n) << (p + 1 - n));
}

void break_it_down(unsigned char x, char p, char n) {
    unsigned char mask = ~(~0 << n) << (p + 1 - n);
    printf("Before    mask      After\n");
    print_binary_byte(x);
    printf("  ");
    print_binary_byte(mask);
    printf("  ");
    print_binary_byte(invert(x, p, n));
    printf("\n");
}

int main() {
    unsigned char before = 169;
    unsigned char after = invert(before, 5, 3);
    printf(
        "Flipping %u bits staring at position %u turns % u into %u.\n",
        3,
        5,
        169,
        invert(169, 5, 3)
    );
    break_it_down(169, 5, 3);

    return 0;
}