#include "Recipe.h"
#include "dataParser.h"

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    // Load recipes from dataInputter
    Parser parser;
    vector<Recipe*> recipeBook = parser.CSVparser();

    // Display all recipes
    cout << "Available Recipes:\n";
    for (size_t i = 0; i < recipeBook.size(); i++)
    {
        cout << i + 1 << ": " << recipeBook.at(i)->getName() << endl;
    }

    // Allow user to view a specific recipe
    cout << "Enter the number of the recipe to view: ";
    int choice;
    cin >> choice;

    if (choice > 0 && choice <= recipeBook.size())
    {
        recipeBook.at(choice - 1)->viewRecipe();
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}