#include "Ingredient.h"

// Constructor: Initialize ingredient attributes
Ingredient::Ingredient(int id, const std::string& n, int cal, char all, const std::string& diet)
    : ingredientID(id), name(n), calPerServing(cal), allergens(all), dietRestrictions(diet) {}

// Calculate the total calories for one serving
double Ingredient::calculateCals() const {
    return static_cast<double>(calPerServing);
}

// Check if the ingredient contains a specific allergen
bool Ingredient::isAllergen(char allergen) const {
    return allergens == allergen;
}

// Check if the ingredient matches a specific dietary restriction
bool Ingredient::isDietSuitable(const std::string& diet) const {
    return dietRestrictions == diet;
}

// Retrieve a formatted string containing information about the ingredient
std::string Ingredient::getInfo() const {
    return "Ingredient ID: " + std::to_string(ingredientID) +
           ", Name: " + name +
           ", Calories per Serving: " + std::to_string(calPerServing) +
           ", Allergen: " + std::string(1, allergens) +
           ", Diet Restrictions: " + dietRestrictions;
}

// Getter for Ingredient ID
int Ingredient::getIngredientID() const {
    return ingredientID;
}

// Getter for Name
std::string Ingredient::getName() const {
    return name;
}

// Getter for Calories per Serving
int Ingredient::getCaloriesPerServing() const {
    return calPerServing;
}

// Getter for Allergens
char Ingredient::getAllergens() const {
    return allergens;
}

// Getter for Diet Restrictions
std::string Ingredient::getDietRestrictions() const {
    return dietRestrictions;
}
