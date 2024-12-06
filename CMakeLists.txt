include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

# Download and make Google Test available
FetchContent_MakeAvailable(googletest)

# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(SingleFileExample VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the main executable
add_executable(runCode 
    mainMenu.cpp
    dataParser.cpp
    Recipe.cpp
    RecipeFilter.cpp
    main.cpp
    Book.cpp
    User.cpp
    Output.cpp
)

# Add the test executable
add_executable(unitTests
    test/SearchTests.cpp
    dataParser.cpp
    Recipe.cpp
    RecipeFilter.cpp
    Book.cpp
    User.cpp
    Output.cpp
)

# Link the test executable to the Google Test libraries
target_link_libraries(unitTests gtest gtest_main pthread)

# Enable testing
enable_testing()

# Add the test to the list of tests
add_test(NAME SearchTests COMMAND unitTests)