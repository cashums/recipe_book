#pragma once
#include "Ingredient.h"
using namespace std;

#include <string>
#include <vector>
#include <map>

class Recipe {
    private:
        int recipeID;
        string recipeName;
        vector<Ingredient> ingredients; 
        int totalCals;
        string cuisine;
        vector<string> steps;
        double rating;
        string instructions;
        string url;
    public:
        string rawNutritionData;
        void editRecipe(); // im confused by edit which part of the recipe
        void viewRecipe(); 
        void deleteRecipe();
        // I think we may need a constructor to read the data into objects, including 
        // all the attributes it should contain
        // also a destructor...
};