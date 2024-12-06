#include "User.h"
#include "Book.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void filteringPage() {}

// User* signUp(){
//     string userName, password;
//     cout << "What's your user name (please input letters/special characters/numbers without space): ";
//     cin >> userName;
//     cout << "What's your password (please input letters/special characters/numbers without space): ";
//     cin >> password;

//     if (userExists(userName)) {
//         int user_input;
//         cout << "This user name is already being used. Input 1 for sign up and 2 for log in: ";
//         cin >> user_input;

//         while (cin.fail() || (user_input != 1 && user_input != 2)) {
//             cout << "Your input is invalid. Please input again: ";
//             cin >> user_input;
//         }

//         if (user_input == 1) {
//             signUp();
//         } else if (user_input == 2) {
//             logIn();
//         }
//         return;
//     }
//     User* new_user = new User(userName, password);

//     return new_user;
// }

// User* logIn(vector<User*> &userVec){
//     string userName, password;
//     int user_input;
//     cout << "What's your user name: " << endl;
//     cin >> userName;
//     cout << "What's your password: " << endl;
//     cin >> password;
//     for (int i = 0; i < userVec.size(); i++){
//         User* userPointer = userVec[i];
//         User& user = *userPointer;
//         if (user.getUserName() == userName){
//             if (user.getUserPassword() == password){
//                 user.logIn(userName, password);
//                 return userPointer;
//             }else{
//                 cout << "Incorrect password. Please try again..." << endl;
//                 logIn(userVec);
//             }
//         }else{
//             cout << endl << "This user name is not registered yet. Input 1 for sign up and 2 for log in: ";
//             cin >> user_input;
//             while (cin.fail() || user_input != 1 || user_input != 2){
//                 cout << endl << "Your input is invalid. Please input again: ";
//                 cin >> user_input;
//             }
//             if (user_input == 1){ signUp(userVec); }
//             else if(user_input == 2){ logIn(userVec); }
//         }
//     }
// }

void mainMenu(User &user)
{
    cout << "------------Welcome to Recipe Book------------" << endl
         << "Here is your personalized daily menu: " << endl;
    // I want to call the generateMenu and displayMenu, both functions are in the
    // sub class "DailyMenu" which derived from the User class
    return;
}

int main()
{
    Book book;
    User *user_ptr = nullptr;
    int userInput_int = 0;
    User user;
    cout << "Welcome to the Recipe Book!" << endl
         << "Would you like to sign up for a new account or log in?" << endl
         << "(enter 1 for sign up, 2 for log in): ";
    cin >> userInput_int;

    while (cin.fail() || (userInput_int != 1 && userInput_int != 2))
    {
        cout << "Your input is invalid. Please input again: ";
        cin >> userInput_int;
    }
    if (userInput_int == 1)
    {
        user = *user.signUp();
    }
    else if (userInput_int == 2)
    {
        user = *user.logIn();
    }

    mainMenu(user);
    book.viewAllRecipes();

    cout << "\nAdd new recipe:\n";
    // if you addRecipe . It will write to CSV and Add to current vector
    //book.addRecipe();      // This function works. its commented so it doesnt run
    //book.viewAllRecipes(); // works

    return 1;
}