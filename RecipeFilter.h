// RecipeFilter.h

#pragma once

#include "Recipe.h"
#include <vector>
#include <string>

using namespace std;

class RecipeFilter {
public:
    // Filter recipes by ingredient
    static vector<Recipe*> filterByIngredient(const vector<Recipe*>& recipes, const string& ingredient);

    // Filtering page, which interacts with the user
    static void filteringPage(); // Declaration of filteringPage
};
