#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main () {
    FILE *b, *c, *d;
    char fileName[100], newFile[100], thirdFile[100];
    //input name of source file
    printf("Input source file name : ");
    scanf("%s", fileName);
    b = fopen(fileName, "r");
    //check if the source file exist or not
    if (b == NULL) {
        printf("Error! No source file!");
        exit(8);
    } else {
        printf("Read successfully!\n");
    }
    //input the name of new file
    printf("\nInput new file name : ");
    scanf("%s", newFile);
    c = fopen (newFile, "r");
    if (c == NULL) {
        printf("Error! No source file!");
        exit(8);
    } else {
        printf("Read successfully!\n");
    }
    //input the name of another file name
    printf("\nInput another file name : ");
    scanf("%s", thirdFile);
    d = fopen (thirdFile, "w");
    char text[sizeof(b)];
    while (fgets(text, sizeof(b), b)) {
        printf("%s", text);
        fputs(text, d);
    }
    fprintf(d, "\n");
    printf("\n");
    while (fgets(text, sizeof(c), c)) {
        printf("%s", text);
        fputs(text, d);
    }
    fclose(d);
    fclose(b);
    fclose(c);
    return 0;
}