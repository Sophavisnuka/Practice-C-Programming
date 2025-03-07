#include <iostream>
#include <string>
#include <conio.h> 
using namespace std;

class AdminLogin {
private:
    string adminUsername = "admin"; 
    string adminPassword = "password123"; 
public:
    bool authenticate(string username, string password) {
        if (username == adminUsername && password == adminPassword) {
            return true; 
        }
        return false;
    }

    string getHiddenPassword() {
        string password;
        char ch;

        cout << "Enter Admin Password: ";
        while ((ch = _getch()) != '\r') { 
            if (ch == '\b' && !password.empty()) { 
                cout << "\b \b";
                password.pop_back();
            } else if (ch != '\b') {
                cout << '*';
                password += ch;
            }
        }
        cout << endl;
        return password;
    }

    void login() {
        string username, password;

        cout << "Enter Admin Username: ";
        cin >> username;
        password = getHiddenPassword();

        if (authenticate(username, password)) {
            cout << "Login Successful! Welcome, Admin." << endl;
            system("pause");
        } else {
            cout << "Invalid Password." << endl;
            exit(10);
        }
    }
};

