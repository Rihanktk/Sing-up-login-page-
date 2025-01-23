#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Declare a global unordered map to store username-password pairs
unordered_map<string, string> userDatabase;

// Function to handle user sign-up
void signUp() {
    string username, password;
    
    cout << "Enter a username: ";
    cin >> username;
    
    // Check if the username already exists
    if (userDatabase.find(username) != userDatabase.end()) {
        cout << "Username already exists! Try again." << endl;
        return;
    }
    
    cout << "Enter a password: ";
    cin >> password;
    
    // Store the username and password in the database
    userDatabase[username] = password;
    
    cout << "Sign-up successful!" << endl;
}

// Function to handle user login
void login() {
    string username, password;
    
    cout << "Enter your username: ";
    cin >> username;
    
    // Check if the username exists
    if (userDatabase.find(username) == userDatabase.end()) {
        cout << "Username not found! Try again." << endl;
        return;
    }
    
    cout << "Enter your password: ";
    cin >> password;
    
    // Validate the password
    if (userDatabase[username] == password) {
        cout << "Login successful!" << endl;
    } else {
        cout << "Incorrect password! Try again." << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\nWelcome! Please select an option:" << endl;
        cout << "1. Sign Up" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                signUp();
                break;
            case 2:
                login();
                break;
            case 3:
                cout << "Exiting the system." << endl;
                return 0;
            default:
                cout << "Invalid option! Please try again." << endl;
        }
    }

    return 0;
}