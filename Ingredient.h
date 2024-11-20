// I believe we can parse the data and then extract the ingredients from the data
// and push back into the ingredients vector

//updates...the test_recipe have the ingredients name separately, but not int he big recipe.csv
/*
recipe: "8 small Granny Smith apples, or as needed, ½ cup unsalted butter, 
3 tablespoons all-purpose flour, ½ cup white sugar ......"

test_recipe: {'quantity': '½', 'unit': 'teaspoon', 'name': 'dried oregano'}, 
             {'quantity': '4', 'unit': 'medium', 'name': 'skinless, boneless chicken breast halves - pounded 1/4 inch thick'}, 
             {'quantity': '4', 'unit': 'tablespoons', 'name': 'butter'}, ......


*/

#pragma once

class Ingredient : public Recipe {
    vector<Ingredient> ingredients;

private:
    

};