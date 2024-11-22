# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(SingleFileExample VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/external/json)

# Add the executable
add_executable(runCode dataInputter.cpp)