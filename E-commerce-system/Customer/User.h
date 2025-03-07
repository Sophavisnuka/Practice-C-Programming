#ifndef USER_H
#define USER_H

#include <conio.h>
#include <stdlib.h>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Node to store product info
struct nodeProducts {
    string productId, brand, productType, category, clothSize;
    int quantity;
    float price; 
    nodeProducts* next;
    nodeProducts(string a, string b, string c, string d, string e, float f, int g)
    : productId(a), brand(b), productType(c), category(d), clothSize(e), price(f), quantity(g), next(nullptr) {}
};

class Product1 {
    nodeProducts* head, *tail; 
    int size;
    vector<string> purchaseHistory; // Stores purchase history

public:
    Product1() : head(nullptr) {
        loadProductsFromFile();
        loadPurchaseHistory();
    }

    ~Product1() {
        while (head != nullptr) {
            nodeProducts* temp = head;
            head = head->next;
            delete temp;
        }
        savePurchaseHistory();
    }

    // Check if Product ID exists in the linked list
    bool isProductIdExist(string& id) {
        nodeProducts* current = head;
        while (current != nullptr) {
            if (current->productId == id) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Write linked list data back to file
    void writeProductsToFile() {
        ofstream outFile("productInfo.csv");
        if (!outFile) {
            cout << "\t\t\t\t\tUnable to open file for writing." << endl;
            return;
        } else {
            cout << "\t\t\t\t\tProduct added successfully!" << endl;
        }

        nodeProducts* current = head;
        while (current != nullptr) {
            outFile << current->productId << ","
                    << current->brand << ","
                    << current->productType << ","
                    << current->category << ","
                    << current->clothSize << ","
                    << current->price << ","
                    << current->quantity << endl;
            current = current->next;
        }
        outFile.close();
    }

    // Load data from file into linked list
    void loadProductsFromFile() {
        ifstream inFile("productInfo.csv");
        if (!inFile) {
            cout << "\t\t\t\t\tNo existing product data found." << endl;
            return;
        }
        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string id, brand, type, category, size;
            int qty;
            float price;

            getline(ss, id, ',');
            getline(ss, brand, ',');
            getline(ss, type, ',');
            getline(ss, category, ',');
            getline(ss, size, ',');
            ss >> price;
            ss.ignore();
            ss >> qty;
            nodeProducts* newNode = new nodeProducts(id, brand, type, category, size, price, qty);
            newNode->next = head;
            head = newNode;
        }
        inFile.close();
    }

    void displayuser() { //testing
        nodeProducts* current = head;
        for (int i = 0; i < size; i++) {
            cout << current->productId << ","
                << current->brand << ","
                << current->productType << ","
                << current->category << ","
                << current->clothSize << ","
                << current->price << ","
                << current->quantity << endl;
            current = current->next; // moving t to the next box
        }
    }

    // View all products
    void ViewProduct() {
        system("cls");
        nodeProducts* current = head;
        if (!current) {
            cout << "\t\t\t\t\tNo products to display." << endl;
            return;
        }

        cout << "\t\t\t\t\t==================================================" << endl;
        cout << "\t\t\t\t\tProduct Information:" << endl;
        while (current != nullptr) {
            cout << "\t\t\tID: " << current->productId
                << " | Brand: " << current->brand
                << " | Type: " << current->productType
                << " | Category: " << current->category
                << " | Size: " << current->clothSize
                << " | Price: " << current->price
                << " | Quantity: " << current->quantity << endl;
            current = current->next;
        }
        cout << "\t\t\t==========================================================================================" << endl;
    }

    // Search for a product by ID
    void SearchProduct() {
        system("cls");
        nodeProducts* current = head;
        if (!current) {
            cout << "\t\t\t\t\tNo products to display." << endl;
            return;
        }
        string searchId;
        cout << "\t\t\t\t\tInput the ID of the product you want to find: ";
        cin.ignore();
        getline(cin, searchId);

        while (current != nullptr) {
            if (current->productId == searchId) {
                cout << "\t\t\t\t\tProduct Found:" << endl;
                cout << "\t\t\t\t\tID: " << current->productId
                    << " | Brand: " << current->brand
                    << " | Type: " << current->productType
                    << " | Category: " << current->category
                    << " | Size: " << current->clothSize
                    << " | Price: " << current->price
                    << " | Quantity: " << current->quantity << endl;
                return;
            }       
            current = current->next;
        }
        cout << "\t\t\t\t\tProduct with ID " << searchId << " not found." << endl;
    }

    void GenerateInvoice(const string& productId, int quantity, float total) {
        stringstream invoice;
        invoice << "Product ID: " << productId
                << " | Quantity: " << quantity
                << " | Total Price: $" << total;

        purchaseHistory.push_back(invoice.str());
        savePurchaseHistory();
        cout << "\t\t\t\t\tInvoice Generated:\n" << invoice.str() << endl;
    }

    void BuyProduct() {
        string productId;
        int buyQuantity;

        cout << "\t\t\t\t\tEnter Product ID: ";
        cin.ignore();
        getline(cin, productId);

        nodeProducts* current = head;
        while (current != nullptr) {
            if (current->productId == productId) {
                cout << "\t\t\t\t\tEnter quantity to buy: ";
                cin >> buyQuantity;

                if (buyQuantity <= current->quantity) {
                    current->quantity -= buyQuantity;
                    writeProductsToFile();

                    float totalPrice = buyQuantity * current->price;
                    GenerateInvoice(productId, buyQuantity, totalPrice);
                } else {
                    cout << "\t\t\t\t\tInsufficient stock available." << endl;
                }
                return;
            }
            current = current->next;
        }

        cout << "\t\t\t\t\tProduct ID not found." << endl;
    }
    void savePurchaseHistory() {
        ofstream outFile("purchaseHistory.txt");
        for (const string& entry : purchaseHistory) {
            outFile << entry << endl;
        }
        outFile.close();
    }

    void loadPurchaseHistory() {
        ifstream inFile("purchaseHistory.txt");
        if (!inFile) return;

        string line;
        while (getline(inFile, line)) {
            purchaseHistory.push_back(line);
        }
        inFile.close();
    }

    void displayHistory() {
        if (purchaseHistory.empty()) {
            cout << "\t\t\t\t\tNo purchase history available." << endl;
        } else {
            cout << "\t\t\t\t\tPurchase History:" << endl;
            for (const string& entry : purchaseHistory) {
                cout << entry << endl;
            }
        }
    }
    void Console() {
        int Choice;
        do {
            cout << "\t\t\t\t\t========================================" << endl;
            cout << "\t\t\t\t\t|           User Console Menu          |" << endl;
            cout << "\t\t\t\t\t========================================" << endl;
            cout << "\t\t\t\t\t|  1. View Product                     |" << endl;
            cout << "\t\t\t\t\t|  2. Search Product                   |" << endl;
            cout << "\t\t\t\t\t|  3. Generate Invoice                 |" << endl;
            cout << "\t\t\t\t\t|  4. Checkout Cart                    |" << endl;
            cout << "\t\t\t\t\t|  5. Buy Product                      |" << endl;
            cout << "\t\t\t\t\t|  6. View Purchase History            |" << endl;
            cout << "\t\t\t\t\t|  0. Exit                             |" << endl;
            cout << "\t\t\t\t\t========================================" << endl;
            cout << "\t\t\t\t\tPlease choose an option: ";

            cin >> Choice;
            system("cls");

            switch (Choice) {
            case 1:
                system("cls");
                ViewProduct(); //Done
                break;
            case 2:
                system("cls");
                SearchProduct(); //Done
                break;
            case 3:
                system("cls");
                cout << "Invoices are now generated during product purchases." << endl;
                break;
            case 4:
                system("cls");
                cout << "Checkout functionality not yet implemented." << endl;
                break;
            case 5:
                system("cls");
                BuyProduct();
                break;
            case 6:
                system("cls");
                displayHistory();
                break;
            case 0:
                cout << "\t\t\tExiting from the console." << endl;
                break;
            default:
                cout << "\t\t\tInvalid choice. Please choose again." << endl;
            }
        } while (Choice != 0);
    }
};
#endif
