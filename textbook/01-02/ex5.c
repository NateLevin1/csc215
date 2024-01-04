#include "../console_utils.h"
#include <string.h>

int main() {
    char str[100], reverse_str[100];
    int i = 0, j = 0;
    clrscr();
    printf("\n Enter the string : ");
    fgets(str, 100, stdin);
    j = strlen(str) - 1;
    while(i<j) {
        int temp = str[j];
        str[j] = str[i];
        str[i] = temp;
        i++;
        j--;
    }
    printf("\n The reversed string is : %s", str);
}