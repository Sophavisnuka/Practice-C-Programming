#include <stdio.h>
long int summation (int n) {
    if (n <= 0) {
        return 0;
    } else {
        return n + summation(n - 1);
    }
}
int main () {
    int n, result;
    printf("Input number : ");
    scanf("%d", &n);
    result = summation(n);
    // printf("Summation : %d", summation(n));
    if (result == 1) {
        printf("The number that you input must bigger than 0\n");
    } else {
        printf("Summation : %d", summation(n));
    }
    return 0;
}