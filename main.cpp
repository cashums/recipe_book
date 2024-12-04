#include "User.h"
#include "Book.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;


void filteringPage(){}

bool userExist(const string & name, const string &password = ""){
    ifstream file("userInfo.csv");
    string line, existingUserName, existingPassword;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, existingUserName, ',');
        getline(ss, existingPassword, ',');
        
        if (existingUserName == name) {
            if (existingPassword == password) return true;
        }
    }
    return false;
}
User* logIn(){
    string userName, password;
    cout << "What's your user name: ";
    cin >> userName;
    cout << "What's your password: ";
    cin >> password;

    if (userExist(userName, password)) {
        cout << "Login successful! Welcome back, " << userName << "." << endl;
        User* new_user = new User(userName, password);
        // read the searching hist/ favorite recipes from the csv file into the vector 
        // -----------------------------------
        return new_user;
    } else {
        int user_input;
        cout << "Invalid username or password. Input 1 for sign up and 2 for log in: ";
        cin >> user_input;

        while (cin.fail() || (user_input != 1 && user_input != 2)) {
            cout << "Your input is invalid. Please input again: ";
            cin >> user_input;
        }

        if (user_input == 1) {
            signUp();
        } else if (user_input == 2) {
            logIn();
        }
    }
}


User* signUp(){
    string userName, password;
    cout << "What's your user name (please input letters/special characters/numbers without space): ";
    cin >> userName;
    cout << "What's your password (please input letters/special characters/numbers without space): ";
    cin >> password;

    // Check if the user already exists
    if (userExist(userName)) {
        int user_input;
        cout << "This user name is already being used. Input 1 for sign up and 2 for log in: ";
        cin >> user_input;

        while (cin.fail() || (user_input != 1 && user_input != 2)) {
            cout << "Your input is invalid. Please input again: ";
            cin >> user_input;
        }

        if (user_input == 1) {
            signUp();
        } else if (user_input == 2) {
            logIn();
        }
    }

    // Append the new user to the CSV file
    ofstream file("userInfo.csv", ios::app);
    file << userName << "," << password << "\n";
    file.close();

    cout << "Sign-up successful! You can now log in." << endl;

    User* new_user = new User(userName, password);
    return new_user;
}

User* authentication(int &userInput_int){
    while (cin.fail() || userInput_int != 1 || userInput_int != 2){
        cout << "Your input is invalid. Please input again: ";
        cin >> userInput_int;
    }
    if (userInput_int == 1){ 
        return signUp();
    }else if(userInput_int == 2){ 
        return logIn(); 
    }
}

void mainMenu(User &user){
    cout << "------------Welcome to Recipe Book------------" << endl
         << "Here is your personalized daily menu: " << endl;
    // I want to call the generateMenu and displayMenu, both functions are in the
    // sub class "DailyMenu" which derived from the User class
}

int main(){
    Book book;

    User* user_ptr = nullptr;
    int userInput_int = 0;
    string userName, password;

    cout << "Welcome to the Recipe Book!" << endl
         << "Would you like to sign up for a new account or log in?" << endl
         << "(enter 1 for sign up, 2 for log in): ";
    cin >> userInput_int;

    user_ptr = authentication(userInput_int);

    User& user = *user_ptr;

    mainMenu(user);
    
    return 1;
}