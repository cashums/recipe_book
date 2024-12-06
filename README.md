# Recipe Book & Search Engine
 > Authors: [Lydia Niu](https://github.com/LydiaNiu), [Cash Bruce](https://github.com/cashums), [Muhammad Sabeel](https://github.com/MuhammadS04), [Muhammad Ibrahim Abid](https://github.com/Bossmanthing098)


## Project Description
>
Overview
>  * 	We are creating a detailed and dynamic recipe search engine that filters through multiple attributes like ingredients, calories, cuisine variety, and user comments. While we aim for a robust and highly functional search engine, our focus extends beyond that by exploring the complexities of object-oriented programming. By building this project with class objects, we can enable features like adding personalized menus, leaving comments, and generating a "daily menu" based on user preferences.
>  * 	Additionally, the project emphasizes practicality and sustainability. Instead of encouraging users to search for completely new recipes requiring rare ingredients, it prioritizes using pre-owned ingredients, reducing grocery costs, and minimizing food waste. Users can search through an expansive database of recipes by various metrics—pre-owned ingredients, cook time, calories, and more—making it easy to find the next homemade meal.
>  * 	This all-in-one database not only provides recipe suggestions and calorie tracking but also stores the history of user-created meals. It’s a versatile tool that helps users navigate a variety of cooking ideas and promotes efficient, sustainable meal planning. We plan to expand on this after class to continue refining its usefulness in everyday cooking.
>    
Tools
>  * We are going to focus on using C++ and maybe some libraries to create/build up/analyze the .csv file. Additionally, we will use HTML and CSS to create a basic website interface.

Input/Output
>  The project will have two primary functions: 
>  * Users can create, store, view, and edit recipes to be stored in a greater recipe book.
>  * Users can navigate an existing recipe book to find entries matching user-selected filters, such as containing certain ingredients, meeting dietary restrictions, range of calories, rating. For example, when searching the book, a user should select any of the filtering conditions:
>      *  [checkbox] "What ingredients would you like to cook with?"
>      * 	[checkbox] “Do you have any dietary restrictions?”
>      * 	[user input] “Would you like to set a calorie range for your meal (Unit in K)?”
>      *  [checkbox] "The rating of the food: "
>      *  [user input] "Search by name: "
>    	
What are the features that the project provides?
>  * 	Search engine for recipes
>  * 	Algorithm that provides recipes based on user-inputted ingredients and other factors 
>  * 	History of favorite foods
>  * 	Calorie tracker
>  * 	Create new recipes
>  * 	Generate daily menu based on the search history
>  * 	User authentification/log-in feature

## User Interface Specification

### Navigation Diagram
>This navigation diagram outlines how users interact with different pages within a recipe application, illustrating the relationships and transitions between these pages:

>- **Entry Points**: Users start by either signing up or logging in. They can switch between these pages before accessing the main page.
>- **Main Page**: Acts as the central hub from which users can navigate to other sections, such as viewing favorite recipes, searching history, adding a recipe, or conducting a search.
>- **Page Relationships**:
>      - **Favorites and History**: From the main page, users can access their **favorite recipes** or **search history**. Both of the pages have a button to navigate user to go back to the main page.
>      - **Add Recipe Page**: From the main page, users can jump to the **add recipe page** to contribute a new recipe. This page has a button to navigate user to go back to the main page.
>      - **Search Functionality**: The **search button** on the main page directs users to the **searching page**, where they input filters. After applying filters, the **continue button** leads them to the **searching result** page. 
>      -  **searching result page**: From the result page, users can view all the filtered recipes and also go back to the search page to adjust their filters.
>- **Log Out**: Every page provides an option to log out, returning the user to the login screen.

<img width="556" alt="Screenshot 2024-11-04 at 9 38 16 PM" src="https://github.com/user-attachments/assets/ae4bb386-7203-47bd-9383-fb3c86c54dc3">


### Screen Layouts
>![image](https://github.com/user-attachments/assets/6cc30ea3-154e-4dd7-98d2-5bf913f41638)
>![image](https://github.com/user-attachments/assets/2579d136-1229-464c-9f7a-8879d8740e01)
>![image](https://github.com/user-attachments/assets/c265c156-15c9-4dd5-a35c-cd9504243b7e)
>![image](https://github.com/user-attachments/assets/00168683-c30e-4a43-82bc-1a678610c0c0)

>![image](https://github.com/user-attachments/assets/edf417e1-fef5-48a2-bed9-0e5b4ef58dd7)
>![image](https://github.com/user-attachments/assets/53d4ffff-4636-4ee9-b295-4edd3404f367)

>![image](https://github.com/user-attachments/assets/4af77db9-1ec2-4ad3-adbe-36be406072c1)


### Updated Screen Layouts
Our program primarily utilizes a text-based interface, as no dedicated UI/UX frontend has been implemented. However, users can seamlessly access and navigate between all features from the main menu. Below is a summary of the program's features:

> * **log in/ sign up**: user is able to either sign up a new account or log in to existed account. Once done, program automatically jump to main menu.
> * **main menu**: After completing any function, the program automatically returns to the main menu for ease of navigation.
>    * **view all recipes**: Displays all available recipe options. Users can select and print a recipe by entering its corresponding index.
>    * **add new recip**e: Allows users to add a new recipe to the database by entering the attributes step by step.
>    * **filter by ingredients**: enables users to search the recipe book using specific ingredients as filtering criteria.
>    * **favorite a recipe**: After viewing all recipes, users can mark a recipe as a favorite by entering its index.
>    * **View All Favorited Recipes**: Displays detailed information about all recipes marked as favorites.

## Class Diagram
 ![UML class (2)](https://github.com/user-attachments/assets/a7c80c52-e7df-4ea6-bdba-ed99daef9534)


 > * Recipe
 >     * Represents a single recipe in the recipe book. This class encapsulates all the necessary details and characteristics one would commonly search for when deciding what recipe to prepare.
 > * Ingredient
 >      * Represents an individual ingredient used in recipes. This class allows for detailed management of ingredients as well as classification based on attributes that link them to the recipes they will be used in.
 > * Comment
 >      * Represents a comment made by a user on a recipe. This class captures the interaction between users and recipes, allowing said users to create a social connection to their recipes.
>  * User
>       * Represents a user of the recipe book application. This class handles user-related functionalities such as adding comments, tracking personal preferences, and everything related to linking a user with their favorite recipes.
>  * Authentication
>       * Contains the umbrella of functions that allow for users to sign in and log out of their accounts, allowing for a seamless experience for linking a user with their history and saved recipes.
>  * Recipe Book
>       * The sum collection of all recipes as one unified recipe book; the purpose of the application. Stores, manages, and sorts through all of a user's saved recipes.

## Updated Class Diagram
![UML class - Page 2 (1)](https://github.com/user-attachments/assets/ae45273b-13b0-4630-a186-989dee676e6b)

 > * SOLID Principles:
 >   * Originally, the Recipe class was far too bloated and filled with too many member variables and member functions. After updating, the main components of a Recipe (Metadata, Steps, Comments, and Ingredients) have been placed into their own classes which aggregate into Recipe. This change more closely conforms to the Single Responsibility Principle, which makes Recipe as a whole easier to test, understand, and modify.
 >   * Separating Nutrition from NutritionParser ensures that, even though NutritionParser is usually necessary to fetch information, Nutrition can still work independently without it. The Nutrition class is closed for modification but open for extension; if new sources of nutrition data are added, only the NutritionParser or its extensions need to change, leaving Nutrition untouched. This adheres to the Open-Closed Principle, allowing for greater independence among Nutrition-related assets.
>    * Recipe now delegates handling of steps, comments, and ingredients to dedicated classes like RecipeSteps and RecipeComments. These classes allow for focused operations like addComment or addStep, which are separate from the Recipe itself (since these items make up Recipe, but are not directly affectable parts of Recipe). Before, Recipe itself managed all these responsibilities directly, so as a result, clients that only care about one aspect (e.g., steps or comments) are forced to interact with methods and data they don’t need. Due to these changes, the code now more closely adheres to Interface Segregation Principle, effectively keeping each class contained to what it should deal with directly and preventing the user from messing with things they don’t intend to.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history.
>  * Each team member should also submit the Individual Contributions Form on Canvas for this final phase. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for the final phase, and a description of their contributions. Remember that each team member should submit the form individually.
 
 ## Screenshots
 > ![Screenshot 2024-12-06 092052](https://github.com/user-attachments/assets/fee97e87-c163-4be9-a867-7683f0410f64)
 > * The log-in screen.
 >
 >
 >
 > ![Screenshot 2024-12-06 092102](https://github.com/user-attachments/assets/9a999b4b-e9ec-4d3e-a669-593656e2fd0a)
> * Main menu.
>
>
>
 > ![Screenshot 2024-12-06 092149](https://github.com/user-attachments/assets/69a80eb7-1f4d-457e-b4fa-91cff2498e8e)
> * Viewing all Recipes.
>
>
>  
 > ![Screenshot 2024-12-06 092520](https://github.com/user-attachments/assets/da766bf3-4cb0-45a5-9c80-a8ef47316522)
> * Viewing a single Recipe in detail.
>
>
> 
 > ![Screenshot 2024-12-06 092551](https://github.com/user-attachments/assets/11fb60a9-5eb5-4e68-b95e-325026d69f2f)
> * Searching (in this case, by Ingredient).
>
>
>   


 ## Installation/Usage
 > Instructions on installing and running your application
 > * To install, download the repository. The Google Test repository is not required for individual download due to being bundled within CMake.
 >  * To run, run the following command:
 >       * clear && cmake . && make && ./runCode
 >  * This will clear any previous output from your terminal, compile, and execute the code.
 > * Once running, simply follow along with user prompts to navigate the Cookbook. 
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
