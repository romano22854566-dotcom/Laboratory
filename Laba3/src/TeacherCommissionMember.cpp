#include "TeacherCommissionMember.h"
#include <iostream>

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
    std::cout << "Преподаватель - член комиссии:\n";
    std::cout << "ФИО: " << lastName << " " << firstName << " " << patronymic << "\n";
    std::cout << "Год рождения: " << birthYear << "\n";
    std::cout << "Должность: " << (position ? position : "") << "\n";
    std::cout << "Ученая степень: " << (academicDegree ? academicDegree : "") << "\n";
    std::cout << "Специальность: " << (specialty ? specialty : "") << "\n";
    std::cout << "Название комиссии: " << (commissionName ? commissionName : "") << "\n";
    std::cout << "Год назначения: " << appointmentYear << "\n";
    std::cout << "Номер свидетельства: " << (certificateNumber ? certificateNumber : "") << "\n";

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

    char buffer[256];
    std::cout << "Введите название комиссии: ";
    std::cin.getline(buffer,256);
    delete[] commissionName;
    commissionName = safeCopy(buffer);

    std::cout << "Введите год назначения: ";
    std::cin >> appointmentYear;
    std::cin.ignore();

    std::cout << "Введите номер свидетельства: ";
    std::cin.getline(buffer,256);
    delete[] certificateNumber;
    certificateNumber = safeCopy(buffer);
}

void TeacherCommissionMember::addCommissionWork(const char* work) {
    if (!work) return;

    if (commissionWorksCount >= commissionWorksCapacity) {
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

    commissionWorks[commissionWorksCount] = safeCopy(work);
    commissionWorksCount++;
}
const char* TeacherCommissionMember::getCommissionWork(int index) const {
    if (index < 0 || index >= commissionWorksCount) return nullptr;
    return commissionWorks[index];
}

void TeacherCommissionMember::updateCommissionWork(int index,const char* newWork) {
    if (index < 0 || index >= commissionWorksCount || !newWork) return;
    delete[] commissionWorks[index];
    commissionWorks[index] = safeCopy(newWork);
}