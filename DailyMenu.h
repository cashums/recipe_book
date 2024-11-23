#pragma once

#include "User.h"

#include <vector>

class DailyMenu : public User{
    vector<Recipe> dailyMenu(3);
    vecotr<Recipe> generateMenu(vector<Recipe>&, vector<Recipe>&);
}