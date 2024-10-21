# Minimum CMAKE version
cmake_minimum_required(VERSION 3.10)

# Set the name of the project
project(csadkopiy09)

# Enter C++ 17 Standart
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Path to our cpp file for build
add_executable(${PROJECT_NAME} src/SW_task2/csadkopiy09/csadkopiy09/csadkopiy09.cpp)

# Add Boost to project
find_package(Boost 1.86 REQUIRED COMPONENTS system)

# Link Boost to project
target_link_libraries(${PROJECT_NAME} PRIVATE Boost::system pthread)


