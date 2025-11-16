cmake_minimum_required(VERSION 3.10)
project(Laba8 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(header)

set(SOURCES
    src/main.cpp
    src/Employee.cpp
    src/FileManager.cpp
    src/Menu.cpp
)

add_executable(laba8_exec ${SOURCES})
