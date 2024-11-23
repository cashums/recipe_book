#pragma once

#include "Book.h"

#include <string>
#include <vector>

using namespace std;

class User{
    void signUp(string＆, int&);
    bool logIn(string&, int&);
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

    void addSearchingHist(Recipe&);
    void addFavorRecipe(Recipe&);
};