cmake_minimum_required(VERSION 3.10)
project(Laba3 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(header)

set(SOURCES
  src/MenuFunctions.cpp
    src/main.cpp
    src/Human.cpp
    src/CommissionMember.cpp
    src/TeacherCommissionMember.cpp
    src/UniversityTeacher.cpp
)

add_executable(laba3_exec ${SOURCES})
