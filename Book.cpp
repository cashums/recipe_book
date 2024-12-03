#include "Book.h"

#include <iostream>
using namespace std;

vector<Recipe*> Book::getBook() {
    return currBook;
}

void Book::addRecipe() {
    cout << "Add a new recipe." << endl;
    // add code to create a new Recipe object from user input
}