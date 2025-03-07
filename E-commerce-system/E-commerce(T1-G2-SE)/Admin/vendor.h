#ifndef VENDOR_H
#define VENDOR_H
#include <conio.h>
#include <stdlib.h>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <climits>
#include <vector>
#include "adminOrder.h"
using namespace std;
// Node to store product info
    vector<string> mostPurchasedProducts, leastPurchasedProducts;
struct nodeProduct {
    string productId, brand, productType, category, clothSize;
    int quantity;
    float price; 
    nodeProduct* next;
    nodeProduct(string a, string b, string c, string d, string e, float f, int g)
    : productId(a), brand(b), productType(c), category(d), clothSize(e), price(f), quantity(g), next(nullptr) {}
};
class Product {
    nodeProduct* head, *tail; 
    int size;

public:
    Product() : head(nullptr) {
        loadProductsFromFile();
    }
    ~Product() {
        while (head != nullptr) {
            nodeProduct* temp = head;
            head = head->next;
            delete temp;
        }
    }
    // Check if Product ID exists in the linked list
    bool isProductIdExist(string& id) {
        nodeProduct* current = head;
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
        fstream outFile;
        outFile.open("productInfo.csv", ios::out);
        if (!outFile) {
            cout << "\t\t\t\t\tUnable to open file for writing." << endl;
            return;
        }
        nodeProduct* current = head;
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
    //clear old linked list dat before load data to linked list
    void clearLinkedList() {
        nodeProduct* current = head;
        while (current != nullptr) {
            current = current->next;
            delete current;
        }
        head = nullptr; // Reset head
    }
    // Load data from file into linked list
    void loadProductsFromFile() {
        clearLinkedList();
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
            nodeProduct* newNode = new nodeProduct(id, brand, type, category, size, price, qty);
            newNode->next = head;
            head = newNode;
        }
        inFile.close();
    }
    // Add product to linked list
    void addProduct() {
        string productId, brand, productType, category, clothSize;
        int quantity;
        float price;
        cout << "\t\t\t\t\tInput the product information that you want to add:" << endl;
        cout << "\t\t\t\t\t===========================================================" << endl;
            do { //check if the id already exist
                transform(productId.begin(), productId.end(), productId.begin(), ::toupper); //convert string to upper case
                cout << "\t\t\t\t\tProduct ID: ";
                cin.ignore();
                getline(cin, productId);
                if (isProductIdExist(productId)) {
                    cout << "\t\t\t\t\tThis ID already exists. Please input again!" << endl;
                }
            } while (isProductIdExist(productId));
            cout << "\t\t\t\t\tProduct Brand: "; getline(cin, brand);
            cout << "\t\t\t\t\tProduct Type: "; getline(cin, productType);
            do { //check the gender only M or W 
                cout << "\t\t\t\t\tProduct Category (M/W): "; getline(cin, category);
                transform(category.begin(), category.end(), category.begin(), ::toupper); //convert string to upper case
                if (category != "M" && category != "W" && category != "X") {
                    cout << "\t\t\t\t\tPlease input a valid category (M or W)." << endl;
                }
            } while (category != "M" && category != "W" && category != "X");
            do { //check size of product we can only input size below
                cout << "\t\t\t\t\tProduct Size (S/M/L/XL): "; getline(cin, clothSize);
                transform(clothSize.begin(), clothSize.end(), clothSize.begin(), ::toupper); //convert string to uppercase
                if (clothSize != "S" && clothSize != "M" && clothSize != "L" && clothSize != "XL") {
                    cout << "\t\t\t\t\tPlease input a valid size (S, M, L, XL)." << endl;
                }
            } while (clothSize != "S" && clothSize != "M" && clothSize != "L" && clothSize != "XL");
            cout << "\t\t\t\t\tProduct Quantity: "; cin >> quantity;
            cout << "\t\t\t\t\tProduct Price (for 1 item): "; cin >> price;
            cout << "\t\t\t\t\tProduct add successfully" << endl;
        // create new node that store info we input 
        nodeProduct* newNode = new nodeProduct(productId, brand, productType, category, clothSize, price, quantity);
        newNode->next = head;
        head = newNode;
        size++;
        //write to file
        writeProductsToFile();
    }
    // View all products
    void viewProduct() {
        system("cls");
        nodeProduct* current = head;
        if (!current) {
            cout << "\t\t\t\t\tNo products to display." << endl;
            return;
        }
        cout << "\t\t\t==========================================================================================" << endl;
        cout << "\t\t\tProduct Information:\n" << endl;
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
        cout <<"\n";
        stockProduct();
        cout << "\t\t\t==========================================================================================" << endl;
    }
    // Search for a product by ID
    void searchProduct() {
        system("cls");
        nodeProduct* current = head;
        cout << "\t\t\t\t\t======================================================" << endl;
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
        cout << "\t\t\t\t\t======================================================" << endl;
        cout << "\t\t\t\t\tProduct with ID " << searchId << " not found." << endl;
    }
    // remove an element from the linked list
    void removeProduct() {
        system("cls");
        loadProductsFromFile(); // Load data from the file into the linked list
        nodeProduct* prev = nullptr; 
        nodeProduct* current = head;
        cout << "\t\t\t\t\t======================================================" << endl;
        if (!current) {
            cout << "\t\t\t\t\tNo products to display.\nn" << endl;
            return;
        }
        string remId;
        cout << "\t\t\t\t\tInput the ID of the product you want to remove: ";
        cin.ignore();
        getline(cin, remId);
        bool found = false; // Flag to check if product is found
        while (current != nullptr) {
            if (current->productId == remId) { 
                if (prev == nullptr) { // Removing the first node
                    head = current->next;
                } else { // Removing a middle or last node
                    prev->next = current->next;
                }
                delete current; // Free memory
                cout << "\t\t\t\t\tProduct with ID: " << remId << " has been removed." << endl;
                cout << "\t\t\t\t\t======================================================" << endl;
                found = true;
                break; // Exit loop after deletion
            } else {
                prev = current;
                current = current->next;
            }
        }
        if (!found) {
            cout << "\t\t\t\t\tProduct with ID: " << remId << " not found." << endl;
            cout << "\t\t\t\t\t======================================================" << endl;
        } else {
            writeProductsToFile(); // Save updated data to file
        }
    }
    //count stock of product
    int stockProduct () {
        nodeProduct* current = head;
        int stock = 0;
        while (current != nullptr) {
            stock += current -> quantity;
            current = current -> next;
        }
        cout <<"\t\t\t\t\tTotal stock: "<<stock<<endl;
        return stock;
    }
    int editStockProduct () {
        nodeProduct* temp = head;
        string editId;
        int editQuantity = 0;
        cout << "\t\t\t\t\t======================================================" << endl;
        cout << "\t\t\t\t\tInput the ID of the product you want to edit: ";
        cin.ignore();
        getline(cin, editId);
        while (temp != nullptr) {
            if (temp->productId == editId) {
                cout << "\t\t\t\t\tProduct Found:" << endl;
                cout << "\t\t\t\t\tID: " << temp->productId
                    << " | Brand: " << temp->brand
                    << " | Type: " << temp->productType
                    << " | Category: " << temp->category
                    << " | Size: " << temp->clothSize
                    << " | Price: " << temp->price
                    << " | Quantity: " << temp->quantity << endl;
                cout << "\t\t\t\t\t======================================================" << endl;
                inPutagain:
                cout << "\t\t\t\t\tEnter new quantity: ";
                cin >> editQuantity;
                if (editQuantity < 0) {
                    cout << "\t\t\t\t\tInvalid quantity. Please input again." << endl;
                    goto inPutagain;
                } else {
                    temp->quantity += editQuantity;
                    cout << "\t\t\t\t\tProduct quantity updated successfully." << endl;
                    cout << "\t\t\t\t\t======================================================" << endl;
                    cout << "\t\t\t\t\tID: " << temp->productId
                        << " | Brand: " << temp->brand
                        << " | Type: " << temp->productType
                        << " | Category: " << temp->category
                        << " | Size: " << temp->clothSize
                        << " | Price: " << temp->price
                        << " | Quantity: " << temp->quantity << endl;
                    writeProductsToFile();
                    return 0;
                }
            }
            temp = temp->next;
        }
    }
    int editStockPrice () {
        nodeProduct* temp = head;
        string editId;
        float editPrice = 0;
        cout << "\t\t\t\t\t======================================================" << endl;
        cout << "\t\t\t\t\tInput the ID of the product you want to edit: ";
        cin.ignore();
        getline(cin, editId);
        while (temp != nullptr) {
            if (temp->productId == editId) {
                cout << "\t\t\t\t\tProduct Found:" << endl;
                cout << "\t\t\t\t\tID: " << temp->productId
                    << " | Brand: " << temp->brand
                    << " | Type: " << temp->productType
                    << " | Category: " << temp->category
                    << " | Size: " << temp->clothSize
                    << " | Price: " << temp->price
                    << " | Quantity: " << temp->quantity << endl;
                cout << "\t\t\t\t\t======================================================" << endl;
                inPutagain:
                cout << "\t\t\t\t\tEnter new price: ";
                cin >> editPrice;
                if (editPrice < 0) {
                    cout << "\t\t\t\t\tInvalid quantity. Please input again." << endl;
                    goto inPutagain;
                } else {
                    temp->price = editPrice;
                    cout << "\t\t\t\t\tProduct quantity updated successfully." << endl;
                    cout << "\t\t\t\t\t======================================================" << endl;
                    cout << "\t\t\t\t\tID: " << temp->productId
                        << " | Brand: " << temp->brand
                        << " | Type: " << temp->productType
                        << " | Category: " << temp->category
                        << " | Size: " << temp->clothSize
                        << " | Price: " << temp->price
                        << " | Quantity: " << temp->quantity << endl;
                    writeProductsToFile();
                    return 0;
                }
            }
            temp = temp->next;
        }
    }
    
