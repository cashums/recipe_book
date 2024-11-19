#pragma once
#include "Ingredient.h"
using namespace std;

#include <string>
#include <vector>

class Recipe {
    private:
        int recipeID;
        string recipeName;
        vector<Ingredient> ingredients;
        int totalCals;
        string cuisine;
        vector<string> steps;
        double rating;
    public:
        void editRecipe();
        void viewRecipe();
        void deleteRecipe();
};