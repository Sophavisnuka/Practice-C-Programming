#include <stdio.h>
int main ()
{
    int sizeArray1, sizeArray2;
    printf("Input the size of the array1 : ");
    scanf("%d", &sizeArray1);
    int array1[sizeArray1];
    printf("Input the size of the array2 : ");
    scanf("%d", &sizeArray2);
    int array2[sizeArray2];
    if (sizeArray1 != sizeArray2)
    {
        printf("Both must have the same size");
    }
    else {
        printf("=====Array1=====\n");
        printf("Input number for array 1 [ex:1 2 3]: ");
        for (int i = 0; i < sizeArray1; i++)
        {
            scanf("%d", &array1[i]);
        }
        printf("=====Array2=====\n");
        printf("Input number for array 2 [ex:4 5 6]: ");
        for(int j = 0; j < sizeArray2; j++)
        {
            scanf("%d", &array2[j]);
        }
        printf("=====Sum Array=====\n");
        int sumArray;
        sizeArray1 = sizeArray2;
        printf("Sum of both array : ");
        for (int x = 0; x < sizeArray2; x++) {
            sumArray = array1[x] + array2[x];
            printf("%d ", sumArray);
        }
        printf("\n=====Subtraction of Array=====\n");
        int subtraction;
        printf("Subtraction of both array : ");
        for (int x = 0; x < sizeArray2; x++) {
            subtraction = array1[x] - array2[x];
            printf("%d ", subtraction);
        }
        printf("\n");
    }
    return 0;
}