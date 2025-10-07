#include "MenuFunctions.h"
#include <iostream>
#include <cstring>

void displayMenu() {
    std::cout << "\n=== МЕНЮ ===\n";
    std::cout << "1. Создать преподавателя университета\n";
    std::cout << "2. Создать члена комиссии\n";
    std::cout << "3. Создать преподавателя-члена комиссии\n";
    std::cout << "4. Показать всех созданных людей\n";
    std::cout << "5. Добавить научный труд преподавателю\n";
    std::cout << "6. Добавить строку автобиографии члену комиссии\n";
    std::cout << "7. Добавить работу в комиссии\n";
    std::cout << "0. Выход\n";
    std::cout << "Выберите опцию: ";
}

void resizePeopleArray(Human**& people,int& capacity,int peopleCount) {
    int newCapacity = capacity * 2;
    Human** newPeople = new Human * [newCapacity];
    for (int i = 0; i < peopleCount; i++) {
        newPeople[i] = people[i];
    }
    for (int i = peopleCount; i < newCapacity; i++) {
        newPeople[i] = nullptr;
    }
    delete[] people;
    people = newPeople;
    capacity = newCapacity;
}

void initializePeople(Human**& people,int& capacity) {
    capacity = 2;
    people = new Human * [capacity];
    for (int i = 0; i < capacity; i++) {
        people[i] = nullptr;
    }
}

void cleanup(Human** people,int peopleCount) {
    for (int i = 0; i < peopleCount; i++) {
        if (people[i] != nullptr) {
            delete people[i];
        }
    }
    delete[] people;
}

void createUniversityTeacher(Human**& people,int& peopleCount,int& capacity) {
    if (peopleCount >= capacity) {
        resizePeopleArray(people,capacity,peopleCount);
    }
    people[peopleCount] = new UniversityTeacher();
    if (people[peopleCount] != nullptr) {
        people[peopleCount]->input();
        peopleCount++;
        std::cout << "Преподаватель университета создан!\n";
    }
}

void createCommissionMember(Human**& people,int& peopleCount,int& capacity) {
    if (peopleCount >= capacity) {
        resizePeopleArray(people,capacity,peopleCount);
    }
    people[peopleCount] = new CommissionMember();
    if (people[peopleCount] != nullptr) {
        people[peopleCount]->input();
        peopleCount++;
        std::cout << "Член комиссии создан!\n";
    }
}

void createTeacherCommissionMember(Human**& people,int& peopleCount,int& capacity) {
    if (peopleCount >= capacity) {
        resizePeopleArray(people,capacity,peopleCount);
    }
    people[peopleCount] = new TeacherCommissionMember();
    if (people[peopleCount] != nullptr) {
        people[peopleCount]->input();
        peopleCount++;
        std::cout << "Преподаватель-член комиссии создан!\n";
    }
}

void displayAllPeople(Human** people,int peopleCount) {
    if (peopleCount == 0) {
        std::cout << "Нет созданных людей.\n";
    }
    else {
        std::cout << "\n=== ВСЕ СОЗДАННЫЕ ЛЮДИ (" << peopleCount << ") ===\n";
        for (int i = 0; i < peopleCount; i++) {
            if (people[i] != nullptr) {
                std::cout << "\n--- Человек " << (i + 1) << " ---\n";
                people[i]->display();
            }
        }
    }
}

void addScientificWork(Human** people,int peopleCount) {
    if (peopleCount == 0) {
        std::cout << "Нет созданных людей.\n";
        return;
    }

    std::cout << "Выберите преподавателя (1-" << peopleCount << "): ";
    int index;
    if (!(std::cin >> index)) {
        std::cout << "Неверный ввод!\n";
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        return;
    }
    index--;

    if (index < 0 || index >= peopleCount || people[index] == nullptr) {
        std::cout << "Неверный индекс!\n";
        return;
    }

    UniversityTeacher* teacher = dynamic_cast<UniversityTeacher*>(people[index]);
    if (teacher == nullptr) {
        std::cout << "Выбранный человек не является преподавателем университета!\n";
        return;
    }

    char work[256];
    std::cout << "Введите название научного труда: ";
    std::cin.ignore();
    if (std::cin.getline(work,256)) {
        teacher->addScientificWork(work);
        std::cout << "Научный труд добавлен!\n";
    }
}

void addAutobiographyLine(Human** people,int peopleCount) {
    if (peopleCount == 0) {
        std::cout << "Нет созданных людей.\n";
        return;
    }

    std::cout << "Выберите члена комиссии (1-" << peopleCount << "): ";
    int index;
    if (!(std::cin >> index)) {
        std::cout << "Неверный ввод!\n";
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        return;
    }
    index--;

    if (index < 0 || index >= peopleCount || people[index] == nullptr) {
        std::cout << "Неверный индекс!\n";
        return;
    }

    CommissionMember* member = dynamic_cast<CommissionMember*>(people[index]);
    if (member == nullptr) {
        std::cout << "Выбранный человек не является членом комиссии!\n";
        return;
    }

    char line[256];
    std::cout << "Введите строку автобиографии: ";
    std::cin.ignore();
    if (std::cin.getline(line,256)) {
        member->addAutobiographyLine(line);
        std::cout << "Строка автобиографии добавлена!\n";
    }
}

void addCommissionWork(Human** people,int peopleCount) {
    if (peopleCount == 0) {
        std::cout << "Нет созданных людей.\n";
        return;
    }

    std::cout << "Выберите преподавателя-члена комиссии (1-" << peopleCount << "): ";
    int index;
    if (!(std::cin >> index)) {
        std::cout << "Неверный ввод!\n";
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        return;
    }
    index--;

    if (index < 0 || index >= peopleCount || people[index] == nullptr) {
        std::cout << "Неверный индекс!\n";
        return;
    }

    TeacherCommissionMember* tcm = dynamic_cast<TeacherCommissionMember*>(people[index]);
    if (tcm == nullptr) {
        std::cout << "Выбранный человек не является преподавателем-членом комиссии!\n";
        return;
    }

    char work[256];
    std::cout << "Введите работу в комиссии: ";
    std::cin.ignore();
    if (std::cin.getline(work,256)) {
        tcm->addCommissionWork(work);
        std::cout << "Работа в комиссии добавлена!\n";
    }
}