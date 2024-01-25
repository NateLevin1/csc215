#include <stdio.h>
#include <string.h>
#include "../console_utils.h"

int main() {
    struct student
    {
        int roll_no;
        char name[80];
        int fees;
        char DOB[80];
    };
    struct student stud[50];
    int n, i, num, new_rolno;
    int new_fees;
    char new_DOB[80], new_name[80];

    printf("\n Enter the number of students: ");
    scanf("%d%*c", &n);
    for (i = 0;i < n && i < 50; i++)
    {
        printf("\n Enter the roll number: ");
        scanf("%d%*c", &stud[i].roll_no);
        printf("\n Enter the name: ");
        get_line(stud[i].name, 80);
        printf("\n Enter the fees: ");
        scanf("%d%*c", &stud[i].fees);
        printf("\n Enter the DOB: ");
        get_line(stud[i].DOB, 80);
    }
    for (i = 0;i < n;i++)
    {
        printf("\n ********DETAILS OF STUDENT %d*******", i + 1);
        printf("\n ROLL No. = %d", stud[i].roll_no);
        printf("\n NAME = %s", stud[i].name);
        printf("\n FEES = %d", stud[i].fees);
        printf("\n DOB = %s", stud[i].DOB);
    }
    printf("\n Enter the student number whose record has to be edited: ");
    scanf("%d%*c", &num);
    num = num - 1;
    printf("\n Enter the new roll number: ");
    scanf("%d%*c", &new_rolno);
    printf("\n Enter the new name: ");
    get_line(new_name, 80);
    printf("\n Enter the new fees: ");
    scanf("%d%*c", &new_fees);
    printf("\n Enter the new DOB: ");
    get_line(new_DOB, 80);
    stud[num].roll_no = new_rolno;
    strcpy(stud[num].name, new_name);
    stud[num].fees = new_fees;
    strcpy(stud[num].DOB, new_DOB);
    for (i = 0;i < n;i++)
    {
        printf("\n ******** DETAILS OF STUDENT %d *******", i + 1);
        printf("\n ROLL No. = %d", stud[i].roll_no);
        printf("\n NAME = %s", stud[i].name);
        printf("\n FEES = %d", stud[i].fees);
        printf("\n DOB = %s", stud[i].DOB);
    }

    return 0;
}