#pragma once

#include "Recipe.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Parser {
    public:
        vector<Recipe*> CSVparser();
};