#include <stdio.h>
#include <string.h>
struct product {
    char productName[100];
    char productColor[100];
    char productDate[100];
    char expireDate[100];
    char id[100];
}p;
int main () {
    struct product p[5];
    for (int i = 0; i < 5; i++) {
        printf("Product name : ");
        scanf("%s", p[i].productName);
        fflush(stdin);
        printf("Input id : ");
        scanf("%s", p[i].id);
        fflush(stdin);
        printf("Product color (we have 5 colors: red, yellow, blue, white, and black) : ");
        fgets(p[i].productColor, 100, stdin);
        printf("Product date : ");
        fgets(p[i].productDate, 100, stdin);
        printf("Expire date : ");
        fgets(p[i].expireDate, 100, stdin);
        printf("----------------------------\n");
    }
    //display here
    for (int i = 0; i < 5; i++) {
        printf("\nInformation of product[%d]\n", i+1);
        printf("----------------------------\n");
        printf("Product name : %s\n", p[i].productName);
        printf("ID of product : %s\n", p[i].id);
        printf("Product color : %s\n", p[i].productColor);
        printf("Product date : %s\n", p[i].productDate);
        printf("Expired date : %s\n", p[i].expireDate);
    }
    return 0;
}