#pragma once

#include "Recipe.h"

#include <string>
#include <vector>

using namespace std;

// Already Added

class User{
public:
    User* logIn();
    User* signUp();

    void addSearchingHist(int&);
    void addFavorRecipe(int&);
    void readVecCSV();
    void writeVecCSV(vector<int>&);
    // void addFavorRecipe(vector<Recipe>&);

    string getUserName() {return userName;}
    string getUserPassword() {return password;}
    bool userExist(const string&, const string& password = "");

    User();
    User(string&, string&);
    ~User();

private:
    string userName = "";
    string password = "";
    vector<int> searchingHistory_vec;
    vector<int> favoriteRecipe_vec;

};