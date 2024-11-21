#include "Recipe.h"

/*#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    // take in all data from recipe file first
    
    ifstream CSVreader("test_recipes.csv");

    if (!CSVreader.is_open()) {
        cerr << "Error opening recipe file" << endl;
        return 1;
    }

    string currentRecipe;
    vector<string> recipeData;

    while (getline(CSVreader, currentRecipe)) {
        cout << currentRecipe << endl;
    }

    CSVreader.close();
    

    // parse the data to classify by type, and make Recipe objects out of this parsed data
    
    for (const auto& line : recipeData) {
        istringstream lineParser(line);
        int num;
        string name;
        int cookTime, totalTime, servings;
    }

    return 0;
}*/