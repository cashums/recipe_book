#pragma once

#include "Book.h"
#include "User.h"
#include "dataParser.h"

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class MainMenu
{
private:
    Book book;
    User currentUser;
    bool isRunning;

    void handleAuthentication();

public:
    void start();
    void displayMenu();
    void handleChoice(int choice);
    MainMenu();
};