#include "Recipe.h"
#include "Nutrition.h"
#include <regex>
#include <iostream>

using namespace std;

Nutrition::Nutrition() { 
    parseNutritionData(); // Parse the nutrition data
}

void Nutrition::parseNutritionData() {
    regex pattern(R"(([^,]+?)\s(\d+\.?\d*)[a-zA-Z%]*)");
    smatch match;

    string::const_iterator searchStart(rawNutritionData.cbegin());

    while (regex_search(searchStart, rawNutritionData.cend(), match, pattern)) {
        string nutrientName = match[1];
        double nutrientValue = stod(match[2]);
        nutritionMap[nutrientName] = nutrientValue;
        searchStart = match.suffix().first;
    }
}

double Nutrition::calculateCalories() {
    totalCalories = 0.0;
    
    // Iterate over the nutritionMap
    for (const auto& entry : nutritionMap) {
        const string& nutrientName = entry.first; // Key: nutrient name
        double nutrientValue = entry.second;          // Value: grams/mg of nutrient

        // Check for specific nutrients and add their calorie contribution
        if (nutrientName == "Total Fat") {
            totalCalories += 9.0 * nutrientValue; // Fat: 9 calories per gram
        } else if (nutrientName == "Total Carbohydrate") {
            totalCalories += 4.0 * nutrientValue; // Carbs: 4 calories per gram
        } else if (nutrientName == "Protein") {
            totalCalories += 4.0 * nutrientValue; // Protein: 4 calories per gram
        } else if (nutrientName == "Protein") {
            totalCalories += 4.0 * nutrientValue;
        } // Other nutrients like fiber, vitamins, etc., don't contribute to calories
    }
    return totalCalories;
}

map<string, double> Nutrition::getNutritionMap() const {
    return nutritionMap;
}