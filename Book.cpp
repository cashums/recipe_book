#include "Book.h"
#include "Recipe.h"

#include <sstream>

#include <iostream>
using namespace std;

vector<string> split(const string &str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string item;
    while (getline(ss, item, delimiter)) {
        result.push_back(item);
    }
    return result;
}

vector<Recipe*> Book::getBook() {
    return currBook;
}

void Book::addRecipe() {
    cout << "Add a new recipe." << endl;
    // add code to create a new Recipe object from user input
    string name;
    vector<string> ingredientNames, ingredientQuantities, directions, tags;
    int calories, prepTime, cookTime;
    string cuisine, foodType;

    // Prompt user for inputs
    cout << "Enter recipe name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter ingredient names (comma-separated): ";
    string input;
    getline(cin, input);
    ingredientNames = split(input, ',');

    cout << "Enter ingredient quantities (comma-separated): ";
    getline(cin, input);
    ingredientQuantities = split(input, ',');

    cout << "Enter directions (each step comma-separated): ";
    getline(cin, input);
    directions = split(input, ',');

    cout << "Enter number of calories: ";
    cin >> calories;

    cout << "Enter tags (comma-separated): ";
    cin.ignore();
    getline(cin, input);
    tags = split(input, ',');

    cout << "Enter cuisine type: ";
    getline(cin, cuisine);

    cout << "Enter food type: ";
    getline(cin, foodType);

    cout << "Enter preparation time (minutes): ";
    cin >> prepTime;

    cout << "Enter cooking time (minutes): ";
    cin >> cookTime;

    // Directly create and add the Recipe object
    Recipe* newRecipe = new Recipe(name, ingredientNames, ingredientQuantities, directions, calories, tags, cuisine, foodType, prepTime, cookTime);

    // Assuming you have a member function or container to store the Recipe object
    currBook.push_back(newRecipe);

    cout << "Recipe added successfully!" << endl;
}