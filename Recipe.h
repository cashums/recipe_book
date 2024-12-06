#pragma once

using namespace std;

#include <string>
#include <vector>
#include <map>

// Already Added: 

class Recipe
{
private:
    int recipeID;
    string recipeName;
    vector<string> ingredientNames, ingredientQuantities, instructions, tags;
    int calories;
    string cuisine, foodType;
    int prepTime, cookTime, totalTime;
    // double rating;
public:
    string rawNutritionData;
    //Recipe();
    Recipe(string name, vector<string> ingredientNames, vector<string> ingredientQuantities, vector<string> directions, int calories, vector<string> tags, string cuisine, string foodType, int prepTime, int cookTime);
    void setRecipeID(int id);
    void viewRecipe();
    vector<string> getIngredientNames();
    vector<string> getIngredientQuantities();
    vector<string> getInstructions();
    vector<string> getTags();
    string getName();
    string getCuisine();
    string getFoodType();
    int getprepTime();
    int getCookTime();
    int getTotalTime();
    int getrecipeID();
    int getCalories();
    ~Recipe();
};