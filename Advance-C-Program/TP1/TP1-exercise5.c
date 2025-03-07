#include <stdio.h>
int main ()
{
    int i;
    float score[10], allScore = 0, average = 0;
    printf("Input all of your 10 scores : \n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%f", &score[i]);
        allScore += score[i];
    }
    average = allScore / 10;
    printf("All score : %.2f\n", allScore);
    printf("Average of 10 score : %.2f\n", average);
    printf("Score that are greater than average[%.2f] are: ", average);
    for (int i = 0; i < 10; i++)
    {
        if (score[i] > average)
            {
                printf("%.2f, ", score[i]);
            }
    }
    return 0;
}