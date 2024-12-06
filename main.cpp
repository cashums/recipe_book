#include "User.h"
#include "Book.h"
#include "Recipe.h"
#include "RecipeFilter.h"
#include "mainMenu.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// void filteringPage() {
//     Book myBook; // Initialize and populate the book

//     // Get the recipes from the book
//     vector<Recipe*> recipes = myBook.getBook();

//     // Prompt the user for the ingredient
//     cout << "Enter the ingredient to filter recipes by: ";
//     string ingredient;
//     cin.ignore();
//     getline(cin, ingredient);

//     // Use the RecipeFilter class to filter recipes
//     vector<Recipe*> filteredRecipes = RecipeFilter::filterByIngredient(recipes, ingredient);

//     // Display the results
//     if (filteredRecipes.empty()) {
//         cout << "No recipes found containing the ingredient \"" << ingredient << "\"." << endl;
//     } else {
//         cout << "Recipes containing \"" << ingredient << "\":" << endl;
//         for (Recipe* recipe : filteredRecipes) {
//             cout << "- " << recipe->getName() << endl;
//         }
//     }
// }

int main() {
    MainMenu menu;
    menu.start();

    // Call filteringPage function to perform the filtering
    //filteringPage();

    cout << "\nThank You For Visiting The CookBook :)\n";

    return 0;
}
