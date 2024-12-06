#include "mainMenu.h"

using namespace std;

MainMenu::MainMenu()
{
    isRunning = true; // Menu starts in a running state
}

void MainMenu::start()
{
    handleAuthentication();

    while (isRunning)
    {
        displayMenu();

        cout << endl;
        int choice;
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        handleChoice(choice);
    }
}

void MainMenu::displayMenu()
{
    cout << "\n------------Welcome to Recipe Book------------" << endl
         << "\nChoose what action you would like to take: "
         << "\n\t1: View All Current Recipes. "
         << "\n\t2: Add A New Recipe. "
         << "\n\t3. Filter By Ingredient Name."
         << "\n\t4. Exit Program.\n"
         << "\n\t3. Check Out Favorite Recipe."
         << "\n\t4. Check Out Searching History."
         << "\n\t5. Exit Program.\n";
}

void MainMenu::handleChoice(int choice)
{
    switch (choice)
    {
    case 1:
        book.viewAllRecipes();
        break;
    case 2:
        book.addRecipe();
        break;
    case 3:
         r.filteringPage();
         break;
    case 4:
        cout << "\nExiting Program" << endl;
        isRunning = false;
        break;
    // case 4:
    //     fav_recipe_vec = currentUser.getFavRecVec();
    //     currentUser.printRecipe(fav_recipe_vec, book.getBook());
    //     break;
    // case 5:
    //     search_hist_vec = currentUser.getSearchHistVec();
    //     currentUser.printRecipe(search_hist_vec, book.getBook());
    //     break;
    default:
        cout << "invalid choice (switch case branch)";
        break;
    }
}

void MainMenu::handleAuthentication()
{
    User user;
    int userInput_int = 0;

    cout << "\n\t\t\t\tWelcome to the Recipe Book!" << endl
         << "Would you like to sign up for a new account or log in?" << endl
         << "(enter 1 for sign up, 2 for log in):\n";

    while (true)
    {
        cin >> userInput_int;

        // Check for invalid input or out-of-range values
        if (cin.fail() || (userInput_int != 1 && userInput_int != 2))
        {
            cout << "Invalid input. Please enter 1 for sign up or 2 for log in: ";
            cin.clear();                                         // Clear the error flag on `cin`
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        }
        else
        {
            break; // Valid input, exit the loop
        }
    }

    if (userInput_int == 1)
    {
        currentUser.signUp();
    }
    else if (userInput_int == 2)
    {
        currentUser.logIn();
    }
}
