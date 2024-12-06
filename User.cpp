#include "User.h"
#include "Recipe.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// Already inside
User::User(){
    userName = "";
    password = "";
}

User::User(string& userName, string& password){
    this->userName = userName;
    this->password = password;
}
// Public Methods

bool User::userExist(const string& name, const string& password) {
    ifstream file("users.csv");

    if (!file.is_open()) {
        cerr << "Error: Could not open the file 'users.csv'." << endl;
        return false; 
    }

    string line, existingUserName, existingPassword;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, existingUserName, ',');
        getline(ss, existingPassword, ',');

        if (existingUserName == name && existingPassword == password)  return true;
    }

    return false;
}


User* User::signUp(){
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

    // write the new user to the csv file
    ofstream file("users.csv", ios::app);
    file << userName << "," << password << "\n";
    file.close();

    cout << "Sign-up successful!" << endl;
    User* new_user = new User(userName, password);
    return new_user;
}


User* User::logIn() {
    cout << "What's your user name (please input letters/special characters/numbers without space): ";
    cin >> userName;
    cout << "What's your password (please input letters/special characters/numbers without space): ";
    cin >> password;

    if (userExist(userName, password)) {
        cout << "Login successful! Welcome back, " << userName << "." << endl;
        User* new_user = new User(userName, password);
        return new_user;
    }else{
        int user_input;
        cout << "Invalid username or password, please try again. Input 1 for sign up and 2 for log in: ";
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
    cout << "Error: Unable to log in." << endl;
    return nullptr;
}

void User::logOut() {
    // Implementation for user logout
}

void User::display(vector<Recipe>& myVec) {
    // Implementation to display search history
    if (myVec.empty()) {
        cout << "Start looking for the recipe of your favorite food!" << endl;
        return;
    }
    for (int i = 0; i < myVec.size(); i++) {
        myVec[i].viewRecipe(); // Assuming Recipe has a viewRecipe() method
    }
}

void User::addSearchingHist(Recipe& hist) {
    // Implementation to add to search history
    searchingHistory_vec.push_back(hist);
}

void User::addFavorRecipe(Recipe& fav) {
    // Implementation to add a recipe to favorites
    favoriteRecipe_vec.push_back(fav);
}

