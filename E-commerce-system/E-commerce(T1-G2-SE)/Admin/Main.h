#ifndef ADMIN_H
#define ADMIN_H
#include "adminVendor.h"
#include "adminOrder.h"
#include "adminPass.h"
#include "vendor.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <conio.h>
#include <string>
#include <unordered_map>
#include <climits>
void adminPage() {
    AdminLogin a1;
    manageVendor v1;
    manageOrder o1;
    Product vendor;
    a1.login();

    int choice;
    do {
        system("cls");
        cout << "\t\t\t\t\t==================================================" << endl;
        cout << "\t\t\t\t\t||                 ADMINISTRATOR                ||" << endl;
        cout << "\t\t\t\t\t==================================================" << endl;
        cout << "\n" << endl;
        cout << "\t\t\t\t\t==================================================" << endl;
        cout << "\t\t\t\t\t||         1. Add Vendor                        ||" << endl;
        cout << "\t\t\t\t\t||         2. Remove Vendor                     ||" << endl;
        cout << "\t\t\t\t\t||         3. Update Salary Vendor              ||" << endl;
        cout << "\t\t\t\t\t||         4. View Info Vendor                  ||" << endl;
        cout << "\t\t\t\t\t||         5. Order to Vendor                   ||" << endl;
        cout << "\t\t\t\t\t||         6. Remove Order                      ||" << endl;
        cout << "\t\t\t\t\t||         7. Update Order                      ||" << endl;
        cout << "\t\t\t\t\t||         8. View All Order                    ||" << endl;
        cout << "\t\t\t\t\t||         0. Exit                              ||" << endl;
        cout << "\t\t\t\t\t==================================================" << endl;
        cout << "\t\t\t\t\tYour Option: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                system("cls");
                string name, password;
                int ID;
                float salary;
                cout << "\t\t\t\t\t\t=========| Add Vendor |=========" << endl;
                cout << "Vendor ID: ";
                cin >> ID;
                if(v1.searchInfoVendor(ID)){
                        cout << "Error: Vendor with ID " << ID << " Already exist." << endl;
                        system("pause");
                        continue;
                }
                cin.ignore(); 
                cout << "Vendor Name: ";
                getline(cin, name);
                cout << "Vendor Salary: ";
                cin >> salary;
                cin.ignore();
                cout << "Vendor Password: ";
                getline(cin, password);

                v1.addVendor(ID, name, password, salary);
                cout << "Vendor with ID " << ID << " has been successfully added." << endl;
                system("pause");
                break;
            }

            case 2: {
                cout << "\t\t\t\t\t\t=========| Remove Vendor |=========" << endl;
                system("cls");
                int ID;
                cout << "Enter Vendor ID to remove: ";
                cin >> ID;
                if(v1.searchInfoVendor(ID) == nullptr){
                    cout << "Error: Vendor with ID " << ID << " does not exist." << endl;
                    system("pause");
                    continue;
                }
                v1.removeVendor(ID);
                cout << "Vendor with ID " << ID << " has been successfully removed." << endl;
                system("pause");
                break;
            }

            case 3: {
                system("cls");
                cout << "\t\t\t\t\t\t=========| Update Salary Vendor |=========" << endl;
                int ID;
                float newSalary;
                int option;
                do{
                    cout<<"Show Info Vendor ?"<<endl;
                    cout<<"1.Yes"<<endl;
                    cout<<"2.No"<<endl;
                    cout<<"Your Option :";
                    cin>>option;
                    cin.ignore();
                    if(option == 1){
                        v1.viewAllVendor();
                        cout << "Enter Vendor ID to update: ";
                        cin >> ID;
                        if(v1.searchInfoVendor(ID) == nullptr){
                            cout << "Error: Vendor with ID " << ID << " does not exist." << endl;
                            system("pause");
                            continue;
                        }
                        cout << "Enter new salary: ";
                        cin >> newSalary;
                        v1.updateSalaryVendor(ID, newSalary);
                        system("pause");
                    }
                    else if(option == 2){
                        cout << "Enter Vendor ID to update: ";
                        cin >> ID;
                        if(v1.searchInfoVendor(ID) == nullptr){
                            cout << "Error: Vendor with ID " << ID << " does not exist." << endl;
                            system("pause");
                            continue;
                        }
                        cout << "Enter new salary: ";
                        cin >> newSalary;
                        v1.updateSalaryVendor(ID, newSalary);
                        system("pause");

                    }
                    else{
                        cout<<"Invalid! Please try again."<<endl;
                        system("pause");
                        continue;
                    }   
                }while (option != 1 && option !=2);   
                break;
            }
            case 4:{
                system("cls");
                cout << "\t\t\t\t\t\t=========| View Info Vendor |=========" << endl;
                v1.viewAllVendor();
                system("pause");
                break;
            }

            case 5: {
                system("cls");
                int orderID;
                string itemName;
                float price;
                int qty;

                cout << "\t\t\t\t\t\t=========| Order to Vendor |=========" << endl;
                cout <<"Order ID:";
                cin>>orderID;
                cin.ignore();
                cout<<"Product Name :";
                getline(cin, itemName);
                cout<<"Price :";
                cin>>price;
                cin.ignore();
                cout<<"Quantity :";
                cin>>qty;
                cin.ignore();

                o1.addnewitemOrder(orderID,itemName,price,qty);
                cout << "Order with ID " << orderID << " has been successfully added." << endl;
                system("pause");
                break;
                break;            
            }
            case 6:{
                cout << "\t\t\t\t\t\t=========| Remove Order |=========" << endl;
                system("cls");
                int ID;
                cout << "Enter Order ID to remove: ";
                cin >> ID;
                if(o1.searchOrder(ID) == nullptr){
                    cout << "Error: Order with ID " << ID << " does not exist." << endl;
                    system("pause");
                    continue;
                }
                o1.removeOrder(ID);
                cout << "Order with ID " << ID << " has been successfully removed." << endl;
                system("pause");
                break;
               
            }
            case 7: {
                cout << "\t\t\t\t\t\t=========| Update Order |=========" << endl;
                int option;
                int ID;
                string itemName;
                float price;
                int qty;
                do {
                    cout << "Show All Orders?" << endl;
                    cout << "1. Yes" << endl;
                    cout << "2. No" << endl;
                    cout << "Your Option: ";
                    cin >> option;
                    cin.ignore();

                    if (option == 1) {
                        o1.viewAllOrder(); // Show all orders
                        cout << "Enter Order ID to update: ";
                        cin >> ID;
                        if (o1.searchOrder(ID) == nullptr) {
                            cout << "Error: Order with ID " << ID << " does not exist." << endl;
                            system("pause");
                            continue;
                        }

                        cout << "What would you like to update?" << endl;
                        cout << "1. Item Name" << endl;
                        cout << "2. Price" << endl;
                        cout << "3. Quantity" << endl;
                        cout << "Your Option: ";
                        int updateOption;
                        cin >> updateOption;
                        cin.ignore();

                        switch (updateOption) {
                            case 1:
                                cout << "Enter New Item Name: ";
                                getline(cin, itemName); 
                                o1.updateOrderItemName(ID, itemName); 
                                break;

                            case 2:
                                cout << "Enter New Price: ";
                                cin >> price;
                                o1.updateOrderPrice(ID, price); 
                                break;

                            case 3:
                                cout << "Enter New Quantity: ";
                                cin >> qty;
                                o1.updateOrderQuantity(ID, qty); 
                                break;

                            default:
                                cout << "Invalid option!" << endl;
                                break;
                        }
                    } 
                    else if(option == 2){
                        cout << "Enter Order ID to update: ";
                        cin >> ID;
                        if(o1.searchOrder(ID) == nullptr){
                            cout << "Error: Order with ID " << ID << " does not exist." << endl;
                            system("pause");
                            continue;
                        }
                        cout << "Enter Item New Name: ";
                        string itemName;
                        cout<<"Enter New Price :";
                        cin>>price;
                        cin.ignore();
                        cout<<"Enter New Quantity: ";
                        cin>>qty;
                        cin.ignore();
                        system("pause");

                    }
                    else{
                        cout<<"Invalid! Please try again."<<endl;
                        system("pause");
                        continue;
                    } 

                    system("pause");

                      
                }while (option != 1 && option !=2);   
                break;


            }
            case 8:{
                system("cls");
                cout << "\t\t\t\t\t\t=========| View All Order |=========" << endl;
                o1.viewAllOrder();
                system("pause");
                break;

                
            }
            case 9:{
                system("cls");
                cout << "\t\t\t\t\t\t=========| Sales Report |=========" << endl;
                vendor.viewSaleReport();
                system("pause");

            }

            case 0:{
                return;
            }

            default: {
                cout << "Invalid choice. Please try again.\n";
                system("pause");
            }
        }
    } while (choice != 0);
}
#endif
