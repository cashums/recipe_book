#include "User.h"
#include "DailyMenu.h"

#include <vector>
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()


void displayMenu(Recipe& recipe) {
    // Dummy function to simulate displaying a Recipe
    recipe.viewRecipe(); // Assuming Recipe has a getTitle() method
}

void DailyMenu::generateMenu(Book& book, vector<Recipe>& fav_vec, vector<Recipe>& hist_vec){
    vector<Recipe> combined;
    // Insert elements of vec1 into combined
    combined.insert(combined.end(), fav_vec.begin(), fav_vec.end());
    // Insert elements of vec2 into combined
    combined.insert(combined.end(), hist_vec.begin(), hist_vec.end());

    srand(time(0));
    int randomNum = 0;

    if (combined.empty()){
        cout << "Start your first new search to get a personalized daily menu recommendation!";
    }else if(combined.size() < 3){
        // not enough data...
        // since daily menu is under User, and User is a friend of Book
        // so randomly choose more options from the recipe book
        for (size_t i = combined.size(); i < (3 - combined.size()); ++i) {
            // Randomly choose a recipe from the Book's recipe list
            vector<Recipe*> allRecipes = book.getRecipe();
            //error
            randomNum = rand() % allRecipes.size(); // Assuming Book has allRecipes as a vector<Recipe*>
            Recipe randomRecipe = *allRecipes[randomNum];
            displayMenu(randomRecipe);
        }
    }else {
        // ramdomly pick three recipes from the vector
        for (Recipe recipe : combined){
            randomNum = rand() % combined.size();
            displayMenu(combined[randomNum]);
            combined.erase(combined.begin() + randomNum);
        }
    }

}