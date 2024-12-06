#include "Book.h"

#include <algorithm>

using namespace std;

vector<Recipe*> searchRecipes(const vector<Recipe*>& cookbook, const string& name = "", const string& cuisine = "", const vector<string>& tags = {}, int minCalories = -1, int maxCalories = -1, int maxTotalTime = -1)
{
    vector<Recipe*> results;

    for (Recipe* recipe : cookbook) {
        bool match = true;

        if (!name.empty() && recipe->getName() != name)  {
            match = false;
        }

        if (!cuisine.empty() && recipe->getCuisine() != cuisine) {
            match = false;
        }

        if (!tags.empty()) {
            for (const string& tag : tags) {
                if (find(recipe->getTags().begin(), recipe->getTags().end(), tag) == recipe->getTags().end()) {
                    match = false;
                    break;
                }
            }
        }

        if (minCalories != -1 && recipe->getCalories() < minCalories) {
            match = false;
        }

        if (maxCalories != -1 && recipe->getCalories() > maxCalories) {
            match = false;
        }

        if (maxTotalTime != -1 && recipe->getTotalTime() > maxTotalTime) {
            match = false;
        }

        if (match) {
            results.push_back(recipe);
        }
    }

    return results;
}