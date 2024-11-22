#pragma once
//#include "Ingredient.h"
using namespace std;

#include <string>
#include <vector>
#include <map>

class Recipe {
    private:
        int recipeID;
        string recipeName;
        vector<string> ingredientNames, ingredientQuantities, instructions, tags;
        int calories;
        string cuisine, foodType;
        int prepTime, cookTime, totalTime;
        //double rating;
        
    public:
        string rawNutritionData;
        Recipe();
        Recipe(string name, vector<string> ingredientNames, vector<string> ingredientQuantities, vector<string> directions, int calories, vector<string> tags, string cuisine, string foodType, int prepTime, int cookTime);
        void editRecipe(); // im confused by edit which part of the recipe
        void viewRecipe(); 
        void deleteRecipe();
        string getName();
        // also a destructor...
};