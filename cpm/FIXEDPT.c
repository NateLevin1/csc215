/* compile & run with: A:SUBMIT FPT */
#include <stdio.h>
#define FPTBTS 7
#define FPTMSK 127
#define FPTMAX 100
#define MAXNUMLEN 8

/*
    max integer value = 511
    max decimal value = 99
*/

FixedPoint(integer, decimal)
int integer;
int decimal;
{
    integer = integer << FPTBTS;
    integer += decimal & FPTMSK;
    return integer;
}

f_gdec(num)
int num;
{
    return num & FPTMSK;
}

f_gint(num) {
    return num >> FPTBTS;
}

f_add(num1, num2)
int num1;
int num2;
{
    int integer1, integer2, decimal1, decimal2;
    integer1 = f_gint(num1);
    integer2 = f_gint(num2);
    decimal1 = f_gdec(num1);
    decimal2 = f_gdec(num2);
    /* Add the integers, then add the decimals, then handle decimal overflow */
    integer1 += integer2;
    decimal1 += decimal2;
    if (decimal1 >= FPTMAX) {
        integer1++;
        decimal1 -= FPTMAX;
    }
    return FixedPoint(integer1, decimal1);
}

f_sub(num1, num2)
int num1;
int num2;
{
    int integer1, integer2, decimal1, decimal2;
    integer1 = f_gint(num1);
    integer2 = f_gint(num2);
    decimal1 = f_gdec(num1);
    decimal2 = f_gdec(num2);
    if(integer1 < integer2) {
        return FixedPoint(0, 0);
    }
    /* Subtract the integers, then subtract the decimals, then handle decimal underflow */
    integer1 -= integer2;
    decimal1 -= decimal2;
    if (decimal1 < 0) {
        integer1--;
        decimal1 += FPTMAX;
    }
    return FixedPoint(integer1, decimal1);
}

f_mult(num1, num2)
int num1;
int num2;
{
    int integer1, integer2, decimal1, decimal2;
    integer1 = f_gint(num1);
    integer2 = f_gint(num2);
    decimal1 = f_gdec(num1);
    decimal2 = f_gdec(num2);
    /*
        Algorithm:
        d_f = (i1 * d2) + (i2 * d1) + (d1 * d2) / FPTMAX
        i_f = i1 * i2 + d_f / FPTMAX
        d_f = decimal % FPTMAX
   */
    decimal1 = (integer1 * decimal2) + (integer2 * decimal1) + (decimal1 * decimal2) / FPTMAX;
    integer1 = integer1 * integer2 + decimal1 / FPTMAX;
    decimal1 = decimal1 % FPTMAX;
    return FixedPoint(integer1, decimal1);
}

f_div(num1, num2)
int num1;
int num2;
{
    int integer1, integer2, decimal1, decimal2, numerator, denominator;
    integer1 = f_gint(num1);
    integer2 = f_gint(num2);
    decimal1 = f_gdec(num1);
    decimal2 = f_gdec(num2);
    /*
        Algorithm:
        numerator = (i1 * FPTMAX + d1)
        denominator = (i2 * FPTMAX + d2)
        i_f = numerator / denominator
        d_f = numerator % denominator * 100 / denominator
    */
    numerator = integer1 * FPTMAX + decimal1;
    denominator = integer2 * FPTMAX + decimal2;
    integer1 = numerator / denominator;
    decimal1 = numerator % denominator * 100 / denominator;
    return FixedPoint(integer1, decimal1);
}

fixed_print(num)
int num;
{
    printf("%d.%02d\n", f_gint(num), f_gdec(num));
}

f_askuser() {
    printf("Enter a number: ");
    int c, i;
    i = 0;
    int integer, decimal;
    integer = 0;
    decimal = 0;
    int decimalStart;
    decimalStart = 0;
    for (c = getchar(); c != 10 && i < MAXNUMLEN; c = getchar(), i++) {
        if (c == '.') {
            decimalStart = i;
            continue;
        }
        if(decimalStart == 0) {
            integer *= 10;
            integer += c - '0';
        } else {
            /*
                Ideally, we would use:
                decimal += (c - '0') * pow(10, decimalStart - i + 2);

                But since we can assume that the user will only be able to enter 2 decimal places,
                we can just use a branch, which will be faster:
            */
            if(i == decimalStart + 1) {
                decimal += (c - '0') * 10;
            } else if(i == decimalStart + 2) {
                decimal += (c - '0');
            } else {
                printf(" (too many characters, skipping last)\n");
                break;
            }
        }
    }
    return FixedPoint(integer, decimal);
}


main() {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\nFIXEDPT.C Testing Program\n\n");

    printf("\n");

    int continueChar;
    int num;
    num = f_askuser();

    for(;;) {
        printf("Enter an operation (+,-,*,/,=,q): ");
        char operation;
        operation = getchar();
        printf("\n");
        if(operation == '+') {
            num = f_add(num, f_askuser());
        } else if(operation == '-') {
            num = f_sub(num, f_askuser());
        } else if(operation == '*') {
            num = f_mult(num, f_askuser());
        } else if(operation == '/') {
            num = f_div(num, f_askuser());
        } else if(operation == '=') {
            num = f_askuser();
        } else if(operation == 'q') {
            return 0;
        } else {
            printf("Unknown operation '%c'\n", operation);
            return 1;
        }

        printf("Result: ");
        fixed_print(num);
        printf("\n");
    }
}