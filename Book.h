#pragma once

#include "Recipe.h"

#include <vector>
#include <string>

using namespace std;

class Book
{
private:
    vector<Recipe*> currBook;
public:
    Book();
    ~Book(); // Destructor declaration
    vector<Recipe *> getBook();
    void addRecipe();
    Recipe* findRecipeByID(int id);
    void deleteRecipe();
    void viewAllRecipes();
};


