#include <stdio.h>
float Number (float num1, float num2) {
    if (num1 > num2) {
        return num1;
    } else if (num1 < num2) {
        return num2;
    } else {
        return -1;
    }
}
int main () {
    float num1, num2, result;
    printf("Input num1 : ");
    scanf("%f", &num1);
    printf("Input num2 : ");
    scanf("%f", &num2);
    result = Number (num1, num2);
    if (result == -1) {
        printf("Both number is equal");
    } else {
        printf("The greatest number is %.2f", result);
    }
    return 0;
}