/*
Author: Jeffrey Elkner 

Date: 13 November 2023

Description:
    A collection of functions useful for writing and debugging functions
    using bitwise operators.
*/
#include <stdio.h>

void print_binary_byte(unsigned char n) {
    unsigned short mask = 128;
    while (mask > 0) {
        printf("%c", ((n & mask) == 0) ? '0' : '1');
        mask = mask >> 1;
    }
}

void print_binary_short(unsigned short n) {
    unsigned short mask = 32768;
    while (mask > 0) {
        printf("%c", ((n & mask) == 0) ? '0' : '1');
        mask = mask >> 1;
    }
}