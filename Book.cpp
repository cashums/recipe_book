#include "Book.h"
#include "Recipe.h"
#include "dataParser.h"

#include <sstream>
#include <iostream>

using namespace std;

Book::Book()
{
    currBook = Parser::CSVparser();
}

vector<Recipe *> Book::getBook()
{
    return currBook;
}

void Book::viewAllRecipes()
{
    // Display all recipes
    cout << "Available Recipes:\n";
    for (size_t i = 0; i < currBook.size(); i++)
    {
        cout << i + 1 << ": " << currBook.at(i)->getName() << endl;
    }
    // Allow user to view a specific recipe
    cout << "Enter the number of the recipe to view: ";
    int choice;
    cin >> choice;
    if (choice > 0 && choice <= currBook.size())
    {
        currBook.at(choice - 1)->viewRecipe();
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }
}

void Book::addRecipe()
{
    cin.ignore();

    string name, cuisine, foodType;
    vector<string> ingredientNames, ingredientQuantities, instructions, tags;
    int calories, prepTime, cookTime;

    cout << "\nEnter recipe name: ";
    getline(cin, name);

    cout << "\nEnter ingredients (type 'done' when finished):\n";
    while (true)
    {
        string ingredient, quantity;
        cout << "\n\tIngredient name: ";
        getline(cin, ingredient);
        if (ingredient == "done")
            break;

        cout << "\n\tQuantity for " << ingredient << ": ";
        getline(cin, quantity);

        ingredientNames.push_back(ingredient);
        ingredientQuantities.push_back(quantity);
    }

    cout << "\nEnter Directions (type 'done' when finished):\n";
    while (true)
    {
        string direction;
        cout << "Step: ";
        getline(cin, direction);
        if (direction == "done")
            break;
        instructions.push_back(direction);
    }

    cout << "\nEnter number of calories: ";
    cin >> calories;
    cin.ignore(); // Clear input buffer

    cout << "\nEnter Tags (type 'done' when finished):\n";
    while (true)
    {
        string tag;
        cout << "Tag: ";
        getline(cin, tag);
        if (tag == "done")
            break;
        tags.push_back(tag);
    }

    cout << "\nEnter cuisine type: ";
    getline(cin, cuisine);

    cout << "\nEnter food type (e.g., Main Course, Side Dish): ";
    getline(cin, foodType);

    cout << "\nEnter prep time (in minutes): ";
    cin >> prepTime;

    cout << "\nEnter cook time (in minutes): ";
    cin >> cookTime;

    Recipe *newRecipe = new Recipe(name, ingredientNames, ingredientQuantities, instructions, calories, tags, cuisine, foodType, prepTime, cookTime);
    currBook.push_back(newRecipe);

    cout << "\nNew Recipe Added: " << name << endl;
}

void Book::deleteRecipe()
{
    // filler
}