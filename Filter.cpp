#include "Filter.h"
#include <iostream>

// Constructor
Filter::Filter() : relevant(0) {}

// Apply filters based on a specific constraint type and value
void Filter::applyFilters(const std::vector<Recipe>& allRecipes, 
                          const std::string& constraintType, 
                          const std::string& constraintValue) {
    result.clear();
    relevant = 0;

    for (const auto& recipe : allRecipes) {
        if (constraintType == "tag" && 
            std::find(recipe.metadata.tags.begin(), recipe.metadata.tags.end(), constraintValue) != recipe.metadata.tags.end()) {
            result.push_back(recipe);
            relevant++;
        } else if (constraintType == "cuisine" && recipe.metadata.cuisineType == constraintValue) {
            result.push_back(recipe);
            relevant++;
        } else if (constraintType == "mealType" && recipe.metadata.mealType == constraintValue) {
            result.push_back(recipe);
            relevant++;
        } else if (constraintType == "rating" && std::stod(constraintValue) <= recipe.metadata.rating) {
            result.push_back(recipe);
            relevant++;
        }
    }
}

// Add a single recipe to the filtered results
void Filter::addRecipe(const Recipe& recipe) {
    result.push_back(recipe);
    relevant++;
}

// Display the filtered results
void Filter::displayResult() const {
    if (result.empty()) {
        std::cout << "No recipes match the filtering criteria." << std::endl;
        return;
    }

    std::cout << "Filtered Recipes (" << relevant << " relevant):" << std::endl;
    for (const auto& recipe : result) {
        std::cout << " - " << recipe.metadata.title << " (Rating: " << recipe.metadata.rating << ")" << std::endl;
    }
}

// Get the filtered results
std::vector<Recipe> Filter::getResult() const {
    return result;
}

// Get the number of relevant recipes
int Filter::getRelevantCount() const {
    return relevant;
}
