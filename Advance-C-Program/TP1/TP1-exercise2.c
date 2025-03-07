#include <stdio.h>
int main ()
{
    //2. Store n names in an array and display on screen. Ask a user for the number of names then ask for each name.
    int n = 0;
    printf("How many names? : ");
    scanf("%d", &n);
    char Name [n][100];
    for (int i = 0; i < n; i++) {
        printf("Name %d : ", i+1);
        scanf("%s", Name[i]);
    }
    if (n == 1) {
        printf("This name is %s.\n", Name[0]);
    } else {
        printf("Those %d names are : ", n);
        for (int j = 0; j < n; j++) {
            if (j == n - 1) {
                printf("and %s.", Name[j]);
            } else {
                printf("%s, ", Name[j]);
            }
        }
    }
    return 0;
}