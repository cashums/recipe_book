#pragma once

#include "Recipe.h"

#include <string>
#include <vector>

using namespace std;

class User{
public:
    bool logIn(string&, string&);
    void logOut();
    void addSearchingHist(Recipe&);
    void addFavorRecipe(Recipe&);
    void display(vector<Recipe>&);
    string getUserName() {return userName;}
    string getUserPassword() {return password;}

    User();
    User(string&, string&);

private:
    string userName = "";
    string password;
    bool authentication(const string&, const string&)const;
    vector<Recipe> searchingHistory_vec;
    vector<Recipe> favoriteRecipe_vec;

};