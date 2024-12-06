#pragma once

#include "User.h"
#include "Recipe.h"
#include "Output.h"

#include <vector>

// No destructor is Needed Checked: 
class DailyMenu : public User{
private:
    vector<int> dailyMenu{0,0,0};
public:
    void generateMenu(vector<Recipe*>&, vector<int>&, vector<int>&);
    vector<int> getDailyMenu() {return dailyMenu;}
    void printRecipe(const vector<int>& vec, const vector<Recipe*>& book) override;
};