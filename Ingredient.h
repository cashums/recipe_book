// File: Ingredient.h

#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include <vector>
#include <iostream>

class Ingredient {
private:
    int ingredientID;          // Unique identifier for the ingredient
    std::string name;          // Name of the ingredient
    int calsPerServing;        // Calories per serving
    std::string allergens;     // Allergens (e.g., gluten, dairy)
    std::string dietRestrictions; // Diet restrictions (e.g., Vegetarian, Vegan)

    // Favorite recipes
    std::vector<std::string> favoriteRecipes;

public:
    // Constructor
    Ingredient(int id, const std::string& name, int calories, const std::string& allergens, const std::string& restrictions);

    // Accessor and Mutator Methods
    int getIngredientID() const;
    std::string getName() const;
    int getCaloriesPerServing() const;
    std::string getAllergens() const;
    std::string getDietRestrictions() const;

    void setIngredientID(int id);
    void setName(const std::string& name);
    void setCaloriesPerServing(int calories);
    void setAllergens(const std::string& allergens);
    void setDietRestrictions(const std::string& restrictions);

    // Functional Methods
    double calculateCals(int servings) const;
    bool isAllergen(const std::string& allergen) const;
    bool isDietSuitable(const std::string& dietType) const;
    void getInfo() const;

    // Filtering Methods
    static std::vector<Ingredient> filterByAllergens(const std::vector<Ingredient>& ingredients, const std::string& allergen);
    static std::vector<Ingredient> filterByDietRestrictions(const std::vector<Ingredient>& ingredients, const std::string& restriction);

    // Favorites Methods
    void addFavoriteRecipe(const std::string& recipe);
    void removeFavoriteRecipe(const std::string& recipe);
    void listFavoriteRecipes() const;
};

#endif // INGREDIENT_H
