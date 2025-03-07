#include <stdio.h>
#include <string.h>
struct student {
    char name[100];
    char id[100];
    float mark;
}s;
int main () {
    int studentNum;
    float maxMark = 0;
    printf("How many students do want to input the record? => ");
    scanf("%d", &studentNum); 
    fflush(stdin);
    struct student s[studentNum];
    for (int i = 0; i < studentNum; i++) {
        printf("------------ Student[%d] -------------\n", i+1);
        printf("Input student name : ");
        gets(s[i].name);
        fflush(stdin);
        printf("Input student's ID : ");
        scanf("%s", s[i].id); 
        fflush(stdin);
        reInput:
        printf("Input student's mark (0.0 to 100) : ");
        scanf("%f", &s[i].mark);
        fflush(stdin);
        if (s[i].mark < 0 || s[i].mark > 100) {
            printf("Student's mark should be from 0.0 to 100\n");
            goto reInput;
        }
        printf("-------------------------------------\n");
    }
    printf("=====================================\n");
    maxMark = s[0].mark;
    for (int i = 0; i < studentNum; i++) {
        if (maxMark < s[i].mark) {
            maxMark = s[i].mark;
        }
    }
    printf("\n------- Highest mark student --------\n");
    for (int i = 0; i <studentNum; i++) {
        if (maxMark == s[i].mark) {
            printf("------------- Student[%d] -------------\n", i+1);
            printf("Student name : %s\n", s[i].name);
            printf("Student's ID : %s\n", s[i].id);
            printf("Student's mark : %.1f\n", s[i].mark);
            printf("---------------------------------------\n");
        }
    }
    return 0;
}