#include "Ingredient.h"



// Constructor
Ingredient::Ingredient(int id, const std::string &name, int cals, char allergen, const std::string &diet)
    : ingredientID(id), name(name), calsPerServing(cals), allergens(allergen), dietRestrictions(diet) {}

// Getters
int Ingredient::getIngredientID() const {
    return ingredientID;
}

std::string Ingredient::getName() const {
    return name;
}

int Ingredient::getCalsPerServing() const {
    return calsPerServing;
}

char Ingredient::getAllergens() const {
    return allergens;
}

std::string Ingredient::getDietRestrictions() const {
    return dietRestrictions;
}

// Methods
double Ingredient::calculateCals(int servings) const {
    return calsPerServing * servings;
}

bool Ingredient::isAllergen(char allergenCode) const {
    return allergens == allergenCode;
}

bool Ingredient::isDietSuitable(const std::string &dietType) const {
    return dietRestrictions.find(dietType) != std::string::npos;
}

std::string Ingredient::getInfo() const {
    return "Ingredient ID: " + std::to_string(ingredientID) +
           "\nName: " + name +
           "\nCalories per Serving: " + std::to_string(calsPerServing) +
           "\nAllergens: " + allergens +
           "\nDiet Restrictions: " + dietRestrictions;
}
