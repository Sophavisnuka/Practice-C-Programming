#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main () {
    FILE *b, *c;
    char fileName[100],newFile[100];
    //input name of source file
    printf("Input file name : ");
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
    c = fopen (newFile, "w");
    //compare both file name
    if (strcmp(fileName, newFile) == 0) {
        printf("Error! Both file have the same name");
    }
    char text[sizeof(b)];
    while (fgets(text, sizeof(b), b) != NULL) {
        printf("%s", text);
        fputs(text, c);
    }
    fclose(b);
    fclose(c);
    return 0;
}