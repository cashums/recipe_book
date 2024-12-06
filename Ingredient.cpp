// File: Ingredient.cpp

#include "Ingredient.h"
#include <algorithm>

// No destructor Needed

// Constructor
Ingredient::Ingredient(int id, const std::string& name, int calories, const std::string& allergens, const std::string& restrictions)
    : ingredientID(id), name(name), calsPerServing(calories), allergens(allergens), dietRestrictions(restrictions) {}

// Accessor Methods
int Ingredient::getIngredientID() const { return ingredientID; }
std::string Ingredient::getName() const { return name; }
int Ingredient::getCaloriesPerServing() const { return calsPerServing; }
std::string Ingredient::getAllergens() const { return allergens; }
std::string Ingredient::getDietRestrictions() const { return dietRestrictions; }

// Mutator Methods
void Ingredient::setIngredientID(int id) { ingredientID = id; }
void Ingredient::setName(const std::string& name) { this->name = name; }
void Ingredient::setCaloriesPerServing(int calories) { calsPerServing = calories; }
void Ingredient::setAllergens(const std::string& allergens) { this->allergens = allergens; }
void Ingredient::setDietRestrictions(const std::string& restrictions) { dietRestrictions = restrictions; }

// Functional Methods
double Ingredient::calculateCals(int servings) const {
    return servings * calsPerServing;
}

bool Ingredient::isAllergen(const std::string& allergen) const {
    return allergens.find(allergen) != std::string::npos;
}

bool Ingredient::isDietSuitable(const std::string& dietType) const {
    return dietRestrictions.find(dietType) != std::string::npos;
}

void Ingredient::getInfo() const {
    std::cout << "Ingredient ID: " << ingredientID << "\n"
              << "Name: " << name << "\n"
              << "Calories per Serving: " << calsPerServing << "\n"
              << "Allergens: " << allergens << "\n"
              << "Diet Restrictions: " << dietRestrictions << "\n";
}

// Filtering Methods
std::vector<Ingredient> Ingredient::filterByAllergens(const std::vector<Ingredient>& ingredients, const std::string& allergen) {
    std::vector<Ingredient> filtered;
    for (const auto& ingredient : ingredients) {
        if (!ingredient.isAllergen(allergen)) { // Keep ingredients that do not contain the allergen
            filtered.push_back(ingredient);
        }
    }
    return filtered;
}

std::vector<Ingredient> Ingredient::filterByDietRestrictions(const std::vector<Ingredient>& ingredients, const std::string& restriction) {
    std::vector<Ingredient> filtered;
    for (const auto& ingredient : ingredients) {
        if (ingredient.isDietSuitable(restriction)) {
            filtered.push_back(ingredient);
        }
    }
    return filtered;
}

// Favorites Methods
void Ingredient::addFavoriteRecipe(const std::string& recipe) {
    favoriteRecipes.push_back(recipe);
    std::cout << "Recipe added to favorites: " << recipe << "\n";
}

void Ingredient::removeFavoriteRecipe(const std::string& recipe) {
    auto it = std::remove(favoriteRecipes.begin(), favoriteRecipes.end(), recipe);
    if (it != favoriteRecipes.end()) {
        favoriteRecipes.erase(it, favoriteRecipes.end());
        std::cout << "Recipe removed from favorites.\n";
    } else {
        std::cout << "Recipe not found in favorites.\n";
    }
}

void Ingredient::listFavoriteRecipes() const {
    std::cout << "Favorite Recipes:\n";
    for (const auto& recipe : favoriteRecipes) {
        std::cout << " - " << recipe << "\n";
    }
}
