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

 > 
 > ## Phase II
 > In addition to completing the "User Interface Specification" and "Class Diagram" sections below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` column (aka Sprint Backlog).
 >   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
 > * Each team member needs to submit the Individual Contributions Form on Canvas for this phase. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for phase  II, and a description of their contributions. Remember that each team member should submit the form individually.
 > * Schedule two check-ins using Calendly. Both time slots should be during your lab on week 6. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
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
><img width="965" alt="Screenshot 2024-11-04 at 10 08 29 PM" src="https://github.com/user-attachments/assets/34e9fcde-b91e-41bb-9db2-4ca0b210a8b8">
><img width="1013" alt="Screenshot 2024-11-04 at 10 08 53 PM" src="https://github.com/user-attachments/assets/1ea5df5a-3af2-4123-b155-73400ed56848">
><img width="1010" alt="Screenshot 2024-11-04 at 10 09 11 PM" src="https://github.com/user-attachments/assets/3bd45d41-754e-403c-bc6a-3d9d19586ac1">
><img width="1010" alt="Screenshot 2024-11-04 at 10 09 44 PM" src="https://github.com/user-attachments/assets/e944b556-edfd-4753-8aaf-1b6debd7a1e6">

>





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

 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * Make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
>  * Each team member should also submit the Individual Contributions Form on Canvas for phase III. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for phase III, and a description of their contributions. Remember that each team member should submit the form individually.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history.
>  * Each team member should also submit the Individual Contributions Form on Canvas for this final phase. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for the final phase, and a description of their contributions. Remember that each team member should submit the form individually.
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
