#include <stdio.h>
struct student {
    int score;
    char id[100];
    char name[100];
}s;
int main () {
    int studentNum;
    printf("How many student's record you want to put : ");
    scanf("%d", &studentNum);
    fflush(stdin);
    struct student s[studentNum];
    for (int i = 0; i < studentNum; i++) {
        printf("Input student name : ");
        scanf("%s", s[i].name);
        fflush(stdin);
        printf("Input student ID : ");
        scanf("%d", s[i].id);
        fflush(stdin);
        printf("Input student score : ");
        scanf("%d", s[i].score);
        fflush(stdin);
        printf("---------------------\n");
    }
    for (int i = 0; i < studentNum; i++) {
        printf("---------------------\n");
        printf("Show All student record\n");
        printf("Input student name : %s\n", s[i].name);
        printf("Input student ID : %d\n", s[i].id);
        printf("Input student score : %d\n", s[i].score);
        printf("---------------------\n");
    }
    return 0;
}