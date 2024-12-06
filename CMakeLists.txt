# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(SingleFileExample VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(runCode 
    mainMenu.cpp
    dataParser.cpp
    Recipe.cpp
    RecipeFilter.cpp
    main.cpp
    Book.cpp
    User.cpp
)