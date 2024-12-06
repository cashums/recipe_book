#include "DailyMenu.h"

#include <vector>
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <algorithm>


// No Destructor is needed Checked

void DailyMenu::generateMenu(vector<Recipe*>& book, vector<int>& fav_vec, vector<int>& hist_vec){
    vector<int> combined;
    // Insert elements of vec1 into combined
    combined.insert(combined.end(), fav_vec.begin(), fav_vec.end());
    // Insert elements of vec2 into combined
    combined.insert(combined.end(), hist_vec.begin(), hist_vec.end());

    //remove duplication
    sort(combined.begin(), combined.end());
    auto last = unique(combined.begin(), combined.end());
    combined.erase(last, combined.end());

    srand(time(0));
    int randomNum = 0;

    if (combined.empty()){
        cout << "Start your first new search to get a personalized daily menu recommendation!";
        return;
    }else if(combined.size() < 3){
        // find random new recipes from the book till total have three recipes in the combined vec
        while (combined.size() < 3){
            randomNum = rand() % book.size();
            if (find(combined.begin(), combined.end(), randomNum) != combined.end()){
                combined.push_back(randomNum);
            }else{
                randomNum = rand() % book.size();
            }
        }
    }else {
        // ramdomly pick three recipes from the vector
        for (int i = combined.size(); i > 3; i--){
            randomNum = rand() % combined.size();
            combined.erase(combined.begin() + randomNum);
        }
    }
}

void DailyMenu::printRecipe(const vector<int>& vec, const vector<Recipe*>& book) {
    if (vec.empty()){
        cout << "\nStart searching your favorite recipes!" << endl;
        return;
    }
    int totalCalories = 0;
    cout << "\n------------Here is your daily menu recommendation------------" << endl;
    for (size_t i = 0; i < vec.size(); ++i) {
        Recipe* recipe_ptr = book[vec[i]];
        recipe_ptr->viewRecipe(); // Call the base functionality
        totalCalories += recipe_ptr->getCalories();
    }

    cout << "\nTotal Calories of Recommended Recipes: " << totalCalories << endl;
}