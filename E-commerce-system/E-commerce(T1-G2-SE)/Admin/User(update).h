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
#include <limits>
#include <unordered_map>
#include "login-form.h"
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
private:
    nodeProducts* head, *tail; 
    int size;
    vector<string> purchaseHistory; // Stores purchase history
public:
    Product1() : head(nullptr){
        loadProductsFromFile();
        loadPurchaseHistory();
    }
    ~Product1() {
        while (head != nullptr) {
            nodeProducts* temp = head;
            head = head->next;
            delete temp;
        }
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

    void savePurchaseHistory() {
        ofstream outFile("purchaseHistory.csv");
        ofstream userFile("invoice.txt");
        for (const string& entry : purchaseHistory) {
            outFile << entry << endl;
            userFile << entry << endl;
        }
        outFile.close();
        userFile.close();
    }

    void loadPurchaseHistory() {
        ifstream inFile("invoice.txt");
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


    void ViewProduct() {
        system("cls");
        nodeProducts* current = head;
        if (!current) {
            cout << "\t\t\t\t\tNo products to display." << endl;
            return;
        }

        cout << "\t\t\t==========================================================================================" << endl;
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
    
    void SearchProduct() {
        if (!head) {
            cout << "\t\t\t\t\tNo products available to search." << endl;
            return;
        }

        string searchId;
        cout << "\t\t\t\t\tEnter the Product ID to search: ";
        cin.ignore();
        getline(cin, searchId);

        nodeProducts* current = head;
        while (current) {
            if (current->productId == searchId) {
                cout << "\t\t\t\t\tProduct Found:" << endl;
                cout << "\t\t\t\t\tID: " << current->productId << endl;
                cout << "\t\t\t\t\tBrand: " << current->brand << endl;
                cout << "\t\t\t\t\tType: " << current->productType << endl;
                cout << "\t\t\t\t\tCategory: " << current->category << endl;
                cout << "\t\t\t\t\tSize: " << current->clothSize << endl;
                cout << "\t\t\t\t\tPrice: $" << current->price << endl;
                cout << "\t\t\t\t\tQuantity: " << current->quantity << endl;
                return;
            }
            current = current->next;
        }
        cout << "\t\t\t\t\tProduct not found with the given ID." << endl;
    }
    void BuyProduct() {
        if (!head) {
            cout << "\t\t\t\t\tNo products available for purchase." << endl;
            return;
        }

        while (true) {
            cout << "\t\t\t\t\t====================\n";
            cout << "\t\t\t\t\tChoose an option:\n";
            cout << "\t\t\t\t\t1. Buy one product\n";
            cout << "\t\t\t\t\t2. Group buy\n";
            cout << "\t\t\t\t\t3. Exit\n";
            cout << "\t\t\t\t\tEnter your choice: ";
            int option;
            cin >> option;

            switch (option) {
                case 1:
                    system("cls");
                    BuySingleProduct();
                    break;
                case 2:
                    system("cls");
                    GroupBuy();
                    break;
                case 3:
                    cout << "\t\t\t\t\tExiting Buy Product." << endl;
                    return;
                default:
                    cout << "\t\t\t\t\tInvalid option. Please choose again." << endl;
            }
        }
    }

    void BuySingleProduct() {
        string productId;
        int buyQuantity;

        cout << "\t\t\t\t\tEnter Product ID: ";
        cin.ignore();
        getline(cin, productId);
        transform(productId.begin(), productId.end(), productId.begin(), ::tolower);

        nodeProducts* current = head;
        while (current != nullptr) {
            if (current->productId == productId) {
                cout << "\t\t\t\t\tEnter quantity to buy: ";
                while (!(cin >> buyQuantity) || buyQuantity <= 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\t\t\t\t\tInvalid quantity. Please enter a positive number: ";
                }
                if (buyQuantity <= current->quantity) {
                    current->quantity -= buyQuantity;
                    writeProductsToFile();
                    float totalPrice = buyQuantity * current->price;
                    GenerateInvoice(current, buyQuantity, totalPrice);
                    cout << "\t\t\t\t\tPurchase successful!" << endl;
                } else {
                    cout << "\t\t\t\t\tInsufficient stock. Available: " << current->quantity << endl;
                }
                return;
            }
            current = current->next;
        }

        cout << "\t\t\t\t\tProduct ID not found. Please try again or view available products." << endl;
    }

    void GroupBuy() {
        unordered_map<string, int> consolidatedPurchases; // Map to consolidate purchases
        string productId;
        int buyQuantity;

        cout << "\t\t\t\t\tInput 'done' if you are ready to checkout.\n";
        cout << "\t\t\t\t\t==========================================\n";
        cin.ignore();
        while (true) {
            cout << "\t\t\t\t\tEnter Product ID: ";
            getline(cin, productId);
            transform(productId.begin(), productId.end(), productId.begin(), ::tolower);

            if (productId == "done") break;
            
            cout << "\t\t\t\t\tEnter quantity: ";
            while (!(cin >> buyQuantity) || buyQuantity <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\t\t\t\t\tInvalid quantity. Please enter a positive number: ";
            }
            consolidatedPurchases[productId] += buyQuantity; // Add quantity to the respective product
            cin.ignore();
        }

        float totalTransactionPrice = 0;

        for (const auto& purchase : consolidatedPurchases) {
            productId = purchase.first;
            buyQuantity = purchase.second;

            nodeProducts* current = head;
            bool productFound = false;

            while (current != nullptr) {
                if (current->productId == productId) {
                    productFound = true;
                    if (buyQuantity <= current->quantity) {
                        current->quantity -= buyQuantity;
                        float totalPrice = buyQuantity * current->price;
                        totalTransactionPrice += totalPrice;
                        GenerateInvoice(current, buyQuantity, totalPrice);
                    } else {
                        cout << "\t\t\t\t\tInsufficient stock for Product ID: " << productId 
                            << ". Available: " << current->quantity << endl;
                    }
                    break;
                }
                current = current->next;
            }

            if (!productFound) {
                cout << "\t\t\t\t\tProduct ID " << productId << " not found." << endl;
            }
        }

        cout << "\t\t\t\t\tTotal Price for Transaction: $" << totalTransactionPrice << endl;
        writeProductsToFile();
    }

    void GenerateInvoice(nodeProducts* product, int quantity, float total) {
        stringstream invoice;
        invoice << "Product ID: " << product->productId
                << " | Quantity: " << quantity
                << " | Total Price: $" << total
                << " | Brand: " << product->brand
                << " | Type: " << product->productType
                << " | Category: " << product->category
                << " | Size: " << product->clothSize
                << " | Price: $" << product->price;

        // Save the invoice to the purchase history
        purchaseHistory.push_back(invoice.str());
        savePurchaseHistory();

        // Display the generated invoice
        cout << "\t\t\t\t\tInvoice Generated:\n" << invoice.str() << endl;
    }
    

    void DeleteHistory() {
        if (purchaseHistory.empty()) {
            cout << "\t\t\t\t\tNo purchase history to delete." << endl;
            return;
        }

        cout << "\t\t\t\t\tAre you sure you want to delete the purchase history? (y/n): ";
        char confirmation;
        cin >> confirmation;

        if (tolower(confirmation) == 'y') {
            purchaseHistory.clear();
            ofstream outFile("invoice.txt", ios::trunc);
            if (outFile) {
                cout << "\t\t\t\t\tPurchase history has been deleted." << endl;
            } else {
                cout << "\t\t\t\t\tUnable to delete purchase history. File error." << endl;
            }
            outFile.close();
        } else {
            cout << "\t\t\t\t\tDeletion cancelled." << endl;
        }
    }
    // void discount () {
    //     nodeProducts* current = head;
    //     int discount;
    //     float discountPrice;
    //     float priceAfterDiscount = 0;
    //     discountPrice = current -> to
    // }
    void Console() {
        int Choice;
        do {
            cout << "\t\t\t\t\t========================================" << endl;
            cout << "\t\t\t\t\t|           User Console Menu          |" << endl;
            cout << "\t\t\t\t\t========================================" << endl;
            cout << "\t\t\t\t\t|  1. View Product                     |" << endl;
            cout << "\t\t\t\t\t|  2. Search Product                   |" << endl;
            cout << "\t\t\t\t\t|  3. Buy Product                      |" << endl;
            cout << "\t\t\t\t\t|  4. View Purchase History            |" << endl;
            cout << "\t\t\t\t\t|  5. Delete Purchase History          |" << endl;
            cout << "\t\t\t\t\t|  0. Exit                             |" << endl;
            cout << "\t\t\t\t\t========================================" << endl;
            cout << "\t\t\t\t\tPlease choose an option: ";

            cin >> Choice;
            system("cls");

            switch (Choice) {
            case 1:
                system("cls");
                ViewProduct();
                break;
            case 2:
                system("cls");
                SearchProduct();
                break;
            case 3:
                system("cls");
                BuyProduct();
                break;
            case 4:
                system("cls");
                displayHistory();
                break;
            case 5: // Call DeleteHistory
                system("cls");
                DeleteHistory();
                break;
            case 0:
                cout << "\t\t\t\tExiting from the console." << endl;
                break;
            default:
                cout << "\t\t\t\tInvalid choice. Please choose again." << endl;
            }
        } while (Choice != 0);
    }
};

#endif