cmake_minimum_required(VERSION 3.10)
project(Laba4 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/Functions.cpp
    src/Figure.cpp
    src/Circle.cpp
    src/Rectangle.cpp
    src/Trapezoid.cpp
)

add_executable(laba4_exec ${SOURCES})
