#ifndef USERLOGIN_H
#define USERLOGIN_H
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <sstream>
#include "User(update).h"
using namespace std;

string getPassword(){
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

bool isLoggedInUser(){
    string username,password;
    // string ur,pw;

    cout<<"\t\t\t\t\tEnter a username: ";
    cin>>username;
    password = getPassword();

    ifstream file("users.csv");
    if(!file.is_open()){
        cout<<"\t\t\t\t\tError: Could not open user.csv file!"<<endl;
    }
    string line, storeUsername,storePass;
    while (getline(file, line))
    {
        stringstream ss(line);
        getline(ss, storeUsername, ',');
        getline(ss, storePass, ',');

        if(storeUsername == username && storePass == password){
            return true;
        }

    }
    return false;
}

void registrationUser(){
    string username, password;

    cout << "\t\t\t\t\t========== Registration =========" << endl;
    cout << "\t\t\t\t\tUsername: ";
    cin >> username;
    password = getPassword();

    // Check if the user already exists
    ifstream file("users.csv");
    if (file.is_open()) {
        string line, storedUsername;
        while (getline(file, line)) {
            stringstream ss(line);
            getline(ss, storedUsername, ',');

            if (storedUsername == username) {
                cout << "\t\t\t\t\tError: Username already exists. Please try again." << endl;
                return;
            }
        }
    }
    file.close();

    // Append the new user to the CSV file
    ofstream outFile("users.csv", ios::app);
    if (outFile.is_open()) {
        outFile << username << "," << password << endl;
        outFile.close();
        cout << "\t\t\t\t\tRegistration successful! Welcome, " << username << "!" << endl;
    } else {
        cerr << "\t\t\t\t\tError: Could not write to users.csv file!" << endl;
    }
}
void userLogin() {
    int choice;
    Product1 customer;
    while (true) {
        cout << "\t\t\t\t\t========== Menu ==========" << endl;
        cout << "\t\t\t\t\t1. Login" << endl;
        cout << "\t\t\t\t\t2. Sign up" << endl;
        cout << "\t\t\t\t\t3. Exit" << endl;
        cout << "\t\t\t\t\tYour choice: ";
        cin >> choice;

        if (choice == 1) {
            if (isLoggedInUser()) {
                cout << "\t\t\t\t\tSuccessfully Logged in!" << endl;
                cout << "\t\t\t\t\tWelcome Back!" << endl;
                customer.Console();
            } else {
                cout << "\t\t\t\t\tInvalid Login! Please try again." << endl;
            }
        } else if (choice == 2) {
            registrationUser();
        } else if (choice == 3) {
            cout << "\t\t\t\t\tExiting the program. Goodbye!" << endl;
            break;
        } else {
            cout << "\t\t\t\t\tInvalid choice. Please select a valid option." << endl;
        }
    }
}
#endif