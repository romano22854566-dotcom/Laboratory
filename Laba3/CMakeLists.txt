cmake_minimum_required(VERSION 3.10)
project(Laba3 LANGUAGES CXX)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем все исходные файлы
set(SOURCES
    main.cpp
    Human.cpp
    CommissionMember.cpp
    MenuFunctions.cpp
    TeacherCommissionMember.cpp
    UniversityTeacher.cpp
)

# Заголовочные файлы (не обязательно, но удобно для IDE)
set(HEADERS
    Human.h
    CommissionMember.h
    MenuFunctions.h
    TeacherCommissionMember.h
    UniversityTeacher.h
)

# Создаём исполняемый файл
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
