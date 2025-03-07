#include <stdio.h>
struct product {
    char productName[100];
    char productColor[100];
    char productDate[100];
    char expireDate[100];
    char id[100];
}p;
struct Address {
    char houseNum[100];
    char road[100];
    char city[100];
};
struct Seller {
    char sellerName[100];
    struct Address address;
}s;
int main () {
    struct product p[5];
    struct Seller s[5];
    for (int i = 0; i < 2; i++) {
        printf("----------------------------\n");
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
        printf("Seller name : ");
        scanf("%s", s[i].sellerName);
        fflush(stdin);
        printf("House number : ");
        fgets(s[i].address.houseNum, 100, stdin);
        printf("Road : ");
        fgets(s[i].address.road, 100, stdin);
        printf("City : ");
        fgets(s[i].address.city, 100, stdin);
        printf("----------------------------\n");
    }
    for (int i = 0; i < 2; i++) {
        printf("\nInformation of product[%d]\n", i+1);
        printf("----------------------------\n");
        printf("Product name : %s\n", p[i].productName);
        printf("ID of product : %s\n", p[i].id);
        printf("Product color : %s\n", p[i].productColor);
        printf("Product date : %s", p[i].productDate);
        printf("Expired date : %s", p[i].expireDate);
        printf("\nSeller of product[%d]\n", i+1);
        printf("----------------------------\n");
        printf("Product name : %s\n", s[i].sellerName);
        printf("House number : %s", s[i].address.houseNum);
        printf("Seller's house road : %s", s[i].address.road);
        printf("Seller's city : %s", s[i].address.city);
        printf("----------------------------\n");
    }
    return 0;
}
