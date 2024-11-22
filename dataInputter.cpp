//#include "Recipe.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    // take in all data from recipe file first
    
    ifstream CSVreader("recipes.csv");
    string currRecipe;

    if (!CSVreader.is_open()) {
        cerr << "Error opening recipe file" << endl;
        return 1;
    }

    getline(CSVreader, currRecipe);

    while(getline(CSVreader, currRecipe)) {
        istringstream rp(currRecipe);

        string name;
        vector<string> ingredientNames, ingredientQuantities, directions;
        int calories;
        vector<string> tags;
        string cuisine, foodType;
        int prepTime, cookTime;

        // store recipeName
        getline(rp, name, ',');

        //store ingredient names and quantities separately
        rp.ignore();

        string temp;
        getline(rp, temp, ':');
        ingredientNames.push_back(temp);
        rp.ignore(); // ignore the space after the colon
        getline(rp, temp, ';');
        ingredientQuantities.push_back(temp);

        cout << name; //<< ' ' << ingredientNames.at(0) << ' ' << ingredientQuantities.at(0);
        /*while(rp.peek() != '"') {
            // create a temporary string to store the curr ingredient until it is pushed back onto the vector of ingredient names
            string temp;                          
            getline(rp, temp, ':');
            ingredientNames.push_back(temp);
            rp.ignore();    //ignore the space after the colon
            getline(rp, temp, ';');
            ingredientQuantities.push_back(temp);
        }*/
    }

    /*string currentRecipe;
    vector<string> recipeData;

    while (getline(CSVreader, currentRecipe)) {
        cout << currentRecipe << endl;
    }*/

    CSVreader.close();
    
/*
    // parse the data to classify by type, and make Recipe objects out of this parsed data
    
    for (const auto& line : recipeData) {
        istringstream lineParser(line);
        string name;
        vector<string> ingredients, directions;
        int calories;
        vector<string> tags;
        string cuisine, foodType;
        int prepTime, cookTime;

        while(lineParser) {

        }
    }
    */

    return 0;
}