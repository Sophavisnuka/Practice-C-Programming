#include <stdio.h>
int main ()
{
    //Input the row and colum for matrix 1
    int rowM1, columM1, rowM2, columM2;
    printf("Input the row of matrix  1 : ");
    scanf("%d", &rowM1);
    printf("Input the colum of matrix 1 : ");
    scanf("%d", &columM1);
    //Input the row and colum for matrix 2
    int matrix1[rowM1][columM1];
    printf("Input the row of matrix 2 : ");
    scanf("%d", &rowM2);
    printf("Input the colum of matrix 2 : ");
    scanf("%d", &columM2);
    int matrix2[rowM2][columM2];
    //check condition
    if (rowM1 != rowM2)
    {
        printf("The row of matrix 1 must equal to row of matrix 2\n");
    }
    else if (columM1 != columM2)
    {
        printf("The colum of matrix 1 must equal to colum of matrix 2\n");
    } 
    else if (rowM1 != rowM2 && columM1 != columM2)
    {
        printf("The row and colum of both matrix must equal\n");
    }
    else {
        printf("Input the elements for matrix 1 [%d][%d]:\n", rowM1, columM1);
        for (int i = 0; i < rowM1; i++)
        {
            for (int j = 0; j < columM1; j++)
            {
                scanf("%d", &matrix1[i][j]);
            }
        }
        printf("Input the elements for matrix 2 [%d][%d]: \n", rowM2, columM2);
        for (int i = 0; i < rowM2; i++)
        {
            for (int j = 0; j < columM2; j++)
            {
                scanf("%d", &matrix2[i][j]);
            }
        }
        int sumArray = 0;
        printf("Sum of matrix 1 and matrix 2 : \n");
        for (int i = 0; i < rowM1; i++) 
        {
            printf("{");
            for (int j = 0; j < columM1; j++)
            {
                sumArray = matrix1[i][j] + matrix2[i][j];
                printf("%d ", sumArray);
            }
            printf("\b}\n");
        }
        int subArray = 0;
        printf("Subtraction of matrix 1 and matrix 2 : \n");
        for (int i = 0; i < rowM1; i++) 
        {
            printf("{");
            for (int j = 0; j < columM1; j++)
            {
                subArray = matrix1[i][j] - matrix2[i][j];
                printf("%d ", subArray);
            }
            printf("\b}\n");
        }
    }
    return 0;
}
