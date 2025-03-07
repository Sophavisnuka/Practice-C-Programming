#include <stdio.h>
int main ()
{
    //4. Write a C program to ask a user for 7 scores then find the maximum and minimum value from that score array.
    float score[7];
    float max, min;
    int i;
    printf("Input all of your 7 scores :\n");
    for (int i = 0; i < 7; i++)
    {
        scanf("%f", &score[i]);
    }
    max = score[0];
    min = score[0];
    for (int i = 1; i < 7; i++)
    {
        if (max < score[i])
        {
            max = score[i];
        }
        if (min > score[i])
        {
            min = score[i];
        }
    }
    printf("The maximum of 7 scores is %.2f.\n", max);
    printf("The minimum of 7 scores is %.2f.\n", min);
    return 0;
}