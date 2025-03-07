#include <stdio.h>
int main () {
    // sort array from smallest to biggest
    // input a size of array element (ex size = 5)
    // array[n]
    // array [5]
    // array = [1, 3, 5, 6, 2, 9]
    // sort array = [1, 2, 3, 5, 6, 9]
    // algorithm = printf from smallest number from 1 by 1
    int n;
    printf("Input a size of an Array : ");
    scanf("%d", &n);
    int array[n];
    printf("Input the element of array : \n");
    for (int i = 0; i < n; i++) {   
        scanf("%d", &array[i]);
    }
    int sort;
    for (int i = 0; i < (n - 1); i++) {
        for (int j = 0; j < (n - i - 1); j++) {
            if (array[j] > array[j + 1]) {
                sort = array[j];
                array[j] = array[j + 1];
                array[j + 1] = sort;
            }
        }
    }
    printf("Sort array from smallest to biggest : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}