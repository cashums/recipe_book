#pragma once

#include <vector>

class Book{
    vector<Recipe*> allRecipes;
public:
    vector<Recipe*> getRecipe(){return allRecipes;}
};