#include "dataParser.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<Recipe*> Parser::CSVparser()
{
    // take in all data from recipe file first
    ifstream CSVreader("recipes.csv");
    string currRecipe, temp;

    if (!CSVreader.is_open())
    {
        cerr << "Error opening recipe file" << endl;
    }

    vector<Recipe *> recipeBook;

    while (getline(CSVreader, currRecipe))
    {
        string name;
        vector<string> ingredientNames, ingredientQuantities, directions;
        int calories;
        vector<string> tags;
        string cuisine, foodType;
        int prepTime, cookTime;

        istringstream rp(currRecipe);

        // store recipeName
        getline(rp, name, ',');

        // store ingredient names and quantities separately
        rp.ignore();

        // get the full ingredients section, then break it down
        string ingredientsSection;
        getline(rp, ingredientsSection, '"');
        istringstream ingredientsStream(ingredientsSection);

        string currIngredient;
        while (getline(ingredientsStream, currIngredient, ';'))
        {
            size_t colonPosition = currIngredient.find(':');
            if (colonPosition != string::npos)
            {
                ingredientNames.push_back(currIngredient.substr(0, colonPosition));
                ingredientQuantities.push_back(currIngredient.substr(colonPosition + 1));
            }
        }

        // get the full directions section, then break it down
        rp.ignore();
        rp.ignore();
        string fullDirections;
        getline(rp, fullDirections, '"');
        istringstream directionsStream(fullDirections);

        // string currDirection;
        while (fullDirections.find('.') != string::npos)
        {
            size_t periodPosition = fullDirections.find('.');
            directions.push_back(fullDirections.substr(0, periodPosition + 1));
            if (periodPosition + 1 < fullDirections.size() && fullDirections[periodPosition + 1] == ' ')
            {
                fullDirections = fullDirections.substr(periodPosition + 2); // Skip past the period and space
            }
            else
            {
                fullDirections = fullDirections.substr(periodPosition + 1); // No space, just skip the period
            }
        }

        // get calories
        rp.ignore();
        string caloriesStr;
        getline(rp, caloriesStr, ',');
        try
        {
            calories = stoi(caloriesStr);
        }
        catch (const std::invalid_argument &e)
        {
            cerr << "Invalid input for calories: " << caloriesStr << endl;
        }
        catch (const std::out_of_range &e)
        {
            cerr << "Calories value out of range: " << caloriesStr << endl;
        }

        // get tags
        rp.ignore();
        string allTags;
        getline(rp, allTags, '"');

        while (allTags.find(';') != string::npos)
        {
            size_t semicolonPosition = allTags.find(';');
            tags.push_back(allTags.substr(0, semicolonPosition));
            allTags = allTags.substr(semicolonPosition + 2);
        }
        if (!allTags.empty())
        {
            tags.push_back(allTags);
        }

        // get cuisine
        rp.ignore();
        rp.ignore();
        getline(rp, cuisine, '"');

        // get dish type
        rp.ignore();
        rp.ignore();
        getline(rp, foodType, '"');

        // get prep time
        rp.ignore();
        rp >> prepTime;

        // get cook time
        rp.ignore();
        rp >> cookTime;

        // create a Recipe object from parsed information
        Recipe *newRecipe = new Recipe(name, ingredientNames, ingredientQuantities, directions, calories, tags, cuisine, foodType, prepTime, cookTime);
        recipeBook.push_back(newRecipe);
        newRecipe->setRecipeID(recipeBook.size());
    }

    CSVreader.close();

    return recipeBook;
}

void Parser::writeToCSV(Recipe *recipe)
{
    ifstream CSVreader("recipes.csv");
    string currentRecipe;

    if (!CSVreader.is_open())
    {
        cerr << "Error opening recipe file" << endl;
    }

    string line;
    bool exists = false;
    while (getline(CSVreader, line))
    {
        istringstream iss(line);
        string existingTitle;
        getline(iss, existingTitle, ',');

        if (existingTitle == recipe->getName())
        {
            exists = true;
            break;
        }
    }

    CSVreader.close();

    if (!exists)
    {
        ofstream CSVfile("recipes.csv", ios::app);
        if (!CSVfile.is_open())
        {
            cerr << "Error opening recipe file" << endl;
        }

        // Add a newline if the file doesn't already end with one
        std::ifstream checkFile("recipes.csv", std::ios::ate);
        if (checkFile.is_open() && checkFile.tellg() > 0)
        {                                       // Check if file is not empty
            checkFile.seekg(-1, std::ios::end); // Move to the last character
            char lastChar;
            checkFile.get(lastChar);
            if (lastChar != '\n')
            {
                CSVfile << "\n"; // Append a newline if the file does not end with one
            }
        }
        checkFile.close();

        CSVfile << recipe->getName() << ",\"";

        for (size_t i = 0; i < recipe->getIngredientNames().size(); ++i)
        {
            CSVfile << recipe->getIngredientNames()[i] << ": " << recipe->getIngredientQuantities()[i];
            if (i != recipe->getIngredientNames().size() - 1)
            {
                CSVfile << "; ";
            }
        }
        CSVfile << "\",\"";
        // Combine directions
        for (size_t i = 0; i < recipe->getInstructions().size(); ++i)
        {
            CSVfile << recipe->getInstructions()[i];
            if (i != recipe->getInstructions().size() - 1)
            {
                CSVfile << ". ";
            }
        }
        CSVfile << "\"," << recipe->getCalories() << ",\"";

        // Combine tags
        for (size_t i = 0; i < recipe->getTags().size(); ++i)
        {
            CSVfile << recipe->getTags()[i];
            if (i != recipe->getTags().size() - 1)
            {
                CSVfile << "; ";
            }
        }
        CSVfile << recipe->getCuisine() << ","
                << recipe->getFoodType() << ","
                << recipe->getprepTime() << ","
                << recipe->getCookTime() << "\n";

        CSVfile.close();
        std::cout << "Recipe successfully added!" << std::endl;
    }
    else
    {
        std::cout << "Recipe with the title \"" << recipe->getName() << "\" already exists in the file." << std::endl;
    }
}
