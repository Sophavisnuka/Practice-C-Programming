#include <stdio.h>
#include <string.h>
void filter(char *str, char c) {
    int len = 0;
    for (int i = 0; i < strlen(str); i++) {
        if ((str[i]) != c) {
            printf("%c", str[i]);
        }
        else {
            len = 1;
        }
    }
    if (len != 1) {
        printf("\nThe filter character [%c] doesn't exist in %s\n", c, str);
    }
}
int main () {
    char string[100], character;
    printf("Enter any sentences : ");
    gets(string);
    printf("Input filter character : ");
    scanf("%c", &character);
    filter(string, character);
    return 0;
}