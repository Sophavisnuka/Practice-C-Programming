#include <stdio.h>
#include <stdbool.h>
int main () {
    int candies[50], extraCandies, kid, candiesForKid = 0;
    printf("Input the amount of kid : ");
    scanf("%d", &kid);
    printf("Input the amount of candies that you give to each kids :\n");
    for (int i = 0; i < kid; i++ )
    {
        printf("Kid %d : ", i+1);
        scanf("%d", &candies[i]);
    }
    printf("Input the amount of extra candies : ");
    scanf("%d", &extraCandies);
    int maxCandies = 0;
    for (int j = 0; j < kid; j++)
    {
        candiesForKid = candies[j] + extraCandies;
        if (candies[j] > maxCandies)
        {
            maxCandies = candies[j];
        }
    }
    int result[50];
    for (int i = 0; i < kid; i++)
    {
        if (candies[i] + extraCandies >= maxCandies)
        {
            bool result = true;
            printf("Kid %d have %d candies. - (%d)\n", i+1, candiesForKid, result);
        } else {
            bool result = false;
            printf("Kid %d have %d candies. - (%d)\n", i+1, candiesForKid, result);
        }
    } 
    return 0;
}