cmake_minimum_required(VERSION 3.14)

set(This LinkedList)
project(${This} C CXX)
set(CMAKE_CXX_STANDARD 14)

enable_testing()

# Dependacies

add_subdirectory(GoogleTest)

set(Headers
    LinkedList.hpp
    Node.hpp
)

set(Sources
    main.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)