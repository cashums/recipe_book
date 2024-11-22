#include "User.h"
#include "Book.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>

// Destructor
User::~User() {
    // Cleanup logic here (if any)
}

// Public Methods

void User::signUp(const std::string& name, const int& id) {
    // Implementation for user signup
    userName = name;
    userID = id;
}

bool User::logIn(const std::string& name, const int& id) {
    // Implementation for user login
    authentication(name, id);
}

void User::logOut() {
    // Implementation for user logout
}

void User::displayHist() {
    // Implementation to display search history
    for (Recipe recipe : searchingHistory_vec) {
        if (searchingHistory_vec.empty()) { // Check if the pointer is not null
            std::cout << "Start looking for the recipe of your favorite food!" << std::endl;
        } else {
            recipe.viewRecipe(); // Assuming Recipe has a viewRecipe() method
        }
    }
}

void User::addSearchingHist(int &recipeId, Book& book) {
    // Implementation to add to search history
    auto it = book.recipeMap.find(recipeId);
    if (it != book.recipeMap.end()) searchingHistory_vec.push_back(it->second);
}

void User::displayFav() {
    // Implementation to display favorite recipes
    for (Recipe recipe : favoriteRecipe_vec) {
        if (favoriteRecipe_vec.empty()) { // Check if the pointer is not null
            std::cout << "Start looking for the recipe of your favorite food!" << std::endl;
        } else {
            recipe.viewRecipe(); // Assuming Recipe has a viewRecipe() method
        }
    }
}

void User::addFavorRecipe(int &recipeId, Book& book) {
    // Implementation to add a recipe to favorites
    auto it = book.recipeMap.find(recipeId);
    if (it != book.recipeMap.end()) {
        favoriteRecipe_vec.push_back(it->second); 
    } else {
        std::cout << "Fail to add to Favorites because recipe with ID " << recipeId << " not found." << std::endl;
    }
}

// Private Methods

bool User::authentication(const std::string& name, const int& id) const {
    // Implementation for user authentication
    if (userName == name && userID == id){
        cout << "Log in successfully!";
        return true;
    }else{
        cout << "fail to log in, please try again.";
        return false; // Placeholder return value
    }
}

