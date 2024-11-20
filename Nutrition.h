#include "Recipe.h"

using namespace std;

// Derived class: Nutrition
class Nutrition : public Recipe {
private:
    map<string, double> nutritionMap;
    double totalCalories = 0.0;
    // Helper function to parse the nutrition data
    void parseNutritionData();
    Nutrition();

public:
    
    // Method to calculate calories
    double calculateCalories();

    // Getter for the parsed nutrition map
    map<string, double> getNutritionMap() const;
};
