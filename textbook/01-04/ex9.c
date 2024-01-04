#include "../console_utils.h"

int main() {
    char str[200], pat[20], new_str[300], rep_pat[100];
    int i = 0, j = 0, k, n = 0, copy_loop = 0, rep_index = 0;
    clrscr();
    printf("\n Enter the string : ");
    fgets(str, 200, stdin);
    printf("\n Enter the pattern to be replaced: ");
    fgets(pat, 20, stdin);
    printf("\n Enter the replacing pattern: ");
    fgets(rep_pat, 100, stdin);
    while (str[i] != '\0')
    {
        j = 0, k = i;
        while (str[k] == pat[j] && pat[j] != '\0')
        {
            k++;
            j++;
        }
        if (pat[j] == '\0' || pat[j] == '\n')
        {
            copy_loop = k;
            while (rep_pat[rep_index] != '\0' && rep_pat[rep_index] != '\n')
            {
                new_str[n] = rep_pat[rep_index];
                rep_index++;
                n++;
            }
        }
        new_str[n] = str[copy_loop];
        i++;
        copy_loop++;
        n++;
    }
    new_str[n] = '\0';
    printf("\n The new string is : ");
    puts(new_str);
}