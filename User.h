#include "Recipe.h"

#include <string>
#include <vector>

class User{
    string userName;
    int userID;
    bool logIn();
    void logOut();
    void displayHist();
    void displayFav();

    User();
    ~User();

private:
    vector<&Recipe> searchingHistory;
    vector<&Recipe> favoriteRecipe;
    string password;
};