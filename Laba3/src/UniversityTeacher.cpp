#include "UniversityTeacher.h"
#include <iostream>

UniversityTeacher::UniversityTeacher():
    position(nullptr),academicDegree(nullptr),specialty(nullptr),
    scientificWorks(nullptr),worksCount(0),worksCapacity(5) {
    scientificWorks = new char* [worksCapacity];
    for (int i = 0; i < worksCapacity; i++) {
        scientificWorks[i] = nullptr;
    }
}

UniversityTeacher::UniversityTeacher(const char* fName,const char* lName,const char* pat,int year,
                                   const char* pos,const char* degree,const char* spec)
    : Human(fName,lName,pat,year),worksCount(0),worksCapacity(5) {

    position = safeCopy(pos);
    academicDegree = safeCopy(degree);
    specialty = safeCopy(spec);

    scientificWorks = new char* [worksCapacity];
    for (int i = 0; i < worksCapacity; i++) {
        scientificWorks[i] = nullptr;
    }
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
    std::cout << "������������� ������������:\n";
    std::cout << "���: " << lastName << " " << firstName << " " << patronymic << "\n";
    std::cout << "��� ��������: " << birthYear << "\n";
    std::cout << "���������: " << (position ? position : "") << "\n";
    std::cout << "������ �������: " << (academicDegree ? academicDegree : "") << "\n";
    std::cout << "�������������: " << (specialty ? specialty : "") << "\n";
    std::cout << "������� ����� (" << worksCount << "):\n";
    for (int i = 0; i < worksCount; i++) {
        std::cout << "  " << (i + 1) << ". " << scientificWorks[i] << "\n";
    }
}

void UniversityTeacher::input() {
    char buffer[256];

    std::cout << "������� ���: ";
    std::cin >> buffer;
    setFirstName(buffer);

    std::cout << "������� �������: ";
    std::cin >> buffer;
    setLastName(buffer);

    std::cout << "������� ��������: ";
    std::cin >> buffer;
    setPatronymic(buffer);

    std::cout << "������� ��� ��������: ";
    std::cin >> birthYear;
    std::cin.ignore();

    std::cout << "������� ���������: ";
    std::cin.getline(buffer,256);
    delete[] position;
    position = safeCopy(buffer);

    std::cout << "������� ������ �������: ";
    std::cin.getline(buffer,256);
    delete[] academicDegree;
    academicDegree = safeCopy(buffer);

    std::cout << "������� �������������: ";
    std::cin.getline(buffer,256);
    delete[] specialty;
    specialty = safeCopy(buffer);
}

void UniversityTeacher::addScientificWork(const char* work) {
    if (!work) return;

    if (worksCount >= worksCapacity) {
        int newCapacity = worksCapacity * 2;
        char** newWorks = new char* [newCapacity];
        for (int i = 0; i < worksCount; i++) {
            newWorks[i] = scientificWorks[i];
        }
        for (int i = worksCount; i < newCapacity; i++) {
            newWorks[i] = nullptr;
        }
        delete[] scientificWorks;
        scientificWorks = newWorks;
        worksCapacity = newCapacity;
    }

    scientificWorks[worksCount] = safeCopy(work);
    worksCount++;
}
const char* UniversityTeacher::getScientificWork(int index) const {
    if (index < 0 || index >= worksCount) return nullptr;
    return scientificWorks[index];
}

void UniversityTeacher::updateScientificWork(int index,const char* newWork) {
    if (index < 0 || index >= worksCount || !newWork) return;
    delete[] scientificWorks[index];
    scientificWorks[index] = safeCopy(newWork);
}