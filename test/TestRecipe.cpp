#include "Recipe.h"
#include "gtest/gtest.h"

// Test default constructor
TEST(RecipeTest, DefaultConstructor) {
    Recipe recipe;

    EXPECT_EQ(recipe.getName(), "");
    EXPECT_TRUE(recipe.getIngredientNames().empty());
    EXPECT_TRUE(recipe.getIngredientQuantities().empty());
    EXPECT_TRUE(recipe.getInstructions().empty());
    EXPECT_EQ(recipe.getCalories(), 0);
    EXPECT_TRUE(recipe.getTags().empty());
    EXPECT_EQ(recipe.getCuisine(), "");
    EXPECT_EQ(recipe.getFoodType(), "");
    EXPECT_EQ(recipe.getprepTime(), 0);
    EXPECT_EQ(recipe.getCookTime(), 0);
    EXPECT_EQ(recipe.getTotalTime(), 0);
}

// Test parameterized constructor
TEST(RecipeTest, ParameterizedConstructor) {
    std::vector<std::string> ingredientNames = {"Flour", "Eggs", "Milk"};
    std::vector<std::string> ingredientQuantities = {"2 cups", "3", "1 cup"};
    std::vector<std::string> instructions = {"Mix ingredients", "Bake for 30 minutes"};
    std::vector<std::string> tags = {"Dessert", "Easy"};

    Recipe recipe("Cake", ingredientNames, ingredientQuantities, instructions, 300, tags, "French", "Dessert", 10, 30);

    EXPECT_EQ(recipe.getName(), "Cake");
    EXPECT_EQ(recipe.getIngredientNames(), ingredientNames);
    EXPECT_EQ(recipe.getIngredientQuantities(), ingredientQuantities);
    EXPECT_EQ(recipe.getInstructions(), instructions);
    EXPECT_EQ(recipe.getCalories(), 300);
    EXPECT_EQ(recipe.getTags(), tags);
    EXPECT_EQ(recipe.getCuisine(), "French");
    EXPECT_EQ(recipe.getFoodType(), "Dessert");
    EXPECT_EQ(recipe.getprepTime(), 10);
    EXPECT_EQ(recipe.getCookTime(), 30);
    EXPECT_EQ(recipe.getTotalTime(), 40);
}

// Test setRecipeID and getrecipeID
TEST(RecipeTest, RecipeIDSetterGetter) {
    Recipe recipe;
    recipe.setRecipeID(123);

    EXPECT_EQ(recipe.getrecipeID(), 123);
}

// Test total time calculation
TEST(RecipeTest, TotalTimeCalculation) {
    Recipe recipe("Pizza", {"Dough", "Cheese"}, {"500g", "200g"}, {"Prepare dough", "Bake"}, 400, {"Comfort Food"}, "Italian", "Main Course", 15, 20);

    EXPECT_EQ(recipe.getTotalTime(), 35);
}

// Test viewRecipe output (mock-based or simulation)
TEST(RecipeTest, ViewRecipe) {
    Recipe recipe("Pasta", {"Pasta", "Tomato Sauce"}, {"200g", "1 cup"}, {"Boil pasta", "Mix with sauce"}, 350, {"Italian", "Quick"}, "Italian", "Main Course", 10, 20);

    // This is just a sanity test for execution; in real tests, capture and validate output
    EXPECT_NO_THROW(recipe.viewRecipe());
}

// Test empty ingredients
TEST(RecipeTest, EmptyIngredients) {
    Recipe recipe;
    EXPECT_TRUE(recipe.getIngredientNames().empty());
    EXPECT_TRUE(recipe.getIngredientQuantities().empty());
}

// Test empty instructions
TEST(RecipeTest, EmptyInstructions) {
    Recipe recipe;
    EXPECT_TRUE(recipe.getInstructions().empty());
}

// Test empty tags
TEST(RecipeTest, EmptyTags) {
    Recipe recipe;
    EXPECT_TRUE(recipe.getTags().empty());
}

// Test recipe with multiple tags
TEST(RecipeTest, MultipleTags) {
    Recipe recipe("Smoothie", {"Banana", "Milk"}, {"1", "1 cup"}, {"Blend together"}, 150, {"Healthy", "Breakfast"}, "American", "Beverage", 5, 0);

    EXPECT_EQ(recipe.getTags().size(), 2);
    EXPECT_EQ(recipe.getTags()[0], "Healthy");
    EXPECT_EQ(recipe.getTags()[1], "Breakfast");
}

// Test recipe with no cooking time
TEST(RecipeTest, NoCookingTime) {
    Recipe recipe("Salad", {"Lettuce", "Tomato"}, {"1 bunch", "2"}, {"Mix all ingredients"}, 100, {"Healthy", "Quick"}, "American", "Side Dish", 5, 0);

    EXPECT_EQ(recipe.getCookTime(), 0);
    EXPECT_EQ(recipe.getTotalTime(), 5);
}
