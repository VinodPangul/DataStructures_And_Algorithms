cmake_minimum_required(VERSION 3.13)
project(UnorderedLinkedList)

set(CMAKE_CXX_STANDARD 14)

add_executable(UnorderedLinkedList main.cpp LinkedListType.h LinkedListType.cpp
        unorderedLinkedList.h unorderedLinkedList.cpp)