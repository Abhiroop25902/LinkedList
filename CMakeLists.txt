cmake_minimum_required(VERSION 3.27)
project(BTree)

set(CMAKE_CXX_STANDARD 26)

add_executable(BTree src/main.cpp
        src/lib/LinkedList/Node/Node.cpp
        src/lib/LinkedList/Node/Node.h
        src/lib/LinkedList/LinkedList.cpp
        src/lib/LinkedList/LinkedList.h
)
