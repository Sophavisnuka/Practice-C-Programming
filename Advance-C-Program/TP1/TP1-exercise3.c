#include <stdio.h>
int main ()
{
    //3. Given an array of 9 integer numbers (3 -3 1 5 7 0 8 9 6). Write a program that test if an integer number input by a user is exist in that array or not.
    int index[] = {3, -3, 1, 5, 7, 0, 8, 9, 6};
    int num = 0;
    printf("Enter a number : ");
    scanf("%d", &num);
    int j = 0;
    for (int i = 0; i < 9; i++)
    {
        if (num == index[i])
        {
            j = 1;
        }
    }
    if (j == 0)
    {
        printf("The number %d does not exists in the array.", num);
    }
    else {
        printf("The number %d exists in the array.", num);
    }
    return 0;
}