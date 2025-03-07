#include <stdio.h>
struct student {
    char surname[100];
    char name[100];
    int age;
}s;
int main () {
    int minAge = 0;
    struct student s[10];
    for (int i = 0; i < 10; i++) {
        printf("------- Student [%d] -------\n", i+1);
        printf("Input student's surname : ");
        scanf("%s", s[i].surname);
        fflush(stdin);
        printf("Input student name : ");
        scanf("%s", s[i].name);
        fflush(stdin);
        printf("Input student age : ");
        scanf("%d", &s[i].age);
        printf("---------------------------\n");
    }
    //find the youngest age
    minAge = s[0].age;
    for (int i = 0; i < 10; i++) {
        if (minAge > s[i].age) {
            minAge = s[i].age;
        }
    }
    for (int i = 0; i < 10; i++) {
        if (minAge == s[i].age) {
            printf("-----------------------------------\n");
            printf("The youngest student is %d year old\n", minAge);
            printf("Surname : %s\n", s[i].surname);
            printf("Student name : %s\n", s[i].name);
            printf("Student age : %d\n", s[i].age);
        }
    }
    return 0;
}