   void viewSaleReport() {
    ifstream buyInfo("purchaseHistory.csv");
    if (!buyInfo) {
        cout << "\t\t\t\t\tNo purchase history available to generate the report." << endl;
        return;
    }

    // Variables for tracking sales data
    unordered_map<string, int> productSales; // Product ID -> Total quantity sold
    unordered_map<string, float> productRevenue; // Product ID -> Total revenue
    float totalRevenue = 0;
    string line;

    // Parse the purchase history
    while (getline(buyInfo, line)) {
        stringstream ss(line);
        string productId, quantityStr, totalPriceStr;

        // Extract details from purchase history entry
        getline(ss, productId, '|');
        productId = productId.substr(productId.find(":") + 2); // Extract value after "Product ID: "

        getline(ss, quantityStr, '|');
        int quantity = stoi(quantityStr.substr(quantityStr.find(":") + 2)); // Extract value after "Quantity: "

        getline(ss, totalPriceStr, '|');
        float totalPrice = stof(totalPriceStr.substr(totalPriceStr.find("$") + 1)); // Extract value after "$"

        // Update sales and revenue data
        productSales[productId] += quantity;
        productRevenue[productId] += totalPrice;
        totalRevenue += totalPrice;
    }
    buyInfo.close();

    // Find most and least purchased products
    int maxQuantity = 0, minQuantity = INT_MAX;

    for (const auto& sale : productSales) {
        if (sale.second > maxQuantity) {
            maxQuantity = sale.second;
            mostPurchasedProducts.clear(); // Clear previous products
            mostPurchasedProducts.push_back(sale.first);
        } else if (sale.second == maxQuantity) {
            mostPurchasedProducts.push_back(sale.first); // Add to the list
        }

        if (sale.second < minQuantity) {
            minQuantity = sale.second;
            leastPurchasedProducts.clear(); // Clear previous products
            leastPurchasedProducts.push_back(sale.first);
        } else if (sale.second == minQuantity) {
            leastPurchasedProducts.push_back(sale.first); // Add to the list
        }
    }

    // Display the sales report
    cout << "\t\t\t\t\t======================================================" << endl;
    cout << "\t\t\t\t\tTotal Revenue Earned: $" << totalRevenue << endl;

    cout << "\t\t\t\t\tMost Purchased Products: ";
    for (const auto& product : mostPurchasedProducts) {
        cout << product << " ";
    }
    cout << "(Quantity Sold: " << maxQuantity << ")" << endl;

    cout << "\t\t\t\t\tLeast Purchased Products: ";
    for (const auto& product : leastPurchasedProducts) {
        cout << product << " ";
    }
    cout << "(Quantity Sold: " << minQuantity << ")" << endl;

    cout << "\t\t\t\t\t======================================================" << endl;
}



