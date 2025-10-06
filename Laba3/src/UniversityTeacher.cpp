#define _CRT_SECURE_NO_WARNINGS
#include "UniversityTeacher.h"
#include <iostream>

UniversityTeacher::UniversityTeacher():
    position(nullptr),academicDegree(nullptr),specialty(nullptr),
    scientificWorks(nullptr),worksCount(0),worksCapacity(10) {
    scientificWorks = new char* [worksCapacity];
}

UniversityTeacher::UniversityTeacher(const char* fName,const char* lName,const char* pat,int year,
                                   const char* pos,const char* degree,const char* spec)
    : Human(fName,lName,pat,year),worksCount(0),worksCapacity(10) {

    position = new char[strlen(pos) + 1];
    strcpy(position,pos);

    academicDegree = new char[strlen(degree) + 1];
    strcpy(academicDegree,degree);

    specialty = new char[strlen(spec) + 1];
    strcpy(specialty,spec);

    scientificWorks = new char* [worksCapacity];
}

UniversityTeacher::~UniversityTeacher() {
    delete[] position;
    delete[] academicDegree;
    delete[] specialty;

    for (int i = 0; i < worksCount; i++) {
        delete[] scientificWorks[i];
    }
    delete[] scientificWorks;
}

void UniversityTeacher::display() const {
    std::cout << "Преподаватель университета:\n";
    std::cout << "ФИО: " << lastName << " " << firstName << " " << patronymic << "\n";
    std::cout << "Год рождения: " << birthYear << "\n";
    std::cout << "Должность: " << position << "\n";
    std::cout << "Ученая степень: " << academicDegree << "\n";
    std::cout << "Специальность: " << specialty << "\n";
    std::cout << "Научные труды (" << worksCount << "):\n";
    for (int i = 0; i < worksCount; i++) {
        std::cout << "  " << (i + 1) << ". " << scientificWorks[i] << "\n";
    }
}

void UniversityTeacher::input() {
    char buffer[100];

    std::cout << "Введите имя: ";
    std::cin >> buffer;
    setFirstName(buffer);

    std::cout << "Введите фамилию: ";
    std::cin >> buffer;
    setLastName(buffer);

    std::cout << "Введите отчество: ";
    std::cin >> buffer;
    setPatronymic(buffer);

    std::cout << "Введите год рождения: ";
    std::cin >> birthYear;

    std::cout << "Введите должность: ";
    std::cin.ignore();
    std::cin.getline(buffer,100);
    setPosition(buffer);

    std::cout << "Введите ученую степень: ";
    std::cin.getline(buffer,100);
    setAcademicDegree(buffer);

    std::cout << "Введите специальность: ";
    std::cin.getline(buffer,100);
    setSpecialty(buffer);
}

void UniversityTeacher::addScientificWork(const char* work) {
    if (worksCount >= worksCapacity) {
        worksCapacity *= 2;
        char** newWorks = new char* [worksCapacity];
        for (int i = 0; i < worksCount; i++) {
            newWorks[i] = scientificWorks[i];
        }
        delete[] scientificWorks;
        scientificWorks = newWorks;
    }

    scientificWorks[worksCount] = new char[strlen(work) + 1];
    strcpy(scientificWorks[worksCount],work);
    worksCount++;
}

void UniversityTeacher::removeScientificWork(int index) {
    if (index < 0 || index >= worksCount) return;

    delete[] scientificWorks[index];
    for (int i = index; i < worksCount - 1; i++) {
        scientificWorks[i] = scientificWorks[i + 1];
    }
    worksCount--;
}

void UniversityTeacher::updateScientificWork(int index,const char* newWork) {
    if (index < 0 || index >= worksCount) return;

    delete[] scientificWorks[index];
    scientificWorks[index] = new char[strlen(newWork) + 1];
    strcpy(scientificWorks[index],newWork);
}

const char* UniversityTeacher::getScientificWork(int index) const {
    if (index < 0 || index >= worksCount) return nullptr;
    return scientificWorks[index];
}

void UniversityTeacher::setPosition(const char* pos) {
    delete[] position;
    position = new char[strlen(pos) + 1];
    strcpy(position,pos);
}

void UniversityTeacher::setAcademicDegree(const char* degree) {
    delete[] academicDegree;
    academicDegree = new char[strlen(degree) + 1];
    strcpy(academicDegree,degree);
}

void UniversityTeacher::setSpecialty(const char* spec) {
    delete[] specialty;
    specialty = new char[strlen(spec) + 1];
    strcpy(specialty,spec);
}