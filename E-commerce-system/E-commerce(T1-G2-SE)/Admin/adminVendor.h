#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

class manageVendor {

private:
    struct node {
        int ID;
        string username;
        string password;
        float salary;

        node* left;
        node* right;
    };
    node* root;

    bool isDuplicateID(node* root, int ID) {
        if (root == nullptr) {
            return false;
        }
        if (root->ID == ID) {
            return true;
        }
        if (root->ID > ID) {
            return isDuplicateID(root->left, ID);
        }
        return isDuplicateID(root->right, ID);
    }


    node* createVendor(int ID, string username, string password, float salary) {
        node* newVendor = new node;
        newVendor->ID = ID;
        newVendor->username = username;
        newVendor->password = password;
        newVendor->salary = salary;
        newVendor->left = nullptr;
        newVendor->right = nullptr;
        return newVendor;
    }

    node* addVendor(node* root, node* newVendor) {
        if (root == nullptr) {
            return newVendor;
        }
        if (root->ID > newVendor->ID) {
            root->left = addVendor(root->left, newVendor);
        } else if (root->ID < newVendor->ID) {
            root->right = addVendor(root->right, newVendor);
        }
        return root;
    }
    

 

    node* searchID(node* root, int ID) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->ID == ID) {
            return root;
        }
        if (root->ID > ID) {
            return searchID(root->left, ID);
        }
        return searchID(root->right, ID);
    }

    node* deleteVendor(node* root, int ID) {
        if (root == nullptr) {
            return root;
        }
        if (root->ID > ID) {
            root->left = deleteVendor(root->left, ID);
        } else if (root->ID < ID) {
            root->right = deleteVendor(root->right, ID);
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
            root->ID = temp->ID;
            root->right = deleteVendor(root->right, temp->ID);
        }
        return root;
    }

    void savetoCSVHelperVendor(node* root, ofstream& file) {
        if (root != nullptr) {
            savetoCSVHelperVendor(root->left, file);
            file << root->ID << "," << root->username << "," << root->password << "," << root->salary << endl;
            savetoCSVHelperVendor(root->right, file);
        }
    }

    void savetoCSVVendor(node* root) {
        ofstream file("Vendors.csv", ios::trunc);
        if (!file.is_open()) {
            cerr << "Error: Could not open vendors.csv" << endl;
            return;
        }
        savetoCSVHelperVendor(root, file);
        file.close();
    }

    void loadfromFileVendor() {
        ifstream file("vendors.csv");
        string line;

        if (!file.is_open()) {
            cerr << "Error: Could not open vendors.csv" << endl;
        }
        while (getline(file, line)) {
            stringstream ss(line);
            string ID, username, password, salary;

            getline(ss, ID, ',');
            getline(ss, username, ',');
            getline(ss, password, ',');
            getline(ss, salary, ',');

            node* newVendor = createVendor(stoi(ID), username, password, stof(salary));
            root = addVendor(root, newVendor);
        }
        file.close();
    }



public:
    manageVendor() {
        root = nullptr;
        loadfromFileVendor();
    }

    void addVendor(int ID, string username, string password, float salary) {
        if (isDuplicateID(root, ID)) {
            cout << "Error: Vendor with ID " << ID << " already exists!" << endl;
            return;
        }
        node* newVendor = createVendor(ID, username, password, salary);
        root = addVendor(root, newVendor);
        savetoCSVVendor(root);
    }


    void removeVendor(int ID) {
        root = deleteVendor(root, ID);
        savetoCSVVendor(root);
    }

    void viewAllVendor() {
        cout << "================================" << endl;
        cout << "\tView Info Vendor" << endl;
        cout << "================================" << endl;
        analyzeVendorHelper(root);
    }

    void analyzeVendorHelper(node* root) {
        if (root != nullptr) {
            analyzeVendorHelper(root->left);
            cout << "Vendor ID: " << root->ID << endl;
            cout << "Name: " << root->username << endl;
            cout << "Salary: $" << root->salary << endl;
            cout << "================================" << endl;
            analyzeVendorHelper(root->right);
        }
    }

    node* searchInfoVendor(int ID) {
        return searchID(root, ID);
    }

    void updateSalaryVendor(int ID, float newSalary) {
        node* vendor = searchID(root, ID);
        if (vendor == nullptr) {
            cout << "Error: Vendor with ID " << ID << " does not exist!" << endl;
            return;
        }
        vendor->salary = newSalary;
        savetoCSVVendor(root);
        cout << "Vendor salary updated successfully." << endl;
    }

};
