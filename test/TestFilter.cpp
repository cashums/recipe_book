#include "../RecipeFilter.cpp"
#include "gtest/gtest.h"
#include <sstream>
#include <string>

// Redirect input and output for testing
class IOStreamRedirect {
public:
    IOStreamRedirect(std::istream &newInput, std::ostream &newOutput)
        : cinBuf(std::cin.rdbuf(newInput.rdbuf())),
          coutBuf(std::cout.rdbuf(newOutput.rdbuf())) {}
    ~IOStreamRedirect() {
        std::cin.rdbuf(cinBuf);
        std::cout.rdbuf(coutBuf);
    }

private:
    std::streambuf *cinBuf;
    std::streambuf *coutBuf;
};

// Unit tests
TEST(RecipeFilterTest, FilterByName) {
    std::istringstream fakeInput("Pasta Primavera\n\n\n\n-1\n-1\n-1\n0\n");
    std::ostringstream fakeOutput;
    IOStreamRedirect ioRedirect(fakeInput, fakeOutput);

    RecipeFilter recipeFilter;
    Book mockBook;

    // Add mock data
    Recipe *recipe1 = new Recipe("Stuffed Bell Peppers", {"Bell peppers"}, {}, {}, 500, {}, "American", "Main Course", 15, 35);
    Recipe *recipe2 = new Recipe("Pasta Primavera", {"Pasta"}, {}, {}, 450, {}, "Italian", "Main Course", 10, 10);
    mockBook.addRecipe(recipe1);
    mockBook.addRecipe(recipe2);

    recipeFilter.setBook(mockBook); // Assumes a setter method exists
    recipeFilter.filteringPage();

    // Validate output
    std::string output = fakeOutput.str();
    EXPECT_TRUE(output.find("Pasta Primavera") != std::string::npos);
    EXPECT_TRUE(output.find("No recipes found") == std::string::npos);

    // Cleanup
    delete recipe1;
    delete recipe2;
}

TEST(RecipeFilterTest, FilterByCuisine) {
    std::istringstream fakeInput("\nItalian\n\n\n-1\n-1\n-1\n0\n");
    std::ostringstream fakeOutput;
    IOStreamRedirect ioRedirect(fakeInput, fakeOutput);

    RecipeFilter recipeFilter;
    Book mockBook;

    // Add mock data
    Recipe *recipe1 = new Recipe("Stuffed Bell Peppers", {"Bell peppers"}, {}, {}, 500, {}, "American", "Main Course", 15, 35);
    Recipe *recipe2 = new Recipe("Pasta Primavera", {"Pasta"}, {}, {}, 450, {}, "Italian", "Main Course", 10, 10);
    mockBook.addRecipe(recipe1);
    mockBook.addRecipe(recipe2);

    recipeFilter.setBook(mockBook); // Assumes a setter method exists
    recipeFilter.filteringPage();

    // Validate output
    std::string output = fakeOutput.str();
    EXPECT_TRUE(output.find("Pasta Primavera") != std::string::npos);
    EXPECT_TRUE(output.find("Stuffed Bell Peppers") == std::string::npos);

    // Cleanup
    delete recipe1;
    delete recipe2;
}

TEST(RecipeFilterTest, FilterByCalories) {
    std::istringstream fakeInput("\n\n\n\n400\n500\n-1\n0\n");
    std::ostringstream fakeOutput;
    IOStreamRedirect ioRedirect(fakeInput, fakeOutput);

    RecipeFilter recipeFilter;
    Book mockBook;

    // Add mock data
    Recipe *recipe1 = new Recipe("Stuffed Bell Peppers", {"Bell peppers"}, {}, {}, 500, {}, "American", "Main Course", 15, 35);
    Recipe *recipe2 = new Recipe("Pasta Primavera", {"Pasta"}, {}, {}, 450, {}, "Italian", "Main Course", 10, 10);
    mockBook.addRecipe(recipe1);
    mockBook.addRecipe(recipe2);

    recipeFilter.setBook(mockBook); // Assumes a setter method exists
    recipeFilter.filteringPage();

    // Validate output
    std::string output = fakeOutput.str();
    EXPECT_TRUE(output.find("Stuffed Bell Peppers") != std::string::npos);
    EXPECT_TRUE(output.find("Pasta Primavera") != std::string::npos);

    // Cleanup
    delete recipe1;
    delete recipe2;
}

TEST(RecipeFilterTest, NoResultsFound) {
    std::istringstream fakeInput("\n\nVegan\n\n-1\n-1\n-1\n0\n");
    std::ostringstream fakeOutput;
    IOStreamRedirect ioRedirect(fakeInput, fakeOutput);

    RecipeFilter recipeFilter;
    Book mockBook;

    // Add mock data
    Recipe *recipe1 = new Recipe("Stuffed Bell Peppers", {"Bell peppers"}, {}, {}, 500, {}, "American", "Main Course", 15, 35);
    Recipe *recipe2 = new Recipe("Pasta Primavera", {"Pasta"}, {}, {}, 450, {}, "Italian", "Main Course", 10, 10);
    vector<Recipe*> cookbook = {recipe1, re}

    recipeFilter.setBook(mockBook); // Assumes a setter method exists
    recipeFilter.filteringPage();

    // Validate output
    std::string output = fakeOutput.str();
    EXPECT_TRUE(output.find("No recipes found") != std::string::npos);

    // Cleanup
    delete recipe1;
    delete recipe2;
}
