#include <stdio.h>
void Power(float *x, const int n) {
    float result = 1;
    if (n > 0) {
        for (int i = 1; i <= n; i++) {
            result *= *x;
        }
        *x = result;
    } else if (n < 0) {
        for (int i = -1; i >= n; i--) {
            result /= *x;
        }
        *x = result;
    }
}
int main () {
    float x;
    int y;
    printf("Input the value of x : ");
    scanf("%f", &x);
    printf("Input the value of n : ");
    scanf("%d", &y);
    if (y == 0) {
        printf("%f power of %d = 1", x, y);
    } else {
        Power(&x, y);
        printf("%.3f", x);
    }
    return 0;
}