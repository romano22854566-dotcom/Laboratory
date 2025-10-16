#include "menu.hpp"
#include <iostream>

Person** people = nullptr;
int peopleCount = 0;

void showPeopleWithIndex() {
    std::cout << "\n=== Список людей ===\n";
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
    std::cout << "Введите имя: ";
    std::cin.getline(name,100);
    std::cout << "Введите фамилию: ";
    std::cin.getline(surname,100);
    std::cout << "Введите отчество: ";
    std::cin.getline(patronymic,100);
    std::cout << "Введите год рождения: ";
    std::cin >> year; std::cin.ignore();
    std::cout << "Введите должность: ";
    std::cin.getline(position,100);
    std::cout << "Введите ученую степень: ";
    std::cin.getline(degree,100);
    std::cout << "Введите специальность: ";
    std::cin.getline(specialty,100);

    Person** newArr = new Person * [peopleCount + 1];
    for (int i = 0; i < peopleCount; i++) newArr[i] = people[i];
    newArr[peopleCount] = new Teacher(name,surname,patronymic,year,
                                      position,degree,specialty);
    delete[] people;
    people = newArr;
    peopleCount++;
    std::cout << "Преподаватель создан.\n";
}

void createCommissionMember() {
    char name[100],surname[100],patronymic[100];
    char commissionName[100];
    int year,yearAppointed,cert;

    std::cin.ignore();
    std::cout << "Введите имя: ";
    std::cin.getline(name,100);
    std::cout << "Введите фамилию: ";
    std::cin.getline(surname,100);
    std::cout << "Введите отчество: ";
    std::cin.getline(patronymic,100);
    std::cout << "Введите год рождения: ";
    std::cin >> year; std::cin.ignore();
    std::cout << "Введите название комиссии: ";
    std::cin.getline(commissionName,100);
    std::cout << "Введите год назначения: ";
    std::cin >> yearAppointed;
    std::cout << "Введите номер свидетельства: ";
    std::cin >> cert; std::cin.ignore();

    Person** newArr = new Person * [peopleCount + 1];
    for (int i = 0; i < peopleCount; i++) newArr[i] = people[i];
    newArr[peopleCount] = new CommissionMember(name,surname,patronymic,year,
                                               commissionName,yearAppointed,cert);
    delete[] people;
    people = newArr;
    peopleCount++;
    std::cout << "Член комиссии создан.\n";
}

void createTeacherCommissionMember() {
    char name[100],surname[100],patronymic[100];
    char position[100],degree[100],specialty[100];
    char commissionName[100];
    int year,yearAppointed,cert;

    std::cin.ignore();
    std::cout << "Введите имя: ";
    std::cin.getline(name,100);
    std::cout << "Введите фамилию: ";
    std::cin.getline(surname,100);
    std::cout << "Введите отчество: ";
    std::cin.getline(patronymic,100);
    std::cout << "Введите год рождения: ";
    std::cin >> year; std::cin.ignore();
    std::cout << "Введите должность: ";
    std::cin.getline(position,100);
    std::cout << "Введите ученую степень: ";
    std::cin.getline(degree,100);
    std::cout << "Введите специальность: ";
    std::cin.getline(specialty,100);
    std::cout << "Введите название комиссии: ";
    std::cin.getline(commissionName,100);
    std::cout << "Введите год назначения: ";
    std::cin >> yearAppointed;
    std::cout << "Введите номер свидетельства: ";
    std::cin >> cert; std::cin.ignore();

    Person** newArr = new Person * [peopleCount + 1];
    for (int i = 0; i < peopleCount; i++) newArr[i] = people[i];
    newArr[peopleCount] = new TeacherCommissionMember(name,surname,patronymic,year,
                                                      position,degree,specialty,
                                                      commissionName,yearAppointed,cert);
    delete[] people;
    people = newArr;
    peopleCount++;
    std::cout << "Преподаватель-член комиссии создан.\n";
}



void showAllPeople() {
    if (peopleCount == 0) {
        std::cout << "Список пуст.\n";
        return;
    }
    std::cout << "\n=== Список людей ===\n";
    for (int i = 0; i < peopleCount; i++) {
        std::cout << i << ") ";
        people[i]->printInfo();
    }
}

void addWorkToTeachers() {
    if (peopleCount == 0) { std::cout << "Нет людей.\n"; return; }
    showPeopleWithIndex();
    std::cout << "Введите номер преподавателя: ";
    int idx; std::cin >> idx; std::cin.ignore();
    if (idx < 0 || idx >= peopleCount) { std::cout << "Неверный индекс.\n"; return; }
    Teacher* t = dynamic_cast<Teacher*>(people[idx]);
    if (!t) { std::cout << "Этот человек не является преподавателем.\n"; return; }
    char work[200];
    std::cout << "Введите название научного труда: ";
    std::cin.getline(work,200);
    t->addWork(work,1.0);
    std::cout << "Труд добавлен.\n";
}

void addBioToCommissionMembers() {
    if (peopleCount == 0) { std::cout << "Нет людей.\n"; return; }
    showPeopleWithIndex();
    std::cout << "Введите номер члена комиссии: ";
    int idx; std::cin >> idx; std::cin.ignore();
    if (idx < 0 || idx >= peopleCount) { std::cout << "Неверный индекс.\n"; return; }
    CommissionMember* c = dynamic_cast<CommissionMember*>(people[idx]);
    if (!c) { std::cout << "Этот человек не является членом комиссии.\n"; return; }
    char bio[200];
    std::cout << "Введите строку автобиографии: ";
    std::cin.getline(bio,200);
    c->addBio(bio,0.0);
    std::cout << "Строка добавлена.\n";
}

void addCommissionWorkToTCM() {
    if (peopleCount == 0) { std::cout << "Нет людей.\n"; return; }
    showPeopleWithIndex();
    std::cout << "Введите номер преподавателя-члена комиссии: ";
    int idx; std::cin >> idx; std::cin.ignore();
    if (idx < 0 || idx >= peopleCount) { std::cout << "Неверный индекс.\n"; return; }
    TeacherCommissionMember* tcm = dynamic_cast<TeacherCommissionMember*>(people[idx]);
    if (!tcm) { std::cout << "Этот человек не является преподавателем-членом комиссии.\n"; return; }
    char work[200];
    std::cout << "Введите работу в комиссии: ";
    std::cin.getline(work,200);
    tcm->addCommissionWork(work,2.0);
    std::cout << "Работа добавлена.\n";
}
