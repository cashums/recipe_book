#include "mainMenu.h"

using namespace std;

MainMenu::MainMenu() {
    isRunning = true; // Menu starts in a running state
}

void MainMenu::start() {
    handleAuthentication();

    cout << "\n------------Welcome to Recipe Book------------" << endl;

    Output::waitingScreen();
    Output::clearScreen();

    while (isRunning) {
        displayMenu();

        cout << endl;
        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        handleChoice(choice);
    }
}

void MainMenu::displayMenu() {
    Output::clearScreen();
    cout << "\nChoose what action you would like to take: "
         << "\n\t1: View All Current Recipes. "
         << "\n\t2: Add A New Recipe. "
         << "\n\t3. Filter By Ingredient Name."
         << "\n\t4. Favorite A Recipe."
         << "\n\t5. View All Favorited Recipes"
         << "\n\t6. Exit Program.\n";
}

void MainMenu::handleChoice(int choice) {
    switch (choice) {
    case 1:
        Output::clearScreen();
        book.viewAllRecipes();
        break;
    case 2:
        Output::clearScreen();
        book.addRecipe();
        break;
    case 3:
        Output::clearScreen();
        r.filteringPage();
        break;
    case 4:
        Output::clearScreen();
        // Display all recipes
        cout << "\nHere are the available recipes: " << endl;
        book.viewAllRecipes(); // Assuming this displays recipes with indices

        // Ask the user which recipe to favorite
        cout << "\nEnter the recipe number you'd like to favorite: ";
        int recipeIndex;
        cin >> recipeIndex;

        if (cin.fail() || recipeIndex < 0 || recipeIndex >= book.getBook().size()) {
            cin.clear();                                         // Clear the error flag on `cin`
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a valid recipe number.\n";
        } else {
            // Add the selected recipe to the favorite vector
            currentUser.addFavorRecipe(recipeIndex);
            cout << "Recipe added to favorites!" << endl;
        }
        break;
    case 5:
        Output::clearScreen();
        // Fetch favorite recipes vector from the user
        fav_recipe_vec = currentUser.getFavRecVec();

        // Check if the favorite recipe list is empty
        if (fav_recipe_vec.empty()) {
            cout << "You don't have any favorite recipes yet. Add some to your favorites!" << endl;
        } else {
            // Display the favorite recipes using the user's printRecipe method
            cout << "\nHere are your favorite recipes: " << endl;
            currentUser.printRecipe(fav_recipe_vec, book.getBook());
        }
        break;
    case 6:
        Output::clearScreen();
        cout << "\nExiting Program" << endl;
        isRunning = false;
        break;
    default:
        cout << "invalid choice (switch case branch)";
        break;
    }
}

void MainMenu::handleAuthentication() {
    User user;
    int userInput_int = 0;

    cout << "\n\t\t\t\tWelcome to the Recipe Book!" << endl
         << "Would you like to sign up for a new account or log in?" << endl
         << "(enter 1 for sign up, 2 for log in):\n";

    while (true) {
        cin >> userInput_int;

        // Check for invalid input or out-of-range values
        if (cin.fail() || (userInput_int != 1 && userInput_int != 2)) {
            cout << "Invalid input. Please enter 1 for sign up or 2 for log in: ";
            cin.clear();                                         // Clear the error flag on `cin`
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        } else {
            break; // Valid input, exit the loop
        }
    }

    if (userInput_int == 1) {
        currentUser.signUp();
    } else if (userInput_int == 2) {
        currentUser.logIn();
    }
}
