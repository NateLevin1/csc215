#include "../console_utils.h"

int main() {
    char str[100];
    printf("Enter a string: ");
    get_line(str, 100);
    printf("You entered: %s", str);
}