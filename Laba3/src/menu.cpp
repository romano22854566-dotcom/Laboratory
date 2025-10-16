#include "menu.hpp"
#include "teacher.hpp"
#include "commissionMember.hpp"
#include "teacherCommissionMember.hpp"
#include <iostream>
#include <string>

Menu::Menu(): people(nullptr),count(0) {}

Menu::~Menu() {
    for (int i = 0; i < count; i++) {
        delete people[i];
    }
    delete[] people;
}

void Menu::createTeacher() {
    std::string name;
    std::string surname;
    std::string patronymic;
    std::string position;
    std::string degree;
    std::string specialty;
    int yearOfBirth;

    std::cout << "¬ведите им€: "; std::getline(std::cin >> std::ws,name);
    std::cout << "¬ведите фамилию: "; std::getline(std::cin,surname);
    std::cout << "¬ведите отчество: "; std::getline(std::cin,patronymic);
    std::cout << "¬ведите год рождени€: "; std::cin >> yearOfBirth; std::cin.ignore();
    std::cout << "¬ведите должность: "; std::getline(std::cin,position);
    std::cout << "¬ведите ученую степень: "; std::getline(std::cin,degree);
    std::cout << "¬ведите специальность: "; std::getline(std::cin,specialty);

    Person** newArr = new Person * [count + 1];
    for (int i = 0; i < count; i++) newArr[i] = people[i];
    newArr[count] = new Teacher(
        String(name.c_str()),String(surname.c_str()),String(patronymic.c_str()),yearOfBirth,
        String(position.c_str()),String(degree.c_str()),String(specialty.c_str())
    );
    delete[] people;
    people = newArr;
    ++count;
}

void Menu::createCommissionMember() {
    std::string name;
    std::string surname;
    std::string patronymic;
    std::string commissionName;
    int yearOfBirth;
    int yearAppointed;
    int cert;

    std::cout << "¬ведите им€: "; std::getline(std::cin >> std::ws,name);
    std::cout << "¬ведите фамилию: "; std::getline(std::cin,surname);
    std::cout << "¬ведите отчество: "; std::getline(std::cin,patronymic);
    std::cout << "¬ведите год рождени€: "; std::cin >> yearOfBirth; std::cin.ignore();
    std::cout << "¬ведите название комиссии: "; std::getline(std::cin,commissionName);
    std::cout << "¬ведите год назначени€: "; std::cin >> yearAppointed;
    std::cout << "¬ведите номер свидетельства: "; std::cin >> cert; std::cin.ignore();

    Person** newArr = new Person * [count + 1];
    for (int i = 0; i < count; i++) newArr[i] = people[i];
    newArr[count] = new CommissionMember(
        String(name.c_str()),String(surname.c_str()),String(patronymic.c_str()),yearOfBirth,
        String(commissionName.c_str()),yearAppointed,cert
    );
    delete[] people;
    people = newArr;
    ++count;
}

void Menu::createTeacherCommissionMember() {
    std::string name;
    std::string surname;
    std::string patronymic;
    std::string position;
    std::string degree;
    std::string specialty;
    std::string commissionName;
    int yearOfBirth;
    int yearAppointed;
    int cert;

    std::cout << "¬ведите им€: "; std::getline(std::cin >> std::ws,name);
    std::cout << "¬ведите фамилию: "; std::getline(std::cin,surname);
    std::cout << "¬ведите отчество: "; std::getline(std::cin,patronymic);
    std::cout << "¬ведите год рождени€: "; std::cin >> yearOfBirth; std::cin.ignore();
    std::cout << "¬ведите должность: "; std::getline(std::cin,position);
    std::cout << "¬ведите ученую степень: "; std::getline(std::cin,degree);
    std::cout << "¬ведите специальность: "; std::getline(std::cin,specialty);
    std::cout << "¬ведите название комиссии: "; std::getline(std::cin,commissionName);
    std::cout << "¬ведите год назначени€: "; std::cin >> yearAppointed;
    std::cout << "¬ведите номер свидетельства: "; std::cin >> cert; std::cin.ignore();

    Person** newArr = new Person * [count + 1];
    for (int i = 0; i < count; i++) newArr[i] = people[i];
    newArr[count] = new TeacherCommissionMember(
        String(name.c_str()),String(surname.c_str()),String(patronymic.c_str()),yearOfBirth,
        String(position.c_str()),String(degree.c_str()),String(specialty.c_str()),
        String(commissionName.c_str()),yearAppointed,cert
    );
    delete[] people;
    people = newArr;
    ++count;
}

void Menu::showAllPeople() const {
    if (count == 0) {
        std::cout << "—писок пуст.\n";
        return;
    }
    std::cout << "\n=== —писок людей ===\n";
    for (int i = 0; i < count; i++) {
        std::cout << i << ") ";
        people[i]->printInfo();
    }
}

void Menu::addWorkToTeacher() {
    showAllPeople();
    std::cout << "¬ведите индекс преподавател€: ";
    int idx;
    std::cin >> idx;
    std::cin.ignore();
    if (idx < 0 || idx >= count) return;
    auto* t = dynamic_cast<Teacher*>(people[idx]);
    if (!t) { std::cout << "Ќе преподаватель.\n"; return; }
    std::string work;
    std::cout << "¬ведите название научного труда: ";
    std::getline(std::cin,work);
    t->addWork(String(work.c_str()));
}

void Menu::addBioToCommissionMember() {
    showAllPeople();
    std::cout << "¬ведите индекс члена комиссии: ";
    int idx;
    std::cin >> idx;
    std::cin.ignore();
    if (idx < 0 || idx >= count) return;
    auto* c = dynamic_cast<CommissionMember*>(people[idx]);
    if (!c) { std::cout << "Ќе член комиссии.\n"; return; }
    std::string bio;
    std::cout << "¬ведите строку автобиографии: ";
    std::getline(std::cin,bio);
    c->addBio(String(bio.c_str()));
}

void Menu::addCommissionWorkToTCM() {
    showAllPeople();
    std::cout << "¬ведите индекс преподавател€-члена комиссии: ";
    int idx;
    std::cin >> idx;
    std::cin.ignore();
    if (idx < 0 || idx >= count) return;
    auto* tcm = dynamic_cast<TeacherCommissionMember*>(people[idx]);
    if (!tcm) {
        std::cout << "Ќе преподаватель-член комиссии.\n";
        return;
    }
    std::string work;
    std::cout << "¬ведите работу в комиссии: ";
    std::getline(std::cin,work);
    tcm->addCommissionWork(String(work.c_str()));
}

