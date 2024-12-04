#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

class Ingredient {
private:
    int ingredientID;
    std::string name;
    int calsPerServing;
    char allergens; // Represents a single allergen code
    std::string dietRestrictions;

public:
    // Constructor
    Ingredient(int id, const std::string &name, int cals, char allergen, const std::string &diet);

    // Getters
    int getIngredientID() const;
    std::string getName() const;
    int getCalsPerServing() const;
    char getAllergens() const;
    std::string getDietRestrictions() const;

    // Methods
    double calculateCals(int servings) const;
    bool isAllergen(char allergenCode) const;
    bool isDietSuitable(const std::string &dietType) const;
    std::string getInfo() const;
};

#endif // INGREDIENT_H
