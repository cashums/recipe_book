#include "RecipeFilter.h"
#include <algorithm>
#include <iostream>
#include "Book.h"  // Include the Book class to get the recipes
#include <cctype>  // For tolower function

using namespace std;

// Helper function to normalize the ingredient name by removing extra spaces and making it lowercase
string normalizeIngredient(const string& ingredient) {
    string normalized = ingredient;
    
    // Remove leading and trailing spaces
    normalized.erase(0, normalized.find_first_not_of(" \t"));
    normalized.erase(normalized.find_last_not_of(" \t") + 1);
    
    // Convert to lowercase for case-insensitive comparison
    transform(normalized.begin(), normalized.end(), normalized.begin(), ::tolower);
    
    return normalized;
}

vector<Recipe*> RecipeFilter::filterByIngredient(const vector<Recipe*>& recipes, const string& ingredient) {
    vector<Recipe*> filteredRecipes;

    string normalizedIngredient = normalizeIngredient(ingredient); // Normalize the input ingredient
    
    for (Recipe* recipe : recipes) {
        vector<string> ingredients = recipe->getIngredientNames();
        
        // Loop through the ingredients of each recipe
        for (const string& recipeIngredient : ingredients) {
            string normalizedRecipeIngredient = normalizeIngredient(recipeIngredient); // Normalize the recipe ingredient
            
            // Compare the normalized ingredient names
            if (normalizedRecipeIngredient.find(normalizedIngredient) != string::npos) {
                filteredRecipes.push_back(recipe);
                break; // Exit loop once a match is found for this recipe
            }
        }
    }

    return filteredRecipes;
}

void RecipeFilter::filteringPage() {
    Book myBook; // Initialize and populate the book

    // Get the recipes from the book
    vector<Recipe*> recipes = myBook.getBook();

    // Prompt the user for the ingredient
    cout << "Enter the ingredient to filter recipes by: ";
    string ingredient;
    cin.ignore();
    getline(cin, ingredient);

    // Use the RecipeFilter class to filter recipes
    vector<Recipe*> filteredRecipes = RecipeFilter::filterByIngredient(recipes, ingredient);

    // Display the results
    if (filteredRecipes.empty()) {
        cout << "No recipes found containing the ingredient \"" << ingredient << "\"." << endl;
    } else {
        cout << "Recipes containing \"" << ingredient << "\":" << endl;
        for (Recipe* recipe : filteredRecipes) {
            cout << recipe->getrecipeID() << " " << recipe->getName() << endl;
        }
    }
    cout << "Enter the number of the recipe to view: ";
    int choice;
    cin >> choice;
    if (choice > 0 && choice <= filteredRecipes.size())
    {
        filteredRecipes[choice - 1]->viewRecipe(); // View the selected recipe
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }
}
