#include <stdio.h>
#include <stdlib.h>
#include "../console_utils.h"
struct student
{
    int r_no;
    char name[20];
    char course[20];
    int fees;
};
struct student* ptr_stud[10];
int main() {
    int i, n;
    printf("\n Enter the number of students : ");
    scanf("%d%*c", &n);
    for (i = 0;i < n;i++)
    {
        ptr_stud[i] = (struct student*)
            malloc(sizeof(struct student));
        printf("\n Enter the data for student %d ", i + 1);
        printf("\n ROLL NO.: ");
        scanf("%d%*c", &ptr_stud[i]->r_no);
        printf("\n NAME: ");
        get_line(ptr_stud[i]->name, 20);
        printf("\n COURSE: ");
        get_line(ptr_stud[i]->course, 20);
        printf("\n FEES: ");
        scanf("%d%*c", &ptr_stud[i]->fees);
    }
    printf("\n DETAILS OF STUDENTS");
    for (i = 0;i < n;i++)
    {
        printf("----------");
        printf("\n ROLL NO. = %d", ptr_stud[i]->r_no);
        printf("\n NAME = %s", ptr_stud[i]->name);
        printf("\n COURSE = %s", ptr_stud[i]->course);
        printf("\n FEES = %d", ptr_stud[i]->fees);
    }
    return 0;
}