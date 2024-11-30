#pragma once

#include "Recipe.h"

#include <string>
#include <vector>

using namespace std;

class User{
public:
    void signUp(string&, int&);
    bool logIn(string&, int&);
    void logOut();
    void addSearchingHist(Recipe&);
    void addFavorRecipe(Recipe&);
    void display(vector<Recipe>&);

    User();

private:
    string userName = "";
    int userID = 0;
    string password;
    bool authentication(const string&, const int&)const;
    vector<Recipe> searchingHistory_vec;
    vector<Recipe> favoriteRecipe_vec;

};