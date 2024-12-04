#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

// Represents an Ingredient used in recipes
class Ingredient {
private:
    int ingredientID;                // Unique identifier for the ingredient
    std::string name;                // Name of the ingredient
    int calPerServing;               // Calories per serving of the ingredient
    char allergens;                  // A character representing the allergen, if any
    std::string dietRestrictions;    // Dietary restrictions (e.g., vegetarian, vegan, etc.)

public:
    // Constructor
    Ingredient(int id, const std::string& n, int cal, char all, const std::string& diet);

    // Calculates the total calories for one serving
    double calculateCals() const;

    // Checks if the ingredient contains a specific allergen
    bool isAllergen(char allergen) const;

    // Checks if the ingredient is suitable for a specific diet
    bool isDietSuitable(const std::string& diet) const;

    // Retrieves formatted information about the ingredient
    std::string getInfo() const;

    // Getters for the class attributes
    int getIngredientID() const;
    std::string getName() const;
    int getCaloriesPerServing() const;
    char getAllergens() const;
    std::string getDietRestrictions() const;
};

#endif // INGREDIENT_HPP
