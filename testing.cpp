#include "Recipe.h"
#include "dataParser.h"

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

Recipe *addRecipe(vector<Recipe *> &recipeBook);
void viewAllRecipes(vector<Recipe *> &recipeBook);

int main()
{
    Parser parser;
    vector<Recipe *> recipeBook = parser.CSVparser();

    viewAllRecipes(recipeBook);
    Recipe *newRecipe = addRecipe(recipeBook);
    parser.writeToCSV(newRecipe);
    viewAllRecipes(recipeBook);

    /*string fullString = "Quick; Healthy; Savory; Low-carb; Protein-rich; Mediterranean; Kid-friendly; Light; Comfort food; Salad";

    istringstream tagsStream(fullString);

    while (fullString.find(';') != string::npos)
    {
        size_t semicolonPosition = fullString.find(';');
        cout << fullString.substr(0, semicolonPosition) << endl;
        // Update fullString to exclude the processed tag and the semicolon
        fullString = fullString.substr(semicolonPosition + 2); // Skip "; "
    }

    if (!fullString.empty())
    {
        cout << fullString << endl;
    }

    while(fullString.find('.') != string::npos) {
        size_t periodPosition = fullString.find('.');
        cout << fullString.substr(0, periodPosition + 1) << ' ';
        if (periodPosition + 1 < fullString.size() && fullString[periodPosition + 1] == ' ')
        {
            fullString = fullString.substr(periodPosition + 2); // Skip past the period and space
        }
        else
        {
            fullString = fullString.substr(periodPosition + 1); // No space, just skip the period
        }
    }*/

    return 0;
}

void viewAllRecipes(vector<Recipe *> &recipeBook)
{
    // Load recipes from dataInputter
    // Parser parser;
    // vector<Recipe *> recipeBook = parser.CSVparser();

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
}

Recipe *addRecipe(vector<Recipe *> &recipeBook)
{
    cout << " ADD new Recipe:: \n";
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

    Recipe *newRecipe = new Recipe{name, ingredientNames, ingredientQuantities, instructions,
                                   calories, tags, cuisine, foodType, prepTime, cookTime};
    recipeBook.push_back(newRecipe);

    cout << "\nNew Recipe Added : " << name << endl;
    return newRecipe;
}