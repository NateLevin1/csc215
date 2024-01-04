#include "../console_utils.h"
#include <string.h>

int main() {
    char str1[100], str2[100];
    int i =0, len1=0, len2=0, same=0;
    clrscr();
    printf("\n Enter the first string : ");
    fgets(str1, 100, stdin);
    printf("\n Enter the second string : ");
    fgets(str2, 100, stdin);
    len1 = strlen(str1);
    len2 = strlen(str2);
    if(len1 == len2) {
        while(i < len1) {
            if(str1[i] == str2[i]) {
                i++;
            } else {
                break;
            }
        }
        if(i == len1) {
            same = 1;
            printf("\n The two strings are equal");
        }
    }
    if(same == 0) {
        printf("\n The two strings are not equal");
        if(str1[i] > str2[i]) {
            printf("\n The first string is greater than the second string");
        } else {
            printf("\n The second string is greater than the first string");
        }
    }
    getch();
}