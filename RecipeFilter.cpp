#include "RecipeFilter.h"
#include "Book.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

// Helper function to normalize strings (used for ingredient and tag comparison)
string normalizeString(const string &str) {
    string normalized = str;

    // Remove leading and trailing spaces
    normalized.erase(0, normalized.find_first_not_of(" \t"));
    normalized.erase(normalized.find_last_not_of(" \t") + 1);

    // Convert to lowercase for case-insensitive comparison
    transform(normalized.begin(), normalized.end(), normalized.begin(), ::tolower);

    return normalized;
}

vector<Recipe *> searchRecipes(const vector<Recipe *> &recipes,
                               const string &name = "",
                               const string &cuisine = "",
                               const vector<string> &tags = {},
                               const string &ingredient = "",
                               int minCalories = -1,
                               int maxCalories = -1,
                               int maxTotalTime = -1) {
    vector<Recipe *> filteredRecipes;

    string normalizedIngredient = normalizeString(ingredient); // Normalize input ingredient for comparison

    for (Recipe *recipe : recipes) {
        bool match = true;

        // Check for name match
        if (!name.empty() && normalizeString(recipe->getName()) != normalizeString(name)) {
            match = false;
        }

        // Check for cuisine match
        if (!cuisine.empty() && normalizeString(recipe->getCuisine()) != normalizeString(cuisine)) {
            match = false;
        }

        // Check for tag match
        if (!tags.empty()) {
            bool tagMatch = true;
            for (const string &tag : tags) {
                bool found = false;
                for (const string &recipeTag : recipe->getTags()) {
                    if (normalizeString(recipeTag) == normalizeString(tag)) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    tagMatch = false;
                    break;
                }
            }
            if (!tagMatch)
                match = false;
        }

        // Check for ingredient match
        if (!ingredient.empty()) {
            bool ingredientFound = false;
            for (const string &recipeIngredient : recipe->getIngredientNames()) {
                if (normalizeString(recipeIngredient).find(normalizedIngredient) != string::npos) {
                    ingredientFound = true;
                    break;
                }
            }
            if (!ingredientFound)
                match = false;
        }

        // Check for calorie range
        if (minCalories != -1 && recipe->getCalories() < minCalories) {
            match = false;
        }
        if (maxCalories != -1 && recipe->getCalories() > maxCalories) {
            match = false;
        }

        // Check for maximum total time
        if (maxTotalTime != -1 && recipe->getTotalTime() > maxTotalTime) {
            match = false;
        }

        // Add recipe to results if it matches all criteria
        if (match) {
            filteredRecipes.push_back(recipe);
        }
    }

    return filteredRecipes;
}

// Unified filtering page
void RecipeFilter::filteringPage() {
    Book myBook; // Initialize and populate the book

    // Get the recipes from the book
    vector<Recipe *> recipes = myBook.getBook();

    // Variables for user input
    string name, cuisine, tagInput, ingredient;
    int minCalories = -1, maxCalories = -1, maxTotalTime = -1;

    // Clear the input buffer before using getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Prompt the user for search criteria
    cout << "Enter the recipe name (leave empty for any): ";
    getline(cin, name);

    cout << "Enter the cuisine type (leave empty for any): ";
    getline(cin, cuisine);

    cout << "Enter tags separated by commas (leave empty for any): ";
    getline(cin, tagInput);

    // Parse tags
    vector<string> tags;
    if (!tagInput.empty()) {
        size_t pos = 0;
        while ((pos = tagInput.find(',')) != string::npos) {
            tags.push_back(normalizeString(tagInput.substr(0, pos)));
            tagInput.erase(0, pos + 1);
        }
        if (!tagInput.empty()) {
            tags.push_back(normalizeString(tagInput));
        }
    }

    cout << "Enter an ingredient (leave empty for any): ";
    getline(cin, ingredient);

    // Prompt for numerical inputs
    cout << "Enter minimum calories (enter -1 for no minimum): ";
    cin >> minCalories;

    cout << "Enter maximum calories (enter -1 for no maximum): ";
    cin >> maxCalories;

    cout << "Enter maximum total time in minutes (enter -1 for no limit): ";
    cin >> maxTotalTime;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the buffer after numeric input

    // Perform the search
    vector<Recipe *> filteredRecipes = searchRecipes(recipes, name, cuisine, tags, ingredient, minCalories, maxCalories, maxTotalTime);

    // Display the results
    if (filteredRecipes.empty()) {
        cout << "No recipes found matching the criteria." << endl;
    } 
    else {
        cout << endl
             << "Recipes found:" << endl;
        for (size_t i = 0; i < filteredRecipes.size(); ++i) {
            cout << i + 1 << ". " << filteredRecipes[i]->getName() << endl;
        }

        // Prompt user to view a recipe
        cout << endl
             << "Enter the number of the recipe to view (or 0 to exit): ";
        int choice;
        cin >> choice;

        if (choice > 0 && choice <= filteredRecipes.size()) {
            filteredRecipes[choice - 1]->viewRecipe();
        } 
        else if (choice != 0) {
            cout << "Invalid choice!" << endl; 
        }
        cout << endl;
        Output::returnToMenu();
    }
}