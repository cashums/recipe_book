#pragma once

#include "User.h"
#include "Recipe.h"
#include <vector>

// No destructor is Needed Checked: 
class DailyMenu : public User{
    int caloryTracker;
public:
    vector<Recipe> dailyMenu[3];
    void generateMenu(Book&, vector<Recipe>&, vector<Recipe>&);
    void displayMenu(vector<Recipe> &);
};