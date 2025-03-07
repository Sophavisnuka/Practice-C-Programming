#include <stdio.h>
#include <string.h>
void RepChar(char *str, char oldChar, char newChar) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == oldChar) {
            str[i] = newChar;
        } 
    }
}
int main () {
    char string[100];
    char oldChar;
    char replaceChar;
    printf("Input any word or sentences : ");
    gets(string);
    fflush(stdin);
    printf("Input a character you want to replace : ");
    scanf("%c", &oldChar);
    fflush(stdin);
    printf("Input a new character : ");
    scanf("%c", &replaceChar);
    fflush(stdin);
    RepChar(string, oldChar, replaceChar);
    printf("Result : %s", string);
    return 0;
}