project(memeory_management)
cmake_minimum_required(VERSION 2.8)

include_directories(${PROJECT_SOURCE_DIR})

add_compile_options(-c
                    -Wall
                    -Wextra
                    -Winit-self
                    -Wold-style-cast
                    -Woverloaded-virtual
                    -Wuninitialized
                    -pedantic
                    -pedantic-errors
                    -std=c++14
                    -g)

add_executable(example1 example1.cpp)
add_executable(example2 example2.cpp)
add_executable(example3 example3.cpp)
add_executable(list list.cpp)
