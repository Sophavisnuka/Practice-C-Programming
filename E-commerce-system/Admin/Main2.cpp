#include "Main.h"
#include "login-form.h"
#include "login-Vendor.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
int main() {
    int choose;
    do {
        system("cls");  
        cout << "\t\t\t\t\t==================================================" << endl;
        cout << "\t\t\t\t\t||                 WELCOME TO                   ||" << endl;
        cout << "\t\t\t\t\t||              OUR CLOTHES SHOP                ||" << endl;
        cout << "\t\t\t\t\t==================================================" << endl;
        cout << "\n"<<endl;
        cout << "\t\t\t\t\t==================================================" << endl;
        cout << "\t\t\t\t\t||         1. Administrator program             ||" << endl;
        cout << "\t\t\t\t\t||         2. Vendor program                    ||" << endl;
        cout << "\t\t\t\t\t||         3. Customer program                  ||" << endl;
        cout << "\t\t\t\t\t||         4. Exit                              ||" << endl;
        cout << "\t\t\t\t\t==================================================" << endl;
        cout << "\t\t\t\t\tChoose 1, 2, or 3: ";
        cin >> choose;
        cout <<"\n";
        system("cls");
        switch (choose) {
        case 1:
            system("cls");
            cout <<"\t\t\t\t\t\tYou are in the Administrator program!"<<endl;
            adminPage();
            break;
        case 2:
            system("cls");
            cout <<"\t\t\t\t\tYou are in the Vendor program!"<<endl;
            vendorLogin();
            break;
        case 3:
            system("cls");
            cout <<"\t\t\t\t\tYou are in the customer program!"<<endl;
            userLogin();
            break;
        case 4:
            system("cls");
            cout << "\t\t\t\t\tExit from program" << endl;
            break;
        default:
            system("cls");
            cout << "\t\t\t\t\tPlease choose a valid option!" << endl;
        }
    } while (choose != 0);
    return 0;
}
