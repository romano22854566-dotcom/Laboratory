#include "TeacherCommissionMember.h"
#include <iostream>

void TeacherCommissionMember::resizeCommissionWorks() {
    auto newCapacity = commissionWorksCapacity * 2;  // ���������� auto
    auto newWorks = new char* [newCapacity];  // ���������� auto
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
    std::cout << "������������� - ���� ��������:\n";
    std::cout << "���: " << getLastName() << " " << getFirstName() << " " << getPatronymic() << "\n";
    std::cout << "��� ��������: " << birthYear << "\n";
    std::cout << "���������: " << getPosition() << "\n";
    std::cout << "������ �������: " << getAcademicDegree() << "\n";
    std::cout << "�������������: " << getSpecialty() << "\n";
    std::cout << "�������� ��������: " << getCommissionName() << "\n";
    std::cout << "��� ����������: " << appointmentYear << "\n";
    std::cout << "����� �������������: " << getCertificateNumber() << "\n";

    std::cout << "������� ����� (" << worksCount << "):\n";
    for (int i = 0; i < worksCount; i++) {
        if (scientificWorks[i] != nullptr) {
            std::cout << "  " << (i + 1) << ". " << scientificWorks[i] << "\n";
        }
    }

    std::cout << "������������� (" << autobiographyLines << " �����):\n";
    for (int i = 0; i < autobiographyLines; i++) {
        if (autobiography[i] != nullptr) {
            std::cout << "  " << autobiography[i] << "\n";
        }
    }

    std::cout << "������ � �������� (" << commissionWorksCount << "):\n";
    for (int i = 0; i < commissionWorksCount; i++) {
        if (commissionWorks[i] != nullptr) {
            std::cout << "  " << (i + 1) << ". " << commissionWorks[i] << "\n";
        }
    }
}

void TeacherCommissionMember::input() {
    UniversityTeacher::input();

    char buffer[256];
    std::cout << "������� �������� ��������: ";
    if (std::cin.getline(buffer,256)) {
        setCommissionName(buffer);
    }

    std::cout << "������� ��� ����������: ";
    if (std::cin >> appointmentYear) {
        // valid input - ��������� ��� �������
    }
    std::cin.ignore();

    std::cout << "������� ����� �������������: ";
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