#include <stdio.h>
void addition (int *a , int b) { // change Void to void
    *a = *a + b;//change a to *a
}
int main() { // change Int to int
    int a = 9;
    int b = 2;
    /* pointer point to NULL */
    int *p_a = &a; // pointer point to the address of a (*p_a = &a)
    //display a, b
    printf("Before swap: (a:%d, b:%d)\n", *p_a, b); // change p_a to *p_a
    /* swap value of a and b */
    *p_a = a + b; // use *p_a
    b = *p_a - b;
    a = *p_a - b;
    /* display a, b */
    printf("After swap: (a:%d, b:%d)\n", a, b); // change p_a to a 
    /* pointer point to b */
    int *p_b = &b; // pointer point to the address of b (*p_b = &b)
    /* display a, b */
    printf("Before sum: (a:%d, b:%d)\n", *p_a, *p_b); // *p_a,*p_b
    /* a equal to a + b */
    addition(&a, b); // use (&a, b)
    /* display a, b */
    printf("After sum: (a:%d, b:%d)\n", *p_a, *p_b); // *p_a,*p_b
    return 0;
}
