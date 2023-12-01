/*
    Description: Convert the text in the file passed as input to base64.
    Author: Nate Levin (12/1/23)
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifndef __cplusplus
#include <stdbool.h>
#endif

char base64Alphabet[64] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', /*  0 -  7 */
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', /*  8 - 15 */
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', /* 16 - 23 */
    'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', /* 24 - 31 */
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', /* 32 - 39 */
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', /* 40 - 47 */
    'w', 'x', 'y', 'z', '0', '1', '2', '3', /* 48 - 55 */
    '4', '5', '6', '7', '8', '9', '+', '/'  /* 56 - 63 */
};

char getbits(char x, int p, int n);

int main(int argc, char *argv[]) {
    FILE *file;
    char *buffer;
    long file_size;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the binary file in binary read mode
    file = fopen(argv[1], "rb");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Find the size of the file
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    // Allocate memory for the buffer to hold the file contents
    int bytesOver = file_size % 3;
    buffer = (char *)malloc(file_size + (3 - bytesOver));
    if (buffer == NULL) {
        perror("Memory allocation error");
        fclose(file);
        return 1;
    }

    // Read the file contents into the buffer
    if (fread(buffer, 1, file_size, file) != file_size) {
        perror("Error reading file");
        free(buffer);
        fclose(file);
        return 1;
    }

    // Close the file
    fclose(file);

    // ***** convert to base64 & print *****
    int iters = ceil(file_size / 3.0);
    for (long i = 0; i < iters; ++i) {
        bool isLast = i == iters - 1;
        
        int bufIndex = i * 3;
        char firstChar = (char)buffer[bufIndex];
        char secondChar = (char)buffer[bufIndex + 1];
        char thirdChar = (char)buffer[bufIndex + 2];
        char first = getbits(firstChar, 8, 6);
        char second = (getbits(firstChar, 2, 2) << 4) | getbits(secondChar, 8, 4);
        char third = (getbits(secondChar, 4, 4) << 2) | getbits(thirdChar, 8, 2);
        char fourth = getbits(thirdChar, 6, 6);

        printf("%c", base64Alphabet[first]);
        printf("%c", base64Alphabet[second]);
        if(isLast && bytesOver == 1) { // quantize
            printf("==");
            break; // end the loop, we've processed everything
        } else {
            printf("%c", base64Alphabet[third]);
        }
        if(isLast && bytesOver == 2) { // quantize
            printf("=");
        } else {
            printf("%c", base64Alphabet[fourth]);
        }
    }

    printf("\n");

    // Free the allocated memory
    free(buffer);

    return 0;
}

char getbits(char x, int p, int n)
{
    return (x >> (p - n)) & ~(~0 << n);
}