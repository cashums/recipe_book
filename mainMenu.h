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

    void handleAuthentication();

public:
    void start();
    void displayMenu();
    void handleChoice(int choice);
    MainMenu();
};