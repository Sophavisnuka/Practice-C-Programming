#include <stdio.h>
#include <string.h>
void shift_left(char *str, int n) {
    int len = strlen(str);
    if ((len - 1) < n || (len - 1) == n) {
        //len -1 because the size of int len is + 1 so we have to -1 to make it equal
        printf("The size of shift n should be smaller than the size of sentences\n");
    } else {
        for (int i = n; i < len; i++) {
            printf("%c", str[i-1]);
        }
    }
}
int main () {
    int n;
    char string[100];
    printf("Write any sentences : ");
    fgets(string, sizeof(string), stdin);
    printf("Shift n : ");
    scanf("%d", &n);
    shift_left(string, n);
    return 0;
}