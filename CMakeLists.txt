cmake_minimum_required(VERSION 3.10) # Minimum version of CMake

project(mydb) # Name of your project

set(CMAKE_CXX_STANDARD 14) # Set C++ standard

include_directories(include)

add_executable(mydb src/main.cpp src/BST.cpp src/KVDB.cpp) # Add executable target with source file
add_library(kvdb SHARED src/BST.cpp src/KVDB.cpp)
target_include_directories(kvdb PUBLIC include)
set_target_properties(kvdb PROPERTIES PUBLIC_HEADER "include/KVDB.h;include/BST.h")
install(TARGETS kvdb
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include)