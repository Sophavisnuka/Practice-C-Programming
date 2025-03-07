#include <stdio.h>
int sum (int x, int y, int z) {
    int sum = 0;
    sum = x + y + z;
    return sum;
}
int main () {
    int a , b, c;
    printf("Input value for a : ");
    scanf("%d", &a);
    printf("Input value for b : ");
    scanf("%d", &b);
    printf("Input value for c : ");
    scanf("%d", &c);
    printf("The sum of 3 integers : %d", sum (a, b, c));
    return 0;
}