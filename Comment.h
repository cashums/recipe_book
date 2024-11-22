#pragma once

#include <iostream>
using namespace std;

class Comment
{
private:
    string commentText;
    int userID;
    int recipeID;
    int commentID;

public:
    Comment(string text, int userID, int recipeID, int commentID); // used to initialize a comment
    string getCommentText();
    int getUserID();
    int getRecipeID();
    int getCommentID();

    void editComment(string text);
    void deleteComment();
};