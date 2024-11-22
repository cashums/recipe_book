#pragma once

#include "Book.h"

#include <string>
#include <vector>

class User{
    void signUp(const string&, const int&);
    bool logIn(const string&, const int&);
    void logOut();

    void displayHist();
    void displayFav();

    ~User();

private:
    string userName = "";
    int userID = 0;
    string password;
    bool authentication(const string&, const int&)const;
    vector<Recipe> searchingHistory_vec;
    vector<Recipe> favoriteRecipe_vec;

    void addSearchingHist(Recipe*);Lydi
    void addFavorRecipe(Recipe*);
};