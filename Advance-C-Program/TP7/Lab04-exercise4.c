#include <stdio.h>
#include <string.h>
struct DateOfBirth {
    int day;
    int month;
    int year;
};
struct student {
    char surname[100];
    char name[100];
    struct DateOfBirth DOB;
}s;
int main () {
    struct student s[10];
    int youngest = 0;
    int count = 0;
    for (int i = 0; i < 10; i++) {
        printf("---------- Student [%d] ----------\n", i+1);
        printf("Input student's surname : ");
        scanf("%s", s[i].surname); fflush(stdin);
        printf("Input student name : ");
        scanf("%s", s[i].name); fflush(stdin);
        printf("Input student date of birth :\n");
        printf("Year : ");
        scanf("%04d", &s[i].DOB.year); fflush(stdin);
        printf("Month : ");
        scanf("%02d", &s[i].DOB.month); fflush(stdin);
        printf("Day : ");
        scanf("%02d", &s[i].DOB.day); fflush(stdin);
        printf("----------------------------------\n");
        if (s[i].DOB.year <= 0 || s[i].DOB.month <= 0 || s[i].DOB.day <= 0) {
            printf("Date of birth can't be negative!\n");
            return 1;
        } 
        if ( s[i].DOB.month > 12) {
            printf("Month and Day can't be bigger than 12\n");
            return 1;
        } 
        if (s[i].DOB.month == 2) {
            // leap year
            if (s[i].DOB.year % 4 == 0 && s[i].DOB.year % 100 != 0 || s[i].DOB.year % 400 == 0) {
                if (s[i].DOB.day > 29) {
                    printf("Day in February can be bigger than 29 in leap year\n");
                    return 1;
                }
            } else {
                if (s[i].DOB.day > 28) {
                    printf("Day can't be bigger than 28 in February if it isn't leap year\n");
                    return 1;
                }
            }
        } else if (s[i].DOB.month == 4 || s[i].DOB.month == 6 || s[i].DOB.month == 9 || s[i].DOB.month == 11) {
            if (s[i].DOB.day > 30) {
                printf("In April, June, September, November there are only 30days\n");
                return 1;
            }
        } else {
            if (s[i].DOB.day > 31) {
                printf("There are only 30days\n");
                return 1;
            }
        }
    }
    int youngestYear = s[0].DOB.year;
    int youngestMonth = s[0].DOB.month;
    int youngestDay = s[0].DOB.day;
    for (int i = 0; i < 10; i++) {
        if (s[i].DOB.year  > s[youngest].DOB.year)
        {
            youngest = i;
        } else if (s[i].DOB.year == s[youngest].DOB.year) {
            if (s[i].DOB.month > s[youngest].DOB.month) {
                youngest = i;
            }
        } else if (s[i].DOB.month == s[youngest].DOB.month) {
            if (s[i].DOB.day > s[youngest].DOB.day) {
                youngest = i;
            }
        } else if (s[i].DOB.year == s[youngest].DOB.year && s[i].DOB.month == s[youngest].DOB.month && s[i].DOB.day == s[youngest].DOB.day) {
            youngestYear = s[i].DOB.year;
            youngestMonth = s[i].DOB.month;
            youngestDay = s[i].DOB.day;
        }
    }
    for (int i = 0; i < 10; i++) {
        if (youngest == i) {
            printf("----------------------------------\n");
            printf("======== Youngest student ========");
            printf("Surname : %s\n", s[i].surname);
            printf("Student name : %s\n", s[i].name);
            printf("========= Date of birth ==========\n");
            printf("Year : %04d\n", s[i].DOB.year);
            printf("Month : %02d\n", s[i].DOB.month);
            printf("Day : %02d\n", s[i].DOB.day);
        } 
    }
    for (int i = 0; i < 10; i++) {
        if (youngestYear == s[i].DOB.year || youngestMonth == s[i].DOB.month || youngestDay == s[i].DOB.day) {
            printf("----------------------------------\n");
            printf("======== Youngest student ========");
            printf("Surname : %s\n", s[i].surname);
            printf("Student name : %s\n", s[i].name);
            printf("========= Date of birth ==========\n");
            printf("Year : %04d\n", s[i].DOB.year);
            printf("Month : %02d\n", s[i].DOB.month);
            printf("Day : %02d\n", s[i].DOB.day);
        } 
    }
    return 0;
}