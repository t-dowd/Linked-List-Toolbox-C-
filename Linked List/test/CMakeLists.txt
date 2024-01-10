cmake_minimum_required(VERSION 3.14)

set(This ExampleTests)

set(Sources
    ExampleTests.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    LinkedList
)

add_test(
    Name ${This}
    COMMAND ${This}
)