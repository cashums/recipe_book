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
        /*below is my concern (lydia): (based on the perspective from the datasest)
        1. ingredients is a super long string, maybe vector is not a perfect fit
        2. I need a subclass for nutrition. 
        */
    public:
        void editRecipe();
        void viewRecipe();
        void deleteRecipe();
};