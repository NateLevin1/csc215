/*
Author: Cyrus Haywood 

Date: 9 November 2023

Description:
    Counts the number of "on" (1) bits in a number.

    x &= (x-1) removes the low order 1 bit because if you have a number such
    as 1101 (13) it will set x to the result of a bitwise and with 1100 (12)
    giving the result 1100 (12) If we do this again, we set x to 1100 (12) &
    1011 (11) which gives 1000 As you can see, this removes the last bit with
    the value of '1'

    The orginal version of this function:

        int bitcount(unsigned x){
            int b;
            for (b = 0; x != 0; x >>= 1)
                if (x & 01)
                    b++;
            return b;
        }

    works, but is less efficient, since it needs to run an iteration of the
    loop for each bit, where the improved version here only needs to iterate
    for each 1 bit being counted.
*/
#include <stdio.h>

int bitcount(unsigned char x) {
    unsigned char b;
    
    // count each 1 in the input (binary)
    for (b = 0; x != 0; x &= (x-1))
        b++;
    
    return b;
}

int main() {
    unsigned char input;
    
    while (true) {
        // user input for easier demonstration
        scanf("%d", &input);
        
        // print output with easier to read format
        printf("The 1 bitcount for %d is %d.\n", input, bitcount(input));
    }

    return 0;
}