#include <stdio.h>
#include "../console_utils.h"
struct student
{
    int r_no;
    char name[20];
    char course[20];
    int fees;
};
int main() {
    struct student stud1, * ptr_stud1;
    clrscr();
    ptr_stud1 = &stud1;
    printf("\n Enter the details of the student :");
    printf("\n Enter the Roll Number =");
    scanf("%d%*c", &ptr_stud1->r_no);
    printf("\n Enter the Name = ");
    get_line(ptr_stud1->name, 20);
    printf("\n Enter the Course = ");
    get_line(ptr_stud1->course, 20);
    printf("\n Enter the Fees = ");
    scanf("%d%*c", &ptr_stud1->fees);
    printf("\n DETAILS OF THE STUDENT");
    printf("\n ROLL NUMBER = %d", ptr_stud1->r_no); printf("\n NAME = %s", ptr_stud1->name); printf("\n COURSE = %s", ptr_stud1->course); printf("\n FEES = %d", ptr_stud1->fees);
    return 0;
}