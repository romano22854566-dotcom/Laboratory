#include "MenuFunctions.h"
#include <iostream>

void displayMenu() {
    std::cout << "\n=== МЕНЮ ===\n";
    std::cout << "1. Создать преподавателя университета\n";
    std::cout << "2. Создать члена комиссии\n";
    std::cout << "3. Создать преподавателя-члена комиссии\n";
    std::cout << "4. Показать всех созданных людей\n";
    std::cout << "0. Выход\n";
    std::cout << "Выберите опцию: ";
}

void resizePeopleArray(Human**& people,int& peopleCount,int& capacity) {
    int newCapacity = capacity * 2;
    Human** newPeople = new Human * [newCapacity];
    for (int i = 0; i < peopleCount; i++) {
        newPeople[i] = people[i];
    }
    delete[] people;
    people = newPeople;
    capacity = newCapacity;
}

void initializePeople(Human**& people,int& capacity) {
    capacity = 2;
    people = new Human * [capacity];
}

void cleanup(Human** people,int peopleCount) {
    for (int i = 0; i < peopleCount; i++) {
        delete people[i];
    }
    delete[] people;
}

void createUniversityTeacher(Human**& people,int& peopleCount,int& capacity) {
    if (peopleCount >= capacity) {
        resizePeopleArray(people,peopleCount,capacity);
    }
    people[peopleCount] = new UniversityTeacher();
    people[peopleCount]->input();
    peopleCount++;
    std::cout << "Преподаватель университета создан!\n";
}

void createCommissionMember(Human**& people,int& peopleCount,int& capacity) {
    if (peopleCount >= capacity) {
        resizePeopleArray(people,peopleCount,capacity);
    }
    people[peopleCount] = new CommissionMember();
    people[peopleCount]->input();
    peopleCount++;
    std::cout << "Член комиссии создан!\n";
}

void createTeacherCommissionMember(Human**& people,int& peopleCount,int& capacity) {
    if (peopleCount >= capacity) {
        resizePeopleArray(people,peopleCount,capacity);
    }
    people[peopleCount] = new TeacherCommissionMember();
    people[peopleCount]->input();
    peopleCount++;
    std::cout << "Преподаватель-член комиссии создан!\n";
}

void displayAllPeople(Human** people,int peopleCount) {
    if (peopleCount == 0) {
        std::cout << "Нет созданных людей.\n";
    }
    else {
        std::cout << "\n=== ВСЕ СОЗДАННЫЕ ЛЮДИ (" << peopleCount << ") ===\n";
        for (int i = 0; i < peopleCount; i++) {
            std::cout << "\n--- Человек " << (i + 1) << " ---\n";
            people[i]->display();
        }
    }
}