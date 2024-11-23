#include "User.h"
#include "DailyMenu.h"

#include <vector>

vector<Recipe> DailyMenu::generateMenu(vector<Recipe>& fav_vec, vector<Recipe>& hist_vec){
    vector<Recipe> combined;
    // Insert elements of vec1 into combined
    combined.insert(combined.end(), fav_vec.begin(), fav_vec.end());
    // Insert elements of vec2 into combined
    combined.insert(combined.end(), hist_vec.begin(), hist_vec.end());

    if (combined.empty()){
        cout << "Start your first new search to get a personalized daily menu recommendation!"
    }else if(combined.size() < 3){
        // not enough data...
        // since daily menu is under User, and User is a friend of Book
        // so randomly choose more options from the recipe book
    }else {
        // ramdomly pick three recipes from the vector
    }

}