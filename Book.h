#pragma once

#include "Recipe.h"

#include <vector>
#include <string>

using namespace std;

class Book {
    vector<Recipe*> currBook;
public:
    vector<Recipe*> getBook();
    void addRecipe();
    vector<string> splitHelper(const string& msg, char delimiter);
};