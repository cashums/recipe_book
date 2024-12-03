#pragma once

#include "Recipe.h"

#include <vector>

class Book{
    vector<Recipe*> currBook;
public:
    vector<Recipe*> getBook();
    void addRecipe();
};