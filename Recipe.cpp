#include "Recipe.h" 
#include <iostream>
using namespace std;

// Destructor Added

// default constructor assigning a 0 or blank to all inputs if not specified by user
Recipe::Recipe(string name = "", vector<string> ingredientNames = {}, vector<string> ingredientQuantities = {}, vector<string> directions = {}, int calories = 0, vector<string> tags = {}, string cuisine = "", string foodType = "", int prepTime = 0, int cookTime = 0)
{
    recipeName = name;
    this->ingredientNames = ingredientNames;
    this->ingredientQuantities = ingredientQuantities;
    instructions = directions;
    this->calories = calories;
    this->tags = tags;
    this->cuisine = cuisine;
    this->foodType = foodType;
    this->prepTime = prepTime;
    this->cookTime = cookTime;
    totalTime = (prepTime + cookTime);
}

void Recipe::setRecipeID(int id) 
{
    this->recipeID = id;
}

/*Recipe::Recipe(string name, vector<string> ingredientNames, vector<string> ingredientQuantities, vector<string> directions, int calories, vector<string> tags, string cuisine, string foodType, int prepTime, int cookTime) {
    recipeName = name;
    this->ingredientNames = ingredientNames;
    this->ingredientQuantities = ingredientQuantities;
    instructions = directions;
    this->calories = calories;
    this->tags = tags;
    this->cuisine = cuisine;
    this->foodType = foodType;
    this->prepTime = prepTime;
    this->cookTime = cookTime;
    totalTime = (prepTime + cookTime);
}*/

void Recipe::viewRecipe()
{
    // Display the recipe details
    cout << "-----------------------------" << endl;
    cout << "Recipe ID: " << recipeID << endl;
    cout << "Recipe Name: " << recipeName << endl;
    cout << "Cuisine: " << cuisine << endl;
    cout << "Type: " << foodType << endl;
    cout << "Calories: " << calories << endl;
    cout << "Preparation Time: " << prepTime << " minutes" << endl;
    cout << "Cooking Time: " << cookTime << " minutes" << endl;
    cout << "Total Time: " << totalTime << " minutes" << endl;
    cout << "-----------------------------" << endl;

    // Display ingredients
    cout << "Ingredients:" << endl;
    for (size_t i = 0; i < ingredientNames.size(); i++)
    {
        cout << "- " << ingredientNames[i] << ": " << ingredientQuantities[i] << endl;
    }

    // Display instructions
    cout << "Instructions:" << endl;
    for (size_t i = 0; i < instructions.size(); i++)
    {
        cout << i + 1 << ". " << instructions[i] << endl;
    }

    // Display tags
    cout << "Tags: ";
    for (size_t i = 0; i < tags.size(); i++)
    {
        cout << tags[i];
        if (i < tags.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;

    cout << "-----------------------------" << endl;
}

string Recipe::getName()
{
    return this->recipeName;
}

vector<string> Recipe::getIngredientNames()
{
    return this->ingredientNames;
}
vector<string> Recipe::getIngredientQuantities()
{
    return this->ingredientQuantities;
}
vector<string> Recipe::getInstructions()
{
    return this->instructions;
}
vector<string> Recipe::getTags()
{
    return this->tags;
}
string Recipe::getCuisine()
{
    return this->cuisine;
}
string Recipe::getFoodType()
{
    return this->foodType;
}
int Recipe::getprepTime()
{
    return this->prepTime;
}
int Recipe::getCookTime()
{
    return this->cookTime;
}
int Recipe::getTotalTime()
{
    return this->totalTime;
}
int Recipe::getrecipeID()
{
    return this->recipeID;
}

int Recipe::getCalories()
{
    return this->calories;
}

// Destructor (no extra cleanup needed)
Recipe::~Recipe()
{
}
