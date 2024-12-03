#pragma once

#include "Recipe.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Parser
{
public:
    int *recipeAmt;
    vector<Recipe *> CSVparser(vector<Recipe *> currBook);
    // void addRecipe()
};