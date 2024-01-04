#include "../console_utils.h"

int main() {
    char dest_str[100], source_str[100];
    int i = 0, j = 0;
    clrscr();
    printf("\n Enter the source string : ");
    fgets(source_str, 100, stdin);
    printf("\n Enter the destination string : ");
    fgets(dest_str, 100, stdin);
    while(dest_str[i] != '\0' && dest_str[i] != '\n') {
        i++;
    }
    while(source_str[j] != '\0' && source_str[j] != '\n') {
        dest_str[i] = source_str[j];
        i++;
        j++;
    }
    dest_str[i] = '\0';
    printf("\n After appending, the destination string is : %s\n", dest_str);
    getch();
}
