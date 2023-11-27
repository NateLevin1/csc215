/*
Author: Julissa Hernandez 

Date: 9 November 2023

Description:
*/
#include <stdio.h>

/*rightrot:  rotates x to the right by n bit positions */
unsigned char rightrot(unsigned char x, unsigned char n)
{
    while (n > 0) {
        if(x & 1)   /* rightmost bit of x is 1 */
            x = (x >> 1) | 128;
        else        /* rightmost bit of x is 0 */
            x = x >> 1;
        --n;
    }
    return x;
}

int main()
{
    printf("%u\n", rightrot(1, 1));
    return 0;
}