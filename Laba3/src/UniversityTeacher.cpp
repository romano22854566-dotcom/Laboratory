#include "UniversityTeacher.h"
#include <iostream>

void UniversityTeacher::resizeWorks() {
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

UniversityTeacher::UniversityTeacher():
    position(safeCopy("")),academicDegree(safeCopy("")),specialty(safeCopy("")),
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
    std::cout << "University Teacher:\n";
    std::cout << "Name: " << getLastName() << " " << getFirstName() << " " << getPatronymic() << "\n";
    std::cout << "Birth Year: " << birthYear << "\n";
    std::cout << "Position: " << getPosition() << "\n";
    std::cout << "Academic Degree: " << getAcademicDegree() << "\n";
    std::cout << "Specialty: " << getSpecialty() << "\n";
    std::cout << "Scientific Works (" << worksCount << "):\n";
    for (int i = 0; i < worksCount; i++) {
        if (scientificWorks[i]) {
            std::cout << "  " << (i + 1) << ". " << scientificWorks[i] << "\n";
        }
    }
}

void UniversityTeacher::input() {
    char buffer[256];

    std::cout << "Enter first name: ";
    if (std::cin >> buffer) {
        setFirstName(buffer);
    }

    std::cout << "Enter last name: ";
    if (std::cin >> buffer) {
        setLastName(buffer);
    }

    std::cout << "Enter patronymic: ";
    if (std::cin >> buffer) {
        setPatronymic(buffer);
    }

    std::cout << "Enter birth year: ";
    if (std::cin >> birthYear) {
        // valid input
    }
    std::cin.ignore();

    std::cout << "Enter position: ";
    if (std::cin.getline(buffer,256)) {
        setPosition(buffer);
    }

    std::cout << "Enter academic degree: ";
    if (std::cin.getline(buffer,256)) {
        setAcademicDegree(buffer);
    }

    std::cout << "Enter specialty: ";
    if (std::cin.getline(buffer,256)) {
        setSpecialty(buffer);
    }
}

void UniversityTeacher::addScientificWork(const char* work) {
    if (!work || std::strlen(work) == 0) return;  // Добавлено std::

    if (worksCount >= worksCapacity) {
        resizeWorks();
    }

    scientificWorks[worksCount] = safeCopy(work);
    worksCount++;
}

const char* UniversityTeacher::getScientificWork(int index) const {
    if (index < 0 || index >= worksCount || !scientificWorks[index]) {
        return "";
    }
    return scientificWorks[index];
}

void UniversityTeacher::updateScientificWork(int index,const char* newWork) {
    if (index < 0 || index >= worksCount || !newWork || std::strlen(newWork) == 0) return;  // Добавлено std::

    delete[] scientificWorks[index];
    scientificWorks[index] = safeCopy(newWork);
}

void UniversityTeacher::setPosition(const char* pos) {
    delete[] position;
    position = safeCopy(pos);
}

void UniversityTeacher::setAcademicDegree(const char* degree) {
    delete[] academicDegree;
    academicDegree = safeCopy(degree);
}

void UniversityTeacher::setSpecialty(const char* spec) {
    delete[] specialty;
    specialty = safeCopy(spec);
}