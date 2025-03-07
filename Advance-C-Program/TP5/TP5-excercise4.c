#include <stdio.h>
#include <string.h>
void existCharacter () {
    char string[1000], character;
    printf("Enter any sentences : ");
    // fgets(string, sizeof(string), stdin);
    scanf("%s", string);
    fflush(stdin);
    printf("Enter any single character : ");
    scanf("%c", &character);
    int check = 0;
    for (int i = 0; i < string; i++) {
        if (character == string[i]) {
            check = 1;
        }
    }
    if (check == 1) {
        printf("The character [%c] is exist.", character);
    } else {
        printf("The character [%c] doesn't exist.", character);
    }
}
int main () {
    existCharacter();
    return 0;
}