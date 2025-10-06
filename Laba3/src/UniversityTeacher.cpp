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

    size_t len = strlen(pos) + 1;
    position = new char[len];
    strcpy_s(position,len,pos);

    len = strlen(degree) + 1;
    academicDegree = new char[len];
    strcpy_s(academicDegree,len,degree);

    len = strlen(spec) + 1;
    specialty = new char[len];
    strcpy_s(specialty,len,spec);

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

    size_t len = strlen(work) + 1;
    scientificWorks[worksCount] = new char[len];
    strcpy_s(scientificWorks[worksCount],len,work);
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
    size_t len = strlen(newWork) + 1;
    scientificWorks[index] = new char[len];
    strcpy_s(scientificWorks[index],len,newWork);
}

const char* UniversityTeacher::getScientificWork(int index) const {
    if (index < 0 || index >= worksCount) return nullptr;
    return scientificWorks[index];
}

void UniversityTeacher::setPosition(const char* pos) {
    delete[] position;
    size_t len = strlen(pos) + 1;
    position = new char[len];
    strcpy_s(position,len,pos);
}

void UniversityTeacher::setAcademicDegree(const char* degree) {
    delete[] academicDegree;
    size_t len = strlen(degree) + 1;
    academicDegree = new char[len];
    strcpy_s(academicDegree,len,degree);
}

void UniversityTeacher::setSpecialty(const char* spec) {
    delete[] specialty;
    size_t len = strlen(spec) + 1;
    specialty = new char[len];
    strcpy_s(specialty,len,spec);
}