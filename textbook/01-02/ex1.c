#include "../console_utils.h"

int main() {
    char str[100], i = 0, length;
    clrscr();
    printf("\n Enter the string : ");
    fgets(str, 100, stdin);
    while(str[i] != '\0' && str[i] != '\n') {
        i++;
    }
    length = i;
    printf("\n The length of this string is : %d", length);
    getch();
    return 0;
}