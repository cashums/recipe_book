#pragma once

#include "User.h"
#include "Recipe.h"

#include <vector>

class DailyMenu : public User{
    vector<Recipe> dailyMenu[3];
    void generateMenu(vector<Recipe>&, vector<Recipe>&);
    void displayMenu(Recipe&);
};