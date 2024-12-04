#pragma once

#include "Recipe.h"

#include <vector>
#include <string>

using namespace std;

class Book
{
    vector<Recipe *> currBook;

public:
    Book();
    vector<Recipe *> getBook();
    void addRecipe();
    void deleteRecipe();
    void viewAllRecipes();
};