    //menu
    void menu() {
        manageOrder v1;
        int choice;
        do {
            cout << "\t\t\t\t\t======================================================" << endl;
            cout << "\t\t\t\t\t\t\t1. Add product" << endl;
            cout << "\t\t\t\t\t\t\t2. Search product" << endl;
            cout << "\t\t\t\t\t\t\t3. Remove product" << endl;
            cout << "\t\t\t\t\t\t\t4. Product List" << endl;
            cout << "\t\t\t\t\t\t\t5. add Quantity" << endl;
            cout << "\t\t\t\t\t\t\t6. View total stock" << endl;
            cout << "\t\t\t\t\t\t\t7. View sales report" << endl;
            cout << "\t\t\t\t\t\t\t8. View order from admin" << endl;
            cout << "\t\t\t\t\t\t\t9. add Price" << endl;
            cout << "\t\t\t\t\t\t\t0. Exit" << endl;
            cout << "\t\t\t\t\t\t\tChoose an option: ";
            cin >> choice;
            system("cls");
            switch (choice) {
            case 1:
                system("cls");
                addProduct();
                break;
            case 2:
                system("cls");
                searchProduct();
                break;
            case 3:
                system("cls");
                removeProduct();
                break;
            case 4:
                system("cls");
                viewProduct();
                break;
            case 5:
                system("cls");
                editStockProduct();
                break;
            case 6:
                system("cls");
                stockProduct();
                break;
            case 7:
                viewSaleReport();
                break;
            case 8:
                v1.viewAllOrder();
                break;
            case 9:
                editStockPrice();
                break;
            case 0:
                cout << "\t\t\t\t\tExiting from the administrator" << endl;
                break;
            default:
                cout << "\t\t\t\t\tnvalid choice. Please choose again." << endl;
            }
        } while (choice != 0);
    }
};

#endif