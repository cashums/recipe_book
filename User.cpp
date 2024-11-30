#include "User.h"
#include "Recipe.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

User::User(){
    userName = "";
    userID = 0;
    password = "";
}

// Public Methods

void User::signUp(string& name, int& id) {
    // Implementation for user signup
    userName = name;
    userID = id;
}

bool User::logIn(string& name, int& id) {
    // Implementation for user login
    authentication(name, id);
}

void User::logOut() {
    // Implementation for user logout
}

void User::display(vector<Recipe>& myVec) {
    // Implementation to display search history
    for (Recipe recipe : myVec) {
        if (myVec.empty()) { // Check if the pointer is not null
            cout << "Start looking for the recipe of your favorite food!" << std::endl;
        } else {
            recipe.viewRecipe(); // Assuming Recipe has a viewRecipe() method
        }
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

// Private Methods

bool User::authentication(const std::string& name, const int& id) const {
    // Implementation for user authentication
    if (userName == name && userID == id){
        cout << "Log in successfully!";
        return true;
    }else{
        cout << "fail to log in, please try again or sign up a new account.";
        return false; // Placeholder return value
    }
}

