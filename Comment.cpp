#include "Comment.h"
using namespace std;

// Checked for destructor Not Needed
Comment::Comment(string text, int userID, int recipeID, int commentID)
{
    this->commentText = text;
    this->userID = userID;
    this->recipeID = recipeID;
    this->commentID = commentID;
}

string Comment::getCommentText()
{
    return this->commentText;
}
int Comment::getUserID()
{
    return this->userID;
}
int Comment::getRecipeID()
{
    return this->recipeID;
}
int Comment::getCommentID()
{
    return this->commentID;
}

void Comment::editComment(string text)
{
    this->commentText = text;
}

void Comment::deleteComment()
{
    this->commentText = {};
}
