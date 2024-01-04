#include "../console_utils.h"

int main() {
    char text[100], str[20], ins_text[120];
    int i = 0, j = 0, k = 0, pos;
    clrscr();
    printf("\n Enter the main text: ");
    fgets(text, 100, stdin);
    printf("\n Enter the string to be inserted: ");
    fgets(str, 20, stdin);
    printf("\n Enter the position at which the string has to be inserted: ");
    scanf("%d", &pos);
    while (text[i] != '\0')
    {
        if (i == pos) {
            while (str[k] != '\0') {
                ins_text[j] = str[k];
                j++;
                k++;
            }
        }
        else {
            ins_text[j] = text[i];
            j++;
        }
        i++;
    }
    ins_text[j] = '\0';
    printf("\n The new string is: ");
    printf("%s", ins_text);
    getch();
}