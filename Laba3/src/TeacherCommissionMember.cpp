#define _CRT_SECURE_NO_WARNINGS
#include "TeacherCommissionMember.h"
#include <iostream>

TeacherCommissionMember::TeacherCommissionMember():
    commissionWorks(nullptr),commissionWorksCount(0),commissionWorksCapacity(10) {
    commissionWorks = new char* [commissionWorksCapacity];
}

TeacherCommissionMember::TeacherCommissionMember(const char* fName,const char* lName,const char* pat,int year,
                                               const char* pos,const char* degree,const char* spec,
                                               const char* commName,int appYear,const char* certNum)
    : Human(fName,lName,pat,year),
    UniversityTeacher(fName,lName,pat,year,pos,degree,spec),
    CommissionMember(fName,lName,pat,year,commName,appYear,certNum),
    commissionWorksCount(0),commissionWorksCapacity(10) {
    commissionWorks = new char* [commissionWorksCapacity];
}

TeacherCommissionMember::~TeacherCommissionMember() {
    for (int i = 0; i < commissionWorksCount; i++) {
        delete[] commissionWorks[i];
    }
    delete[] commissionWorks;
}

void TeacherCommissionMember::display() const {
    std::cout << "Преподаватель - член комиссии:\n";
    std::cout << "ФИО: " << lastName << " " << firstName << " " << patronymic << "\n";
    std::cout << "Год рождения: " << birthYear << "\n";
    std::cout << "Должность: " << position << "\n";
    std::cout << "Ученая степень: " << academicDegree << "\n";
    std::cout << "Специальность: " << specialty << "\n";
    std::cout << "Название комиссии: " << commissionName << "\n";
    std::cout << "Год назначения: " << appointmentYear << "\n";
    std::cout << "Номер свидетельства: " << certificateNumber << "\n";

    std::cout << "Научные труды (" << worksCount << "):\n";
    for (int i = 0; i < worksCount; i++) {
        std::cout << "  " << (i + 1) << ". " << scientificWorks[i] << "\n";
    }

    std::cout << "Автобиография (" << autobiographyLines << " строк):\n";
    for (int i = 0; i < autobiographyLines; i++) {
        std::cout << "  " << autobiography[i] << "\n";
    }

    std::cout << "Работы в комиссии (" << commissionWorksCount << "):\n";
    for (int i = 0; i < commissionWorksCount; i++) {
        std::cout << "  " << (i + 1) << ". " << commissionWorks[i] << "\n";
    }
}

void TeacherCommissionMember::input() {
    UniversityTeacher::input();

    char buffer[100];
    std::cout << "Введите название комиссии: ";
    std::cin.ignore();
    std::cin.getline(buffer,100);
    setCommissionName(buffer);

    std::cout << "Введите год назначения: ";
    std::cin >> appointmentYear;

    std::cout << "Введите номер свидетельства: ";
    std::cin.ignore();
    std::cin.getline(buffer,100);
    setCertificateNumber(buffer);
}

void TeacherCommissionMember::addCommissionWork(const char* work) {
    if (commissionWorksCount >= commissionWorksCapacity) {
        commissionWorksCapacity *= 2;
        char** newWorks = new char* [commissionWorksCapacity];
        for (int i = 0; i < commissionWorksCount; i++) {
            newWorks[i] = commissionWorks[i];
        }
        delete[] commissionWorks;
        commissionWorks = newWorks;
    }

    commissionWorks[commissionWorksCount] = new char[strlen(work) + 1];
    strcpy(commissionWorks[commissionWorksCount],work);
    commissionWorksCount++;
}

void TeacherCommissionMember::removeCommissionWork(int index) {
    if (index < 0 || index >= commissionWorksCount) return;

    delete[] commissionWorks[index];
    for (int i = index; i < commissionWorksCount - 1; i++) {
        commissionWorks[i] = commissionWorks[i + 1];
    }
    commissionWorksCount--;
}

void TeacherCommissionMember::updateCommissionWork(int index,const char* newWork) {
    if (index < 0 || index >= commissionWorksCount) return;

    delete[] commissionWorks[index];
    commissionWorks[index] = new char[strlen(newWork) + 1];
    strcpy(commissionWorks[index],newWork);
}

const char* TeacherCommissionMember::getCommissionWork(int index) const {
    if (index < 0 || index >= commissionWorksCount) return nullptr;
    return commissionWorks[index];
}