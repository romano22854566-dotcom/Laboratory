#include "TeacherCommissionMember.h"
#include <iostream>

void TeacherCommissionMember::resizeCommissionWorks() {
    int newCapacity = commissionWorksCapacity * 2;
    char** newWorks = new char* [newCapacity];
    for (int i = 0; i < commissionWorksCount; i++) {
        newWorks[i] = commissionWorks[i];
    }
    for (int i = commissionWorksCount; i < newCapacity; i++) {
        newWorks[i] = nullptr;
    }
    delete[] commissionWorks;
    commissionWorks = newWorks;
    commissionWorksCapacity = newCapacity;
}

TeacherCommissionMember::TeacherCommissionMember():
    commissionWorks(nullptr),commissionWorksCount(0),commissionWorksCapacity(5) {
    commissionWorks = new char* [commissionWorksCapacity];
    for (int i = 0; i < commissionWorksCapacity; i++) {
        commissionWorks[i] = nullptr;
    }
}

TeacherCommissionMember::TeacherCommissionMember(const char* fName,const char* lName,const char* pat,int year,
                                               const char* pos,const char* degree,const char* spec,
                                               const char* commName,int appYear,const char* certNum)
    : Human(fName,lName,pat,year),
    UniversityTeacher(fName,lName,pat,year,pos,degree,spec),
    CommissionMember(fName,lName,pat,year,commName,appYear,certNum),
    commissionWorksCount(0),commissionWorksCapacity(5) {
    commissionWorks = new char* [commissionWorksCapacity];
    for (int i = 0; i < commissionWorksCapacity; i++) {
        commissionWorks[i] = nullptr;
    }
}

TeacherCommissionMember::~TeacherCommissionMember() {
    for (int i = 0; i < commissionWorksCount; i++) {
        delete[] commissionWorks[i];
    }
    delete[] commissionWorks;
}

void TeacherCommissionMember::display() const {
    std::cout << "Teacher - Commission Member:\n";
    std::cout << "Name: " << getLastName() << " " << getFirstName() << " " << getPatronymic() << "\n";
    std::cout << "Birth Year: " << birthYear << "\n";
    std::cout << "Position: " << getPosition() << "\n";
    std::cout << "Academic Degree: " << getAcademicDegree() << "\n";
    std::cout << "Specialty: " << getSpecialty() << "\n";
    std::cout << "Commission Name: " << getCommissionName() << "\n";
    std::cout << "Appointment Year: " << appointmentYear << "\n";
    std::cout << "Certificate Number: " << getCertificateNumber() << "\n";

    std::cout << "Scientific Works (" << worksCount << "):\n";
    for (int i = 0; i < worksCount; i++) {
        if (scientificWorks[i]) {
            std::cout << "  " << (i + 1) << ". " << scientificWorks[i] << "\n";
        }
    }

    std::cout << "Autobiography (" << autobiographyLines << " lines):\n";
    for (int i = 0; i < autobiographyLines; i++) {
        if (autobiography[i]) {
            std::cout << "  " << autobiography[i] << "\n";
        }
    }

    std::cout << "Commission Works (" << commissionWorksCount << "):\n";
    for (int i = 0; i < commissionWorksCount; i++) {
        if (commissionWorks[i]) {
            std::cout << "  " << (i + 1) << ". " << commissionWorks[i] << "\n";
        }
    }
}

void TeacherCommissionMember::input() {
    UniversityTeacher::input();

    char buffer[256];
    std::cout << "Enter commission name: ";
    if (std::cin.getline(buffer,256)) {
        setCommissionName(buffer);
    }

    std::cout << "Enter appointment year: ";
    if (std::cin >> appointmentYear) {
        // valid input
    }
    std::cin.ignore();

    std::cout << "Enter certificate number: ";
    if (std::cin.getline(buffer,256)) {
        setCertificateNumber(buffer);
    }
}

void TeacherCommissionMember::addCommissionWork(const char* work) {
    if (!work || std::strlen(work) == 0) return;  // Добавлено std::

    if (commissionWorksCount >= commissionWorksCapacity) {
        resizeCommissionWorks();
    }

    commissionWorks[commissionWorksCount] = safeCopy(work);
    commissionWorksCount++;
}

const char* TeacherCommissionMember::getCommissionWork(int index) const {
    if (index < 0 || index >= commissionWorksCount || !commissionWorks[index]) {
        return "";
    }
    return commissionWorks[index];
}

void TeacherCommissionMember::updateCommissionWork(int index,const char* newWork) {
    if (index < 0 || index >= commissionWorksCount || !newWork || std::strlen(newWork) == 0) return;  // Добавлено std::

    delete[] commissionWorks[index];
    commissionWorks[index] = safeCopy(newWork);
}