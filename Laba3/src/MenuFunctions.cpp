#include "MenuFunctions.h"
#include <iostream>
#include <cstring>

void displayMenu() {
    std::cout << "\n=== ���� ===\n";
    std::cout << "1. ������� ������������� ������������\n";
    std::cout << "2. ������� ����� ��������\n";
    std::cout << "3. ������� �������������-����� ��������\n";
    std::cout << "4. �������� ���� ��������� �����\n";
    std::cout << "5. �������� ������� ���� �������������\n";
    std::cout << "6. �������� ������ ������������� ����� ��������\n";
    std::cout << "7. �������� ������ � ��������\n";
    std::cout << "0. �����\n";
    std::cout << "�������� �����: ";
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
        std::cout << "������������� ������������ ������!\n";
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
        std::cout << "���� �������� ������!\n";
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
        std::cout << "�������������-���� �������� ������!\n";
    }
}

void displayAllPeople(Human** people,int peopleCount) {
    if (peopleCount == 0) {
        std::cout << "��� ��������� �����.\n";
    }
    else {
        std::cout << "\n=== ��� ��������� ���� (" << peopleCount << ") ===\n";
        for (int i = 0; i < peopleCount; i++) {
            if (people[i] != nullptr) {
                std::cout << "\n--- ������� " << (i + 1) << " ---\n";
                people[i]->display();
            }
        }
    }
}

void addScientificWork(Human** people,int peopleCount) {
    if (peopleCount == 0) {
        std::cout << "��� ��������� �����.\n";
        return;
    }

    std::cout << "�������� ������������� (1-" << peopleCount << "): ";
    int index;
    if (!(std::cin >> index)) {
        std::cout << "�������� ����!\n";
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        return;
    }
    index--;

    if (index < 0 || index >= peopleCount || people[index] == nullptr) {
        std::cout << "�������� ������!\n";
        return;
    }

    UniversityTeacher* teacher = dynamic_cast<UniversityTeacher*>(people[index]);
    if (teacher == nullptr) {
        std::cout << "��������� ������� �� �������� �������������� ������������!\n";
        return;
    }

    char work[256];
    std::cout << "������� �������� �������� �����: ";
    std::cin.ignore();
    if (std::cin.getline(work,256)) {
        teacher->addScientificWork(work);
        std::cout << "������� ���� ��������!\n";
    }
}

void addAutobiographyLine(Human** people,int peopleCount) {
    if (peopleCount == 0) {
        std::cout << "��� ��������� �����.\n";
        return;
    }

    std::cout << "�������� ����� �������� (1-" << peopleCount << "): ";
    int index;
    if (!(std::cin >> index)) {
        std::cout << "�������� ����!\n";
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        return;
    }
    index--;

    if (index < 0 || index >= peopleCount || people[index] == nullptr) {
        std::cout << "�������� ������!\n";
        return;
    }

    CommissionMember* member = dynamic_cast<CommissionMember*>(people[index]);
    if (member == nullptr) {
        std::cout << "��������� ������� �� �������� ������ ��������!\n";
        return;
    }

    char line[256];
    std::cout << "������� ������ �������������: ";
    std::cin.ignore();
    if (std::cin.getline(line,256)) {
        member->addAutobiographyLine(line);
        std::cout << "������ ������������� ���������!\n";
    }
}

void addCommissionWork(Human** people,int peopleCount) {
    if (peopleCount == 0) {
        std::cout << "��� ��������� �����.\n";
        return;
    }

    std::cout << "�������� �������������-����� �������� (1-" << peopleCount << "): ";
    int index;
    if (!(std::cin >> index)) {
        std::cout << "�������� ����!\n";
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        return;
    }
    index--;

    if (index < 0 || index >= peopleCount || people[index] == nullptr) {
        std::cout << "�������� ������!\n";
        return;
    }

    TeacherCommissionMember* tcm = dynamic_cast<TeacherCommissionMember*>(people[index]);
    if (tcm == nullptr) {
        std::cout << "��������� ������� �� �������� ��������������-������ ��������!\n";
        return;
    }

    char work[256];
    std::cout << "������� ������ � ��������: ";
    std::cin.ignore();
    if (std::cin.getline(work,256)) {
        tcm->addCommissionWork(work);
        std::cout << "������ � �������� ���������!\n";
    }
}