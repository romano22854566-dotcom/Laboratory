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
    commissionWorksCount(0),
    commissionWorksCapacity(5) {
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
    commissionWorksCount(0),
    commissionWorksCapacity(5) {

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
    std::cout << "��� ��������: " << getBirthYear() << "\n";
    std::cout << "���������: " << UniversityTeacher::getPosition() << "\n";
    std::cout << "������ �������: " << UniversityTeacher::getAcademicDegree() << "\n";
    std::cout << "�������������: " << UniversityTeacher::getSpecialty() << "\n";
    std::cout << "�������� ��������: " << CommissionMember::getCommissionName() << "\n";
    std::cout << "��� ����������: " << CommissionMember::getAppointmentYear() << "\n";
    std::cout << "����� �������������: " << CommissionMember::getCertificateNumber() << "\n";

    std::cout << "������� ����� (" << UniversityTeacher::getScientificWorksCount() << "):\n";
    for (int i = 0; i < UniversityTeacher::getScientificWorksCount(); i++) {
        const char* work = UniversityTeacher::getScientificWork(i);
        if (work != nullptr && std::strlen(work) > 0) {
            std::cout << "  " << (i + 1) << ". " << work << "\n";
        }
    }

    std::cout << "������������� (" << CommissionMember::getAutobiographyLinesCount() << " �����):\n";
    for (int i = 0; i < CommissionMember::getAutobiographyLinesCount(); i++) {
        const char* line = CommissionMember::getAutobiographyLine(i);
        if (line != nullptr && std::strlen(line) > 0) {
            std::cout << "  " << line << "\n";
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

    int year;
    std::cout << "������� ��� ��������: ";
    std::cin >> year;
    setBirthYear(year);
    std::cin.ignore();

    std::cout << "������� ���������: ";
    std::cin.getline(buffer,256);
    UniversityTeacher::setPosition(buffer);

    std::cout << "������� ������ �������: ";
    std::cin.getline(buffer,256);
    UniversityTeacher::setAcademicDegree(buffer);

    std::cout << "������� �������������: ";
    std::cin.getline(buffer,256);
    UniversityTeacher::setSpecialty(buffer);

    std::cout << "������� �������� ��������: ";
    std::cin.getline(buffer,256);
    CommissionMember::setCommissionName(buffer);

    int appYear;
    std::cout << "������� ��� ����������: ";
    std::cin >> appYear;
    CommissionMember::setAppointmentYear(appYear);
    std::cin.ignore();

    std::cout << "������� ����� �������������: ";
    std::cin.getline(buffer,256);
    CommissionMember::setCertificateNumber(buffer);
}

void TeacherCommissionMember::addCommissionWork(const char* work) {
    if (work == nullptr || std::strlen(work) == 0) return;

    if (commissionWorksCount >= commissionWorksCapacity) {
        resizeCommissionWorks();
    }

    commissionWorks[commissionWorksCount] = UniversityTeacher::safeCopy(work);
    commissionWorksCount++;
}

const char* TeacherCommissionMember::getCommissionWork(int index) const {
    if (index < 0 || index >= commissionWorksCount || commissionWorks[index] == nullptr) {
        return "";
    }
    return commissionWorks[index];
}

int TeacherCommissionMember::getCommissionWorksCount() const {
    return commissionWorksCount;
}

void TeacherCommissionMember::updateCommissionWork(int index,const char* newWork) {
    if (index < 0 || index >= commissionWorksCount || newWork == nullptr || std::strlen(newWork) == 0) return;

    delete[] commissionWorks[index];
    commissionWorks[index] = UniversityTeacher::safeCopy(newWork);
}

const char* TeacherCommissionMember::getFirstName() const {
    return UniversityTeacher::getFirstName();
}

const char* TeacherCommissionMember::getLastName() const {
    return UniversityTeacher::getLastName();
}

const char* TeacherCommissionMember::getPatronymic() const {
    return UniversityTeacher::getPatronymic();
}

int TeacherCommissionMember::getBirthYear() const {
    return UniversityTeacher::getBirthYear();
}

void TeacherCommissionMember::setFirstName(const char* fName) {
    UniversityTeacher::setFirstName(fName);
    CommissionMember::setFirstName(fName);
}

void TeacherCommissionMember::setLastName(const char* lName) {
    UniversityTeacher::setLastName(lName);
    CommissionMember::setLastName(lName);
}

void TeacherCommissionMember::setPatronymic(const char* pat) {
    UniversityTeacher::setPatronymic(pat);
    CommissionMember::setPatronymic(pat);
}

void TeacherCommissionMember::setBirthYear(int year) {
    UniversityTeacher::setBirthYear(year);
    CommissionMember::setBirthYear(year);
}