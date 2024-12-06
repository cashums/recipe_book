#pragma once

#include "Recipe.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// No destructor Needed

class Parser
{
public:
    static vector<Recipe *> CSVparser();
    void writeToCSV(Recipe *recipe);
};