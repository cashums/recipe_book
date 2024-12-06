#pragma once

#include "Recipe.h"

#include <string>
#include <vector>

using namespace std;

// Already Added

class User{
public:
    User* logIn();
    void logOut();
    User* signUp();
    void addSearchingHist(Recipe&);
    void addFavorRecipe(Recipe&);
    void addSearchingHist(vector<Recipe>&);
    void addFavorRecipe(vector<Recipe>&);
    void display(vector<Recipe>&);
    string getUserName() {return userName;}
    string getUserPassword() {return password;}
    bool userExist(const string&, const string& password = "");

    User();
    User(string&, string&);

private:
    string userName = "";
    string password = "";
    vector<Recipe> searchingHistory_vec;
    vector<Recipe> favoriteRecipe_vec;

};