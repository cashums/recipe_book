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
    void deleteRecipe();
};