#include <stdio.h>
int main () {
    FILE *a;
    char fileName[sizeof(a)];
    printf("Input file name : ");
    scanf("%s", fileName);
    a = fopen (fileName, "r");
    if (a != NULL)
    {
        printf("\nRead successful\n");
    } else {
        printf("Fail to read\n");
    }
    char text[sizeof(a)];
    while (fgets (text, sizeof(a), a) != NULL)
    {
        printf("%s", text);
    }
    fclose(a);
    
    return 0;
}
