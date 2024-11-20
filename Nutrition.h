#include "Recipe.h"

using namespace std;

// Derived class: Nutrition
class Nutrition : public Recipe {
private:
    map<string, double> nutritionMap;

    // Helper function to parse the nutrition data
    void parseNutritionData();

public:
    // Nutrition(const int&, const string&);

    // Method to calculate calories
    double calculateCalories();

    // Getter for the parsed nutrition map
    map<string, double> getNutritionMap() const;
};
