#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>
#include <ctype.h> 
//use struct to store variable
struct book {
    char bookName[100];
    char bookType[1000];
    char authorName[100];
    char phoneNumber[11];
    char bookId[1000];
};
struct student {
    char sName[100];
    char date[200];
    char sBookId[1000];
};
//just loading
void loading () {
    for (int i = 1; i <= 3; i++) {
        sleep(1);
        printf(".");
    }
}
//1.function view book
void viewBook() {
    char searchBookName[100];
    char buffer[1024];
    char searchBookID[1000];
    int select;
    int findBook = 0;
    //open txt file
    FILE*search;
    search = fopen("Add-book.txt", "r");
    back:
    printf("\033[0;33m------------ View books ------------\n\033[0m");
    printf("1. Search by book's Name\n");
    printf("2. Search by book's ID\n");
    printf("3. Show all books\n");
    printf("0. exit\n");
    printf("\nSelect => "); 
    scanf("%d", &select);
    fflush(stdin);
    system("cls");
    switch (select)
    {
        case 1: 
            printf("\033[0;33m\n<======= Search by book's name ======>\033[0m");
            printf("\nInput the book's name : "); 
            fgets(searchBookName,sizeof(searchBookName),stdin);
            searchBookName[strlen(searchBookName)-1]= '\0';
            printf("<------------------------------------>\n");
            findBook = 0;
            while (fgets (buffer, sizeof(buffer), search)) {
                if (strstr (buffer, searchBookName)) {
                    findBook = 1;
                    printf("%s", buffer);//printf name of the book you search
                    while (fgets (buffer, sizeof(buffer), search)) {
                        if (strcmp(buffer, "--------------------------------------\n") != 0) {
                            printf("%s", buffer);//printf information of search book
                        } else {
                            break; // break stop search
                        }
                    }
                }
            }
            if (findBook == 0) {
                printf("\033[0;31m\nNo information of that book!\n\033[0m");
            }
            break;
        case 2:
            printf("\033[0;33m\n<======= Search by book's ID ======>\033[0m");
            printf("\nInput ID of the book : "); 
            scanf("%s", &searchBookID);
            fflush(stdin);
            printf("<------------------------------------>\n");
            findBook = 0;
            while (fgets(buffer, sizeof(buffer), search)) {
                if (strstr(buffer, searchBookID)) { //strstr use for search
                    findBook = 1;
                    printf("%s", buffer);  // Print the book ID  
                    while (fgets (buffer, sizeof(buffer), search)) {
                        if (strcmp(buffer, "--------------------------------------\n") != 0) {
                            printf("%s", buffer);//printf information of search book
                        } else {
                            break; // break stop search
                        }
                    }
                }
            }
            if (findBook == 0) {
                printf("\033[0;31m\nNo information of that book!\n\033[0m");
            }
            break;
        case 3:
            printf("\033[0;33m\n<========== Show all book ===========>\033[0m");
            while (fgets(buffer, sizeof(buffer), search)) {
                printf("%s", buffer);
                findBook = 1;
            }
            if (findBook == 0) {
                printf("\033[0;31m\nNo information!\n\033[0m");
            }
            break;
        case 0:
            system("cls");
            break;
        default:
            printf("\033[0;31mInvalid option!\n\033[0m");
            goto back;
            break;
        fclose(search);
    }
}
//2.function add book
void addBook() {
    struct book b;
    char buf[1024];
    int checkID;
    FILE*a;
    a = fopen("Add-book.txt", "r");
    printf("\033[0;33m\n<====== Information to add new book =====>\n\033[0m");
    printf("Enter book name : "); 
    fgets(b.bookName, 100, stdin);
    b.bookName[strlen(b.bookName)-1]='\0';
    printf("Enter book id : "); 
    scanf("%s", &b.bookId);
    fflush(stdin);
    checkID = 1;
    while (fgets (buf, sizeof(buf), a)) {
        if (strstr (buf, b.bookId)) {
            checkID = 0;
        }
    }
    if (checkID == 0) {
        printf("\033[0;31mBook ID already exist\n\033[0m");
    } else {
        printf("Enter the type of book : "); 
        fgets(b.bookType, 1000, stdin);
        b.bookType[strlen(b.bookType)-1]='\0';
        printf("Enter author name : "); 
        fgets(b.authorName, 100, stdin);
        printf("\033[0;33m\nBook Added Successfully\033[0m");
        FILE*addBook;
        addBook = fopen("Add-book.txt", "a");
        //add book information 
        fprintf(addBook, "\n======= New book that just add =======\n");
        fprintf(addBook, "\nBook name : %s ID : %s", b.bookName, b.bookId);
        fprintf(addBook, "\nBook ID : %s", b.bookId);
        fprintf(addBook, "\nType of that book : %s", b.bookType);
        fprintf(addBook, "\nAuthor name : %s", b.authorName);
        fprintf(addBook, "\n--------------------------------------\n");
        fclose(addBook);
        //add book name to All-Book.txt
        FILE*addBookName;
        addBookName = fopen("All-Book.txt", "a");
        fprintf(addBookName, "\nBook name : %s", b.bookName);
        fclose(addBookName);
    }
}
//3.function for student who want to borrow books
void borrowBook() {
    struct book a;
    struct student s;
    char buffer4[1024];
    char bookName[1000];
    int find = 0;
    int digit;
    //read from the txt file and printf in terminal
    FILE*borrow, *read;
    borrow = fopen("Add-book.txt", "r");
    printf("\033[0;33m\n<----------- Your information ------------>\n\033[0m");
    printf("Enter your name : "); 
    fgets(s.sName, 100, stdin);
    s.sName[strlen(s.sName)-1]='\0';
    printf("Input the date that you borrow the book (Optional): "); 
    fgets(s.date, 200, stdin);
    s.date[strlen(s.date)-1]='\0';
    printf("Enter your phone number (Optional): "); 
    fgets(a.phoneNumber, 11, stdin);
    fflush(stdin);
    a.phoneNumber[strlen(a.phoneNumber)-1]='\0';
    printf("\n<-------------- Borrow Book -------------->\n");
    printf("ID of book (ex : 1) : ");  
    scanf("%s", s.sBookId);
    fflush(stdin);
    printf("Name of book : "); 
    fgets(bookName, 1000, stdin);
    //check if id input exist or not
    find = 0;
    while (fgets (buffer4, sizeof(buffer4), borrow)) {
        if (strstr (buffer4, s.sBookId)) {
            find = 1;
        }
    }
    //check the book name
    if (find == 0) {
        printf("\033[0;31mThis book doesn't exist in our list\n\033[0m");
    } else {
        bookName[strlen(bookName)-1]='\0';
        printf("Type of book : "); 
        fgets(a.bookType, 1000, stdin);
        a.bookType[strlen(a.bookType)-1]='\0';
        printf("\033[0;33mSuccessfully borrow the book\n\033[0m");
        //detail of students who borrow book will be at to the Borrow book txt
        read = fopen ("Borrow-book.txt", "a");
        fprintf(read, "\n<====== Detail of students who borrow the book ======>\n");
        fprintf(read, "\nName of students : %s", s.sName);
        fprintf(read, "\nDate that students borrow the book : %s", s.date);
        fprintf(read, "\nStudents phone number : %s", a.phoneNumber);
        fprintf(read, "\n<======================= Book =======================>\n");
        fprintf(read, "\nName of book : %s", bookName);
        fprintf(read, "\nID of book : %s", s.sBookId);
        fprintf(read, "\nType of book : %s", a.bookType);
        fprintf(read, "\n<---------------------------------------------------->\n");
        fclose(read);
    }
    fclose(borrow);
    // remove the book from the All-book txt when you borrow one book
    FILE*Remove, *temp;
    Remove = fopen ("All-Book.txt", "r");
    temp = fopen ("temp.txt", "w");
    char buffer6[1024];
    int found = 0;
    while (fgets(buffer6, sizeof(buffer6), Remove)) {
        // Check if the current line contains the book name
        if (strstr(buffer6, bookName) == 0) {
            fputs(buffer6, temp);
        } else {
            found = 1;
        }
    }
    fclose(Remove);
    fclose(temp);
    if (found) {
        remove("All-Book.txt");
        rename("temp.txt", "All-Book.txt");
    } else {
        // If no book name was found, remove the temporary file
        remove("temp.txt");
    }
}
//4. function return book
void returnBook() {
    struct book c;
    char studentName[100];
    char bookID[1000];
    char buffer2[1024];
    int found = 0;
    //read from the borrow book file
    FILE *borrowFile;
    borrowFile = fopen("Borrow-book.txt", "r");
    printf("------------------ Return books ------------------\n");
    printf("Enter your name : "); 
    fgets(studentName, 100, stdin);
    studentName[strlen(studentName) - 1]='\0';
    printf("Enter the book ID you are returning : "); 
    scanf("%s", &bookID);
    fflush(stdin);
    printf("Enter the name of the book you return : "); 
    fgets(c.bookName, 100, stdin);
    c.bookName[strlen(c.bookName) - 1] = '\0';
    printf("<------------------------------------------------->\n");
    found = 0;
    while (fgets (buffer2, sizeof(buffer2), borrowFile)) {
        if (strstr (buffer2, studentName)) {
            found = 1;
        }
    }
    if (found == 0) {
        printf("\033[0;31m\nNo information of that student!\n\033[0m");
    } else {
        printf("\033[0;35mReturning book successfully\n\033[0m");
        FILE *returnFile;
        returnFile = fopen("All-Book.txt", "a");
        fprintf(returnFile, "\nBook name : %s(Return by : %s)", c.bookName, studentName);
        fclose(returnFile);
    }
}
//5.function for show student Detail from the database
void detail () {
    char searchStudentName[100];
    char buffer1[1024];
    int option;
    int findDetail = 0;
    //read again and show it in terminal 
    FILE*detail;
    detail = fopen ("Borrow-book.txt", "r");
    rePut:
    printf("1. Search students name\n");
    printf("2. Show all student details\n");
    printf("0. exit\n");
    printf("Select any option => "); 
    scanf("%d", &option);
    fflush(stdin);
    system("cls");
    switch (option)
    {
        case 1:
            printf("\n<========== Search by student name =============>");
            printf("\nInput students name : "); 
            fgets(searchStudentName, 100, stdin);
            loading();
            system("cls");
            printf("\n<========== Search by student name =============>");
            printf("\nInput students name : %s", searchStudentName);
            printf("<----------------------------------------------->\n");
            findDetail = 0;
            while (fgets (buffer1, sizeof(buffer1), detail)) {
                if (strstr (buffer1, searchStudentName)) {
                    findDetail = 1;
                    printf("%s", buffer1);//printf name of the student you search
                    while (fgets (buffer1, sizeof(buffer1), detail)) {
                        if (strcmp(buffer1, "<====== Detail of students who borrow the book ======>\n") != 0) {
                            printf("%s", buffer1);//printf information of search book
                        } else {
                            break;//stop search
                        }
                    } 
                }
            }
            if (findDetail == 0) {
                printf("\033[0;31m\nNo information of that student!\n\033[0m");
            }
            break;
        case 2:
            printf("\n<========== Show all students detail ===========>");
            while (fgets(buffer1, sizeof(buffer1), detail)) {
                printf("%s", buffer1);
                findDetail = 1;
            } 
            if (findDetail == 0) {
                printf("\033[0;31m\nNo information!\n\033[0m");
            }
            break;
        case 0:
            system("cls");
            break;
        default:
            printf("\033[0;31m\nInvalid option\033[0m");
            goto rePut;
            break;
        fclose (detail);
    }
}
//main function
int main () {
    while (1) {
        system("cls");
        reInput:
        printf("\033[0;33m\n==================================================\n\033[0m");
        printf("\033[0;36m\n=------ Library management system project -------=\n\033[0m");
        printf("\033[0;33m\n==================================================\n\033[0m");
        printf("\033[0;36m\n\t      WELCOME TO OUR LIBRARY\n\033[0m");
        printf("\033[0;33m\n--------------------------------------------------\n\033[0m");
        int option;
        printf("\033[0;36m\n<-----Please choose any of this options below----->\n\n\033[0m");
        printf("1. View books\n");
        printf("2. Add books\n");
        printf("3. Borrow books\n");
        printf("4. Returning books\n");
        printf("5. Student details\n");
        printf("0.exit\n");
        printf("\nYour choice => ");
        scanf("%d", &option);
        fflush(stdin);
        system("cls");
        switch (option)
        {
            case 1:
                viewBook();
                break;
            case 2:
                addBook();
                break;
            case 3:
                borrowBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                detail();
                break;
            case 0:
                exit(8);
            default:
                printf("\033[0;31m\nInvalid option!\n\033[0m");
                goto reInput;
        }
        printf("\033[0;36m\nPress Any Key To Continue ===>\033[0m");
        getch();
    }
    return 0;
}