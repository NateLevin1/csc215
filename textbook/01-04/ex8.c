#include "../console_utils.h"

int main() {
    char text[200], str[20], new_text[200];
    int i = 0, j = 0, found = 0, k, n = 0, copy_loop = 0;
    clrscr();
    printf("\n Enter the main text: ");
    fgets(text, 200, stdin);
    printf("\n Enter the string to be deleted: ");
    fgets(str, 20, stdin);
    while (text[i] != '\0')
    {
        j = 0, found = 0, k = i;
        while (text[k] == str[j] && str[j] != '\0')
        {
            k++;
            j++;
        }
        if (str[j] == '\0' || str[j] == '\n')
            copy_loop = k;
        new_text[n] = text[copy_loop];
        i++;
        copy_loop++;
        n++;
    }
    new_text[n] = '\0'; // NOTE: book originally said new_str
    printf("\n The new string is : ");
    printf("%s", new_text);
}
