#include "../RecipeFilter.cpp"
#include "gtest/gtest.h"

#include <vector>

using namespace std;

// Mock data setup and unit test
TEST(SearchRecipesTest, SearchByName) {
    Recipe* recipe1 = new Recipe("Stuffed Bell Peppers", {"Bell peppers", "Ground turkey", "Rice", "Tomato sauce", "Onion"}, {"4", "300 grams", "1/2 cup", "1/2 cup", "1 diced"}, {"Stuff bell peppers with a mixture of cooked ground turkey, rice, tomato sauce, and onion. Bake for 25 minutes."}, 500, {"Hearty", "Family favorite", "Savory", "Comfort food", "Low-carb", "High-protein", "Kid-friendly", "Easy", "Make-ahead", "Filling"}, "American", "Main Course", 15, 35);
    Recipe* recipe2 = new Recipe("Pasta Primavera", {"Pasta", "Mixed vegetables", "Garlic", "Parmesan cheese", "Olive oil"}, {"200 grams", "2 cups", "2 cloves", "50 grams", "2 tbsp"}, {"Cook pasta. Sauté vegetables and garlic in olive oil. Combine pasta and vegetables, then top with parmesan cheese."}, 450, {"Vegetarian", "Fresh", "Italian", "Kid-friendly", "Quick", "Comfort food", "Healthy", "Low-calorie", "Summer", "Easy"}, "Italian", "Main Course", 10, 10);

    vector<Recipe*> cookbook = {recipe1, recipe2};

    vector<Recipe*> filteredRecipes = searchRecipes(cookbook, "Pasta Primavera");

    ASSERT_EQ(filteredRecipes.size(), 1); // only one recipe matches "Pasta Primavera"
    EXPECT_EQ(filteredRecipes[0]->getName(), "Pasta Primavera");

    for (Recipe* recipe : cookbook) {
        delete recipe;
    }
}

TEST(SearchRecipesTest, SearchByCuisine) {
    Recipe* recipe1 = new Recipe("Stuffed Bell Peppers", {"Bell peppers", "Ground turkey", "Rice", "Tomato sauce", "Onion"}, {"4", "300 grams", "1/2 cup", "1/2 cup", "1 diced"}, {"Stuff bell peppers with a mixture of cooked ground turkey, rice, tomato sauce, and onion. Bake for 25 minutes."}, 500, {"Hearty", "Family favorite", "Savory", "Comfort food", "Low-carb", "High-protein", "Kid-friendly", "Easy", "Make-ahead", "Filling"}, "American", "Main Course", 15, 35);
    Recipe* recipe2 = new Recipe("Pasta Primavera", {"Pasta", "Mixed vegetables", "Garlic", "Parmesan cheese", "Olive oil"}, {"200 grams", "2 cups", "2 cloves", "50 grams", "2 tbsp"}, {"Cook pasta. Sauté vegetables and garlic in olive oil. Combine pasta and vegetables, then top with parmesan cheese."}, 450, {"Vegetarian", "Fresh", "Italian", "Kid-friendly", "Quick", "Comfort food", "Healthy", "Low-calorie", "Summer", "Easy"}, "Italian", "Main Course", 10, 10);

    vector<Recipe*> cookbook = {recipe1, recipe2};

    vector<Recipe*> filteredRecipes = searchRecipes(cookbook, "", "Italian");

    ASSERT_EQ(filteredRecipes.size(), 1); // only "Pasta Primavera" matches the Italian cuisine
    EXPECT_EQ(filteredRecipes[0]->getCuisine(), "Italian");

    for (Recipe* recipe : cookbook) {
        delete recipe;
    }
}

