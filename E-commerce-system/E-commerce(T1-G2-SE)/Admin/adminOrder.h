#ifndef ADMIN_ORDER_H
#define ADMIN_ORDER_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

class manageOrder {

private:
    struct node {
        int orderID;
        string item;
        float price;
        int qty;
        node* left;
        node* right;
    };
    node* root;

    bool isDuplicateID(node* root, int orderID) {
        if (root == nullptr) {
            return false;
        }
        if (root->orderID == orderID) {
            return true;
        }
        if (root->orderID > orderID) {
            return isDuplicateID(root->left, orderID);
        }
        return isDuplicateID(root->right, orderID);
    }

    node* createNewItemOrder(int orderID, string item, float price, int qty) {
        node* newOrder = new node;
        newOrder->orderID = orderID;
        newOrder->item = item;
        newOrder->price = price;
        newOrder->qty = qty;
        newOrder->left = nullptr;
        newOrder->right = nullptr;
        return newOrder;
    }

    node* addnewitemOrder(node* root, node* newOrder) {
        if (root == nullptr) {
            return newOrder;
        }
        if (root->orderID > newOrder->orderID) {
            root->left = addnewitemOrder(root->left, newOrder);
        } else if (root->orderID < newOrder->orderID) {
            root->right = addnewitemOrder(root->right, newOrder);
        }
        return root;
    }

    node* searchID(node* root, int orderID) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->orderID == orderID) {
            return root;
        }
        if (root->orderID > orderID) {
            return searchID(root->left, orderID);
        }
        return searchID(root->right, orderID);
    }

    node* deleteOrder(node* root, int orderID) {
        if (root == nullptr) {
            return root;
        }
        if (root->orderID > orderID) {
            root->left = deleteOrder(root->left, orderID);
        } else if (root->orderID < orderID) {
            root->right = deleteOrder(root->right, orderID);
        } else {
            if (root->left == nullptr) {
                node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                node* temp = root->left;
                delete root;
                return temp;
            }
            node* temp = root->right;
            while (temp != nullptr && temp->left != nullptr) {
                temp = temp->left;
            }
            root->orderID = temp->orderID;
            root->right = deleteOrder(root->right, temp->orderID);
        }
        return root;
    }


    void savetoCSVHelperOrder(node* root, ofstream& file) {
        if (root != nullptr) {
            savetoCSVHelperOrder(root->left, file);
            file << root->orderID << "," << root->item << "," << root->price << "," << root->qty << endl;
            savetoCSVHelperOrder(root->right, file);
        }
    }

    void savetoCSVOrder() {
        ofstream file("orders.csv", ios::trunc);
        if (!file.is_open()) {
            cerr << "Error: Could not open orders.csv" << endl;
            return;
        }
        savetoCSVHelperOrder(root, file);
        file.close();
    }

  void loadfromFileOrder() {
    ifstream file("orders.csv");
    string line;

    if (!file.is_open()) {
        cerr << "Error: Could not open orders.csv" << endl;
        return;
    }
    
    while (getline(file, line)) {
        stringstream ss(line);
        string orderID, item, price, qty;

        getline(ss, orderID, ',');
        getline(ss, item, ',');
        getline(ss, price, ',');
        getline(ss, qty, ',');

        node* newOrder = createNewItemOrder(stoi(orderID),item,stof(price),stoi(qty));
        root = addnewitemOrder(root, newOrder);
    }
    file.close();
}

public:
    manageOrder() : root(nullptr) {
        loadfromFileOrder();
    }

    void addnewitemOrder(int orderID, string item, float price, int qty) {
        node* newOrder = createNewItemOrder(orderID, item, price, qty);
        root = addnewitemOrder(root, newOrder);
        savetoCSVOrder();
    }

    void removeOrder(int ID) {
        root = deleteOrder(root, ID);
        savetoCSVOrder();
    }

    node* searchOrder(int ID) {
        return searchID(root, ID);
    }

    void updateOrderItemName(int ID, string NewitemName) {
        node* order = searchID(root, ID);
        if (order == nullptr) {
            cout << "Error: Order with ID " << ID << " does not exist!" << endl;
            return;
        }
        order->item = NewitemName;
        savetoCSVOrder();
        cout << "Order updated successfully." << endl;
    }

    void updateOrderPrice(int ID, float NewPrice) {
        node* order = searchID(root, ID);
        if (order == nullptr) {
            cout << "Error: Order with ID " << ID << " does not exist!" << endl;
            return;
        }
        order->price = NewPrice;
        savetoCSVOrder();
        cout << "Order updated successfully." << endl;
    }

    void updateOrderQuantity(int ID, int Newqty) {
        node* order = searchID(root, ID);
        if (order == nullptr) {
            cout << "Error: Order with ID " << ID << " does not exist!" << endl;
            return;
        }
        order->qty = Newqty;
        savetoCSVOrder();
        cout << "Order updated successfully." << endl;
    }

    void viewAllOrder() {
        cout << "================================" << endl;
        cout << "\tView All Orders" << endl;
        cout << "================================" << endl;
        ViewAllOrderHelper(root);
    }

    void ViewAllOrderHelper(node* root) {
        if (root != nullptr) {
            ViewAllOrderHelper(root->left);
            cout << "Order ID: " << root->orderID << endl;
            cout << "Product Name: " << root->item << endl;
            cout << "Price: $" << root->price << endl;
            cout << "Quantity: " << root->qty << endl;
            cout << "================================" << endl;
            ViewAllOrderHelper(root->right);
        }
    }


};
#endif