#include "mainMenu.h"

using namespace std;

void mainMenu::printTitleScreen() {
    cout << "Welcome to the Coder's Cookbook!\nWould you like to:" << endl << endl;
    cout << "r: Read from a CSV file to create Recipes" << endl;
    cout << "c: Create a new Recipe" << endl;
    cout << "s: Search through your cookbook" << endl;
}