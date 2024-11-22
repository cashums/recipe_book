#pragma once

#include "Book.h"

#include <string>
#include <vector>

class User{
    string userName = "";
    int userID = 0;
    void signUp(const string&, const int&);
    bool logIn(const string&, const int&);
    void logOut();

    void displayHist();
    void addSearchingHist(int &, Book& book);

    void displayFav();
    void addFavorRecipe(int &, Book& book);

    ~User();

private:
    string password;
    bool authentication(const string&, const int&)const;
    vector<Recipe> searchingHistory_vec;
    vector<Recipe> favoriteRecipe_vec;
    string password;
};