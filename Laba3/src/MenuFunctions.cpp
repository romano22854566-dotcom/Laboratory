#include "MenuFunctions.h"
#include <iostream>

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

void resizePeopleArray(Human**& people,int& capacity) {
    capacity *= 2;
    Human** newPeople = new Human * [capacity];
    for (int i = 0; i < capacity / 2; i++) {
        newPeople[i] = people[i];
    }
    delete[] people;
    people = newPeople;
}

void createUniversityTeacher(Human**& people,int& peopleCount,int& capacity) {
    if (peopleCount >= capacity) {
        resizePeopleArray(people,capacity);
    }

    people[peopleCount] = new UniversityTeacher();
    people[peopleCount]->input();
    peopleCount++;
    std::cout << "Преподаватель университета создан!\n";
}

void createCommissionMember(Human**& people,int& peopleCount,int& capacity) {
    if (peopleCount >= capacity) {
        resizePeopleArray(people,capacity);
    }

    people[peopleCount] = new CommissionMember();
    people[peopleCount]->input();
    peopleCount++;
    std::cout << "Член комиссии создан!\n";
}

void createTeacherCommissionMember(Human**& people,int& peopleCount,int& capacity) {
    if (peopleCount >= capacity) {
        resizePeopleArray(people,capacity);
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
        std::cout << "\n=== ВСЕ СОЗДАННЫЕ ЛЮДИ ===\n";
        for (int i = 0; i < peopleCount; i++) {
            std::cout << "\n--- Человек " << (i + 1) << " ---\n";
            people[i]->display();
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
    std::cin >> index;
    index--;

    if (index >= 0 && index < peopleCount) {
        UniversityTeacher* teacher = dynamic_cast<UniversityTeacher*>(people[index]);
        if (teacher) {
            char work[100];
            std::cout << "Введите название научного труда: ";
            std::cin.ignore();
            std::cin.getline(work,100);
            teacher->addScientificWork(work);
            std::cout << "Научный труд добавлен!\n";
        }
        else {
            std::cout << "Выбранный человек не является преподавателем университета!\n";
        }
    }
    else {
        std::cout << "Неверный индекс!\n";
    }
}

void addAutobiographyLine(Human** people,int peopleCount) {
    if (peopleCount == 0) {
        std::cout << "Нет созданных людей.\n";
        return;
    }

    std::cout << "Выберите члена комиссии (1-" << peopleCount << "): ";
    int index;
    std::cin >> index;
    index--;

    if (index >= 0 && index < peopleCount) {
        CommissionMember* member = dynamic_cast<CommissionMember*>(people[index]);
        if (member) {
            char line[100];
            std::cout << "Введите строку автобиографии: ";
            std::cin.ignore();
            std::cin.getline(line,100);
            member->addAutobiographyLine(line);
            std::cout << "Строка автобиографии добавлена!\n";
        }
        else {
            std::cout << "Выбранный человек не является членом комиссии!\n";
        }
    }
    else {
        std::cout << "Неверный индекс!\n";
    }
}

void addCommissionWork(Human** people,int peopleCount) {
    if (peopleCount == 0) {
        std::cout << "Нет созданных людей.\n";
        return;
    }

    std::cout << "Выберите преподавателя-члена комиссии (1-" << peopleCount << "): ";
    int index;
    std::cin >> index;
    index--;

    if (index >= 0 && index < peopleCount) {
        TeacherCommissionMember* tcm = dynamic_cast<TeacherCommissionMember*>(people[index]);
        if (tcm) {
            char work[100];
            std::cout << "Введите работу в комиссии: ";
            std::cin.ignore();
            std::cin.getline(work,100);
            tcm->addCommissionWork(work);
            std::cout << "Работа в комиссии добавлена!\n";
        }
        else {
            std::cout << "Выбранный человек не является преподавателем-членом комиссии!\n";
        }
    }
    else {
        std::cout << "Неверный индекс!\n";
    }
}

void cleanup(Human** people,int peopleCount) {
    for (int i = 0; i < peopleCount; i++) {
        delete people[i];
    }
    delete[] people;
}