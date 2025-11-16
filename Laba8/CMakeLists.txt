cmake_minimum_required(VERSION 3.10)
project(Laba8 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/menu.cpp
    src/Algorithms.cpp
    src/SinglyLinkedList.cpp
    src/Iterator.cpp
    src/Node.cpp
)

add_executable(laba8_exec ${SOURCES})
