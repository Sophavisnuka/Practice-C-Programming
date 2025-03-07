#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
struct student {
    int id;
    char surname[100];
    char name[100];
    int age;
    char sex;
}s;
int studentNumber = 0;
void infoStudent (struct student s[100]) {
    printf("======== Student's information ========\n");
    again:
    printf("How many student do you want to input?(max = 100) => ");
    scanf("%d", &studentNumber);
    if (studentNumber > 100) {
        printf("Maximum size : 100\n");
        goto again;
    }
    for (int i = 0; i < studentNumber; i++) {
        printf("========= Student[%d]'s info ==========\n", i+1);
        printf("Input student's ID : ");
        scanf("%d", &s[i].id); fflush(stdin);
        printf("Input student's surname : ");
        scanf("%s", s[i].surname); fflush(stdin);
        printf("Input student name : ");
        scanf("%s", s[i].name); fflush(stdin);
        printf("Input student's age : ");
        scanf("%d", &s[i].age); fflush(stdin);
        printf("Student's Gender : ");
        scanf("%c", &s[i].sex); fflush(stdin);
        printf("---------------------------------------\n");
    }
    studentNumber++;
}
void deleteInfo (struct student s[100]) {
    int found = 0;
    int id;
    reInput:
    printf("Input the ID of the student's info you want to delete : ");
    scanf("%d", &id);
    found = 0;
    for (int i = 0; i < studentNumber; i++) {
        if (id == s[i].id) {
            found = 1;
            for (int j = i; j < studentNumber - 1; j++) {
                s[j] = s[j + 1];
            }
            studentNumber--;
            printf("Remove successfully\n");
        }
    }
    if (found == 0) {
        printf("This ID isn't exist\n");
        goto reInput;
    }
}
void displayInfo(struct student s[100]) {
    int check=0;
    int id;
    check = 0;
    putID:
    printf("Input ID of student you want to display : ");
    scanf("%d", &id);
    for (int i = 0; i < studentNumber ; i++) {
       if (id == s[i].id) {
        check = 1;
        printf("========= Student[%d]'s info ==========\n", i+1);
        printf("Input student's ID : %d\n", s[i].id);
        printf("Input student's surname : %s\n", s[i].surname);
        printf("Input student name : %s\n", s[i].name);
        printf("Input student's age : %d\n", s[i].age);
        printf("Student's Gender : %c\n", s[i].sex);
        printf("---------------------------------------\n");
       } 
    }
    if (check == 0) {
        printf("ID doesn't exist\n");
        goto putID;
    }
}
int main () {
    struct student s[100];
    int option;
    while (1) {
        system("cls");
        printf("1. Input student's information\n");
        printf("2. Delete student's information\n");
        printf("3. Display student's information\n");
        printf("0. Exit\n");
        printf("Select option : ");
        scanf("%d", &option);
        system("cls");
        switch(option) {
            case 1:
                infoStudent(s);
                break;
            case 2:
                deleteInfo(s);
                break;
            case 3:
                displayInfo(s);
                break;
            case 0:
                exit(8);
                break;
            default:
                printf("Invalid option\n");
                break;
        }
        printf("Press any key to go back...\n");
        getch();
    }
    return 0;
}