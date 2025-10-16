#include "menu.hpp"
#include <iostream>

Person** people = nullptr;
int peopleCount = 0;

void showPeopleWithIndex() {
    std::cout << "\n=== ������ ����� ===\n";
    for (int i = 0; i < peopleCount; i++) {
        std::cout << i << ") ";
        people[i]->printInfo();
    }
}

void createTeacher() {
    char name[100],surname[100],patronymic[100];
    char position[100],degree[100],specialty[100];
    int year;

    std::cin.ignore();
    std::cout << "������� ���: ";
    std::cin.getline(name,100);
    std::cout << "������� �������: ";
    std::cin.getline(surname,100);
    std::cout << "������� ��������: ";
    std::cin.getline(patronymic,100);
    std::cout << "������� ��� ��������: ";
    std::cin >> year; std::cin.ignore();
    std::cout << "������� ���������: ";
    std::cin.getline(position,100);
    std::cout << "������� ������ �������: ";
    std::cin.getline(degree,100);
    std::cout << "������� �������������: ";
    std::cin.getline(specialty,100);

    Person** newArr = new Person * [peopleCount + 1];
    for (int i = 0; i < peopleCount; i++) newArr[i] = people[i];
    newArr[peopleCount] = new Teacher(name,surname,patronymic,year,
                                      position,degree,specialty);
    delete[] people;
    people = newArr;
    peopleCount++;
    std::cout << "������������� ������.\n";
}

void createCommissionMember() {
    char name[100],surname[100],patronymic[100];
    char commissionName[100];
    int year,yearAppointed,cert;

    std::cin.ignore();
    std::cout << "������� ���: ";
    std::cin.getline(name,100);
    std::cout << "������� �������: ";
    std::cin.getline(surname,100);
    std::cout << "������� ��������: ";
    std::cin.getline(patronymic,100);
    std::cout << "������� ��� ��������: ";
    std::cin >> year; std::cin.ignore();
    std::cout << "������� �������� ��������: ";
    std::cin.getline(commissionName,100);
    std::cout << "������� ��� ����������: ";
    std::cin >> yearAppointed;
    std::cout << "������� ����� �������������: ";
    std::cin >> cert; std::cin.ignore();

    Person** newArr = new Person * [peopleCount + 1];
    for (int i = 0; i < peopleCount; i++) newArr[i] = people[i];
    newArr[peopleCount] = new CommissionMember(name,surname,patronymic,year,
                                               commissionName,yearAppointed,cert);
    delete[] people;
    people = newArr;
    peopleCount++;
    std::cout << "���� �������� ������.\n";
}

void createTeacherCommissionMember() {
    char name[100],surname[100],patronymic[100];
    char position[100],degree[100],specialty[100];
    char commissionName[100];
    int year,yearAppointed,cert;

    std::cin.ignore();
    std::cout << "������� ���: ";
    std::cin.getline(name,100);
    std::cout << "������� �������: ";
    std::cin.getline(surname,100);
    std::cout << "������� ��������: ";
    std::cin.getline(patronymic,100);
    std::cout << "������� ��� ��������: ";
    std::cin >> year; std::cin.ignore();
    std::cout << "������� ���������: ";
    std::cin.getline(position,100);
    std::cout << "������� ������ �������: ";
    std::cin.getline(degree,100);
    std::cout << "������� �������������: ";
    std::cin.getline(specialty,100);
    std::cout << "������� �������� ��������: ";
    std::cin.getline(commissionName,100);
    std::cout << "������� ��� ����������: ";
    std::cin >> yearAppointed;
    std::cout << "������� ����� �������������: ";
    std::cin >> cert; std::cin.ignore();

    Person** newArr = new Person * [peopleCount + 1];
    for (int i = 0; i < peopleCount; i++) newArr[i] = people[i];
    newArr[peopleCount] = new TeacherCommissionMember(name,surname,patronymic,year,
                                                      position,degree,specialty,
                                                      commissionName,yearAppointed,cert);
    delete[] people;
    people = newArr;
    peopleCount++;
    std::cout << "�������������-���� �������� ������.\n";
}



void showAllPeople() {
    if (peopleCount == 0) {
        std::cout << "������ ����.\n";
        return;
    }
    std::cout << "\n=== ������ ����� ===\n";
    for (int i = 0; i < peopleCount; i++) {
        std::cout << i << ") ";
        people[i]->printInfo();
    }
}

void addWorkToTeachers() {
    if (peopleCount == 0) { std::cout << "��� �����.\n"; return; }
    showPeopleWithIndex();
    std::cout << "������� ����� �������������: ";
    int idx; std::cin >> idx; std::cin.ignore();
    if (idx < 0 || idx >= peopleCount) { std::cout << "�������� ������.\n"; return; }
    Teacher* t = dynamic_cast<Teacher*>(people[idx]);
    if (!t) { std::cout << "���� ������� �� �������� ��������������.\n"; return; }
    char work[200];
    std::cout << "������� �������� �������� �����: ";
    std::cin.getline(work,200);
    t->addWork(work,1.0);
    std::cout << "���� ��������.\n";
}

void addBioToCommissionMembers() {
    if (peopleCount == 0) { std::cout << "��� �����.\n"; return; }
    showPeopleWithIndex();
    std::cout << "������� ����� ����� ��������: ";
    int idx; std::cin >> idx; std::cin.ignore();
    if (idx < 0 || idx >= peopleCount) { std::cout << "�������� ������.\n"; return; }
    CommissionMember* c = dynamic_cast<CommissionMember*>(people[idx]);
    if (!c) { std::cout << "���� ������� �� �������� ������ ��������.\n"; return; }
    char bio[200];
    std::cout << "������� ������ �������������: ";
    std::cin.getline(bio,200);
    c->addBio(bio,0.0);
    std::cout << "������ ���������.\n";
}

void addCommissionWorkToTCM() {
    if (peopleCount == 0) { std::cout << "��� �����.\n"; return; }
    showPeopleWithIndex();
    std::cout << "������� ����� �������������-����� ��������: ";
    int idx; std::cin >> idx; std::cin.ignore();
    if (idx < 0 || idx >= peopleCount) { std::cout << "�������� ������.\n"; return; }
    TeacherCommissionMember* tcm = dynamic_cast<TeacherCommissionMember*>(people[idx]);
    if (!tcm) { std::cout << "���� ������� �� �������� ��������������-������ ��������.\n"; return; }
    char work[200];
    std::cout << "������� ������ � ��������: ";
    std::cin.getline(work,200);
    tcm->addCommissionWork(work,2.0);
    std::cout << "������ ���������.\n";
}
