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
void display(struct student*);
int main() {
    struct student* ptr;
    ptr = (struct student*)malloc(sizeof(struct student));
    printf("\n Enter the data for the student ");
    printf("\n ROLL NO.: ");
    scanf("%d%*c", &ptr->r_no);
    printf("\n NAME: ");
    get_line(ptr->name, 20);
    printf("\n COURSE: ");
    get_line(ptr->course, 20);
    printf("\n FEES: ");
    scanf("%d%*c", &ptr->fees);
    display(ptr);

    return 0;
}
void display(struct student* ptr) {
    printf("\n DETAILS OF STUDENT");
    printf("\n ROLL NO. = %d", ptr->r_no);
    printf("\n NAME = %s", ptr->name);
    printf("\n COURSE = %s ", ptr->course);
    printf("\n FEES = %d", ptr->fees);
}