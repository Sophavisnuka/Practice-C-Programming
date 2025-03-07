#include <stdio.h>
#include <string.h>
int main () {
    // Sort array from smallest to biggest
    int n;
    printf("Input the size of array : ");
    scanf("%d", &n);
    int array[n];
    int sort;
    printf("Now input the number of %d element : \n", n);
    //input element of array
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < (n - 1); i++) {
        for (int j = 0; j < (n - i - 1); j++) {
            if (array[j] < array[j + 1]) {
                sort = array[j];
                array[j] = array[j + 1];
                array[j + 1] = sort;
            }
        }
    }
    printf("Sort array from biggest to smallest : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}