#include "TeacherCommissionMember.h"
#include <iostream>

void TeacherCommissionMember::resizeCommissionWorks() {
    auto newCapacity = commissionWorksCapacity * 2;  // Используем auto
    auto newWorks = new char* [newCapacity];  // Используем auto
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

TeacherCommissionMember::TeacherCommissionMember() {
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
    CommissionMember(fName,lName,pat,year,commName,appYear,certNum) {
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
    std::cout << "Преподаватель - член комиссии:\n";
    std::cout << "ФИО: " << getLastName() << " " << getFirstName() << " " << getPatronymic() << "\n";
    std::cout << "Год рождения: " << birthYear << "\n";
    std::cout << "Должность: " << getPosition() << "\n";
    std::cout << "Ученая степень: " << getAcademicDegree() << "\n";
    std::cout << "Специальность: " << getSpecialty() << "\n";
    std::cout << "Название комиссии: " << getCommissionName() << "\n";
    std::cout << "Год назначения: " << appointmentYear << "\n";
    std::cout << "Номер свидетельства: " << getCertificateNumber() << "\n";

    std::cout << "Научные труды (" << worksCount << "):\n";
    for (int i = 0; i < worksCount; i++) {
        if (scientificWorks[i] != nullptr) {
            std::cout << "  " << (i + 1) << ". " << scientificWorks[i] << "\n";
        }
    }

    std::cout << "Автобиография (" << autobiographyLines << " строк):\n";
    for (int i = 0; i < autobiographyLines; i++) {
        if (autobiography[i] != nullptr) {
            std::cout << "  " << autobiography[i] << "\n";
        }
    }

    std::cout << "Работы в комиссии (" << commissionWorksCount << "):\n";
    for (int i = 0; i < commissionWorksCount; i++) {
        if (commissionWorks[i] != nullptr) {
            std::cout << "  " << (i + 1) << ". " << commissionWorks[i] << "\n";
        }
    }
}

void TeacherCommissionMember::input() {
    UniversityTeacher::input();

    char buffer[256];
    std::cout << "Введите название комиссии: ";
    if (std::cin.getline(buffer,256)) {
        setCommissionName(buffer);
    }

    std::cout << "Введите год назначения: ";
    if (std::cin >> appointmentYear) {
        // valid input - оставлено для ясности
    }
    std::cin.ignore();

    std::cout << "Введите номер свидетельства: ";
    if (std::cin.getline(buffer,256)) {
        setCertificateNumber(buffer);
    }
}

void TeacherCommissionMember::addCommissionWork(const char* work) {
    if (work == nullptr || std::strlen(work) == 0) return;

    if (commissionWorksCount >= commissionWorksCapacity) {
        resizeCommissionWorks();
    }

    commissionWorks[commissionWorksCount] = safeCopy(work);
    commissionWorksCount++;
}

const char* TeacherCommissionMember::getCommissionWork(int index) const {
    if (index < 0 || index >= commissionWorksCount || commissionWorks[index] == nullptr) {
        return "";
    }
    return commissionWorks[index];
}

void TeacherCommissionMember::updateCommissionWork(int index,const char* newWork) {
    if (index < 0 || index >= commissionWorksCount || newWork == nullptr || std::strlen(newWork) == 0) return;

    delete[] commissionWorks[index];
    commissionWorks[index] = safeCopy(newWork);
}