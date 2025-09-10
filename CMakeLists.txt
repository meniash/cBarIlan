cmake_minimum_required(VERSION 3.15)
project(cBarIlan C)

set(CMAKE_C_STANDARD 99)

# Add each subproject
add_subdirectory(ex1)
add_subdirectory(ex2)
add_subdirectory(ex3)
add_subdirectory(ex4)
add_subdirectory(ex5)
add_subdirectory(ex6)
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} --build . --target clean
    COMMAND ${CMAKE_COMMAND} -E echo "Object files and executables cleaned!"
)
