#pragma once
#include "User.h"

#include <vector>

class DailyMenu : public User{
    vector<Recipe> dailyMenu(3);
    void generateMenu(vector<Recipe>&, vector<Recipe>&);
public:


}