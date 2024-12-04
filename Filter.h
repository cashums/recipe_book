#ifndef FILTER_H
#define FILTER_H

#include <vector>
#include <string>
#include "Recipe.h" // Assuming Recipe is defined elsewhere

class Filter {
private:
    std::vector<Recipe> result;  // List of recipes after filtering
    int relevant;               // Number of relevant recipes found

public:
    // Constructor
    Filter();

    // Apply filters based on constraints (e.g., tags, cuisine type, allergens, etc.)
    void applyFilters(const std::vector<Recipe>& allRecipes, 
                      const std::string& constraintType, 
                      const std::string& constraintValue);

    // Add a single recipe to the filtered results
    void addRecipe(const Recipe& recipe);

    // Display the filtered results
    void displayResult() const;

    // Get the filtered results
    std::vector<Recipe> getResult() const;

    // Get the number of relevant recipes
    int getRelevantCount() const;
};

#endif // FILTER_HPP
