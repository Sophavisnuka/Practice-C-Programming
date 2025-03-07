#include <stdio.h>
int main () 
{
    //1. Create an array that store 10 integer numbers (2 4 6 8 10 12 14 16 18 20). Then display those array elements on screen.
    printf("1.Create an array that store 10 integer numbers.\n");
    int Array[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    for (int i = 0; i < 10; i++) {
        printf("%d ", Array[i]);
    }
    return 0;
}