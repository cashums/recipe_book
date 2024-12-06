#pragma once

#include "Book.h"
#include "User.h"
#include "dataParser.h"
#include "RecipeFilter.h"

#include <string>
#include <iostream>
#include <sstream>

// No Destructor Needed

using namespace std;

class MainMenu
{
private:
    Book book;
    User currentUser;
    bool isRunning;
    RecipeFilter r;

    vector<int> fav_recipe_vec;
    vector<int> search_hist_vec;
    void handleAuthentication();

public:
    void start();
    void displayMenu();
    void handleChoice(int choice);
    MainMenu();
};