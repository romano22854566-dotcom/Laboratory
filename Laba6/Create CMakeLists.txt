cmake_minimum_required(VERSION 3.10)
project(Laba6 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(header)

set(SOURCES
   src/main.cpp
    src/menu.cpp
    src/MyString.cpp
    src/MyException.cpp
)

add_executable(laba6_exec ${SOURCES})