TEST(SearchRecipesTest, SearchByTags) {
    Recipe* recipe1 = new Recipe("Stuffed Bell Peppers", {"Bell peppers", "Ground turkey", "Rice", "Tomato sauce", "Onion"}, {"4", "300 grams", "1/2 cup", "1/2 cup", "1 diced"}, {"Stuff bell peppers with a mixture of cooked ground turkey, rice, tomato sauce, and onion. Bake for 25 minutes."}, 500, {"Hearty", "Family favorite", "Savory", "Comfort food", "Low-carb", "High-protein", "Kid-friendly", "Easy", "Make-ahead", "Filling"}, "American", "Main Course", 15, 35);
    Recipe* recipe2 = new Recipe("Pasta Primavera", {"Pasta", "Mixed vegetables", "Garlic", "Parmesan cheese", "Olive oil"}, {"200 grams", "2 cups", "2 cloves", "50 grams", "2 tbsp"}, {"Cook pasta. Sauté vegetables and garlic in olive oil. Combine pasta and vegetables, then top with parmesan cheese."}, 450, {"Vegetarian", "Fresh", "Italian", "Kid-friendly", "Quick", "Comfort food", "Healthy", "Low-calorie", "Summer", "Easy"}, "Italian", "Main Course", 10, 10);

    vector<Recipe*> cookbook = {recipe1, recipe2};

    vector<Recipe*> filteredRecipes = searchRecipes(cookbook, "", "", {"Vegetarian", "Healthy"});

    ASSERT_EQ(filteredRecipes.size(), 1); // only "Pasta Primavera" matches both "Vegetarian" and "Healthy" tags
    EXPECT_EQ(filteredRecipes[0]->getTags(), vector<string>({"Vegetarian", "Fresh", "Italian", "Kid-friendly", "Quick", "Comfort food", "Healthy", "Low-calorie", "Summer", "Easy"}));

    for (Recipe* recipe : cookbook) {
        delete recipe;
    }
}

TEST(SearchRecipesTest, SearchByCalories) {
    Recipe* recipe1 = new Recipe("Stuffed Bell Peppers", {"Bell peppers", "Ground turkey", "Rice", "Tomato sauce", "Onion"}, {"4", "300 grams", "1/2 cup", "1/2 cup", "1 diced"}, {"Stuff bell peppers with a mixture of cooked ground turkey, rice, tomato sauce, and onion. Bake for 25 minutes."}, 500, {"Hearty", "Family favorite", "Savory", "Comfort food", "Low-carb", "High-protein", "Kid-friendly", "Easy", "Make-ahead", "Filling"}, "American", "Main Course", 15, 35);
    Recipe* recipe2 = new Recipe("Pasta Primavera", {"Pasta", "Mixed vegetables", "Garlic", "Parmesan cheese", "Olive oil"}, {"200 grams", "2 cups", "2 cloves", "50 grams", "2 tbsp"}, {"Cook pasta. Sauté vegetables and garlic in olive oil. Combine pasta and vegetables, then top with parmesan cheese."}, 450, {"Vegetarian", "Fresh", "Italian", "Kid-friendly", "Quick", "Comfort food", "Healthy", "Low-calorie", "Summer", "Easy"}, "Italian", "Main Course", 10, 10);

    vector<Recipe*> cookbook = {recipe1, recipe2};

    vector<Recipe *> filteredRecipes = searchRecipes(cookbook, "", "", {}, 400, 500);

    ASSERT_EQ(filteredRecipes.size(), 2); // both recipes match the calorie range of 400–500
    EXPECT_EQ(filteredRecipes[0]->getCalories(), 500);
    EXPECT_EQ(filteredRecipes[1]->getCalories(), 450);

    for (Recipe* recipe : cookbook) {
        delete recipe;
    }
}

TEST(SearchRecipesTest, SearchByTime) {
    Recipe* recipe1 = new Recipe("Stuffed Bell Peppers", {"Bell peppers", "Ground turkey", "Rice", "Tomato sauce", "Onion"}, {"4", "300 grams", "1/2 cup", "1/2 cup", "1 diced"}, {"Stuff bell peppers with a mixture of cooked ground turkey, rice, tomato sauce, and onion. Bake for 25 minutes."}, 500, {"Hearty", "Family favorite", "Savory", "Comfort food", "Low-carb", "High-protein", "Kid-friendly", "Easy", "Make-ahead", "Filling"}, "American", "Main Course", 15, 35);
    Recipe* recipe2 = new Recipe("Pasta Primavera", {"Pasta", "Mixed vegetables", "Garlic", "Parmesan cheese", "Olive oil"}, {"200 grams", "2 cups", "2 cloves", "50 grams", "2 tbsp"}, {"Cook pasta. Sauté vegetables and garlic in olive oil. Combine pasta and vegetables, then top with parmesan cheese."}, 450, {"Vegetarian", "Fresh", "Italian", "Kid-friendly", "Quick", "Comfort food", "Healthy", "Low-calorie", "Summer", "Easy"}, "Italian", "Main Course", 10, 10);

    vector<Recipe*> cookbook = {recipe1, recipe2};

    vector<Recipe*> filteredRecipes = searchRecipes(cookbook, "", "", {}, -1, -1, 20);

    ASSERT_EQ(filteredRecipes.size(), 1); // only "Pasta Primavera" matches total time <= 20 minutes
    EXPECT_EQ(filteredRecipes[0]->getTotalTime(), 20);

    for (Recipe* recipe : cookbook) {
        delete recipe;
    }
}