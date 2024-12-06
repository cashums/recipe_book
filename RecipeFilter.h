// RecipeFilter.h

#pragma once

#include "Output.h"
#include "Recipe.h"

#include <string>
#include <vector>

using namespace std;

class RecipeFilter {
  public:
    // Filter recipes by ingredient
    static vector<Recipe *> filterByIngredient(const vector<Recipe *> &recipes, const string &ingredient);

    // Filtering page, which interacts with the user
    static void filteringPage(); // Declaration of filteringPage
};
