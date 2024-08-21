cmake_minimum_required(VERSION 3.27)
project(BTree)

set(CMAKE_CXX_STANDARD 26)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(executeTests.out
        test/LinkedList_test.cpp)
target_link_libraries(executeTests.out ${GTEST_LIBRARIES} pthread)

add_executable(LinkedList.out
        src/main.cpp
        src/lib/LinkedList/Node/Node.cpp
        src/lib/LinkedList/Node/Node.h
        src/lib/LinkedList/LinkedList.cpp
        src/lib/LinkedList/LinkedList.h
)
