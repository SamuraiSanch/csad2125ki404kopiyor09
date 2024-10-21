# Вказуємо мінімальну версію CMake
cmake_minimum_required(VERSION 3.10)

# Назва проекту
project(csadkopiy09)

# Вказуємо стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Вказуємо виконуваний файл
add_executable(${PROJECT_NAME} src/SW_task2/csadkopiy09/csadkopiy09/csadkopiy09.cpp)

# Підключаємо бібліотеку Boost
find_package(Boost 1.86 REQUIRED COMPONENTS system)

# Лінкуємо бібліотеки Boost до нашого проекту
target_link_libraries(${PROJECT_NAME} PRIVATE Boost::system pthread)


