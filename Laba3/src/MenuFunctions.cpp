#include "MenuFunctions.h"
#include <iostream>

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
    std::cout << "������������� ������������ ������!\n";
}

void createCommissionMember(Human**& people,int& peopleCount,int& capacity) {
    if (peopleCount >= capacity) {
        resizePeopleArray(people,capacity);
    }

    people[peopleCount] = new CommissionMember();
    people[peopleCount]->input();
    peopleCount++;
    std::cout << "���� �������� ������!\n";
}

void createTeacherCommissionMember(Human**& people,int& peopleCount,int& capacity) {
    if (peopleCount >= capacity) {
        resizePeopleArray(people,capacity);
    }

    people[peopleCount] = new TeacherCommissionMember();
    people[peopleCount]->input();
    peopleCount++;
    std::cout << "�������������-���� �������� ������!\n";
}

void displayAllPeople(Human** people,int peopleCount) {
    if (peopleCount == 0) {
        std::cout << "��� ��������� �����.\n";
    }
    else {
        std::cout << "\n=== ��� ��������� ���� ===\n";
        for (int i = 0; i < peopleCount; i++) {
            std::cout << "\n--- ������� " << (i + 1) << " ---\n";
            people[i]->display();
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
    std::cin >> index;
    index--;

    if (index >= 0 && index < peopleCount) {
        UniversityTeacher* teacher = dynamic_cast<UniversityTeacher*>(people[index]);
        if (teacher) {
            char work[100];
            std::cout << "������� �������� �������� �����: ";
            std::cin.ignore();
            std::cin.getline(work,100);
            teacher->addScientificWork(work);
            std::cout << "������� ���� ��������!\n";
        }
        else {
            std::cout << "��������� ������� �� �������� �������������� ������������!\n";
        }
    }
    else {
        std::cout << "�������� ������!\n";
    }
}

void addAutobiographyLine(Human** people,int peopleCount) {
    if (peopleCount == 0) {
        std::cout << "��� ��������� �����.\n";
        return;
    }

    std::cout << "�������� ����� �������� (1-" << peopleCount << "): ";
    int index;
    std::cin >> index;
    index--;

    if (index >= 0 && index < peopleCount) {
        CommissionMember* member = dynamic_cast<CommissionMember*>(people[index]);
        if (member) {
            char line[100];
            std::cout << "������� ������ �������������: ";
            std::cin.ignore();
            std::cin.getline(line,100);
            member->addAutobiographyLine(line);
            std::cout << "������ ������������� ���������!\n";
        }
        else {
            std::cout << "��������� ������� �� �������� ������ ��������!\n";
        }
    }
    else {
        std::cout << "�������� ������!\n";
    }
}

void addCommissionWork(Human** people,int peopleCount) {
    if (peopleCount == 0) {
        std::cout << "��� ��������� �����.\n";
        return;
    }

    std::cout << "�������� �������������-����� �������� (1-" << peopleCount << "): ";
    int index;
    std::cin >> index;
    index--;

    if (index >= 0 && index < peopleCount) {
        TeacherCommissionMember* tcm = dynamic_cast<TeacherCommissionMember*>(people[index]);
        if (tcm) {
            char work[100];
            std::cout << "������� ������ � ��������: ";
            std::cin.ignore();
            std::cin.getline(work,100);
            tcm->addCommissionWork(work);
            std::cout << "������ � �������� ���������!\n";
        }
        else {
            std::cout << "��������� ������� �� �������� ��������������-������ ��������!\n";
        }
    }
    else {
        std::cout << "�������� ������!\n";
    }
}

void cleanup(Human** people,int peopleCount) {
    for (int i = 0; i < peopleCount; i++) {
        delete people[i];
    }
    delete[] people;
}