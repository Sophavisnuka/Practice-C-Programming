#ifndef VENDORLOGIN_H
#define VENDORLOGIN_H
#include <iostream>
#include <fstream>
#include <string>
#include<conio.h>
#include <sstream>
#include "vendor.h"
using namespace std;

string getPassword2(){
    string Password;
    char ch;

    cout<<"\t\t\t\t\tEnter Password :";
    while (true)
    {
        ch=_getch();
        if(ch == '\r'){
            cout<<endl;
            break;
        }
        else if(ch == '\b'){
            if(!Password.empty()){
                cout<<"\b \b";
                Password.pop_back();
            }
        }
        else{
            cout<<"*";
            Password += ch;
        }
    }
    return Password;
    
}

bool isLoggedInVendor(){
    string username,password;

    cout<<"\t\t\t\t\tEnter a username: ";
    cin>>username;
    password = getPassword2();

    ifstream file("Vendors.csv");
    if(!file.is_open()){
        cout<<"\t\t\t\t\tError: Could not open user.csv file!"<<endl;
    }
    string line, storeUsername,storePass,id,salary;
    while (getline(file, line))
    {
        stringstream ss(line);
        getline(ss, id, ','); // ignore
        getline(ss, storeUsername, ',');
        getline(ss, storePass, ',');
        getline(ss, salary, ','); // ignore


        if(storeUsername == username && storePass == password){
            return true;
        }

    }
    return false;

}

void vendorLogin(){
    Product vendor;
    if(isLoggedInVendor()){
        //your code
        cout<<"\t\t\t\t\tWelcome"<<endl;
        vendor.menu();
    }
    else{
        cout<<"\t\t\t\t\tinvalid password";
    }

    
}
#endif