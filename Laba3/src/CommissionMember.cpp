#include "CommissionMember.h"
#include <iostream>

CommissionMember::CommissionMember():
    commissionName(nullptr),appointmentYear(0),certificateNumber(nullptr),
    autobiography(nullptr),autobiographyLines(0),autobiographyCapacity(10) {
    autobiography = new char* [autobiographyCapacity];
}

CommissionMember::CommissionMember(const char* fName,const char* lName,const char* pat,int year,
                                 const char* commName,int appYear,const char* certNum)
    : Human(fName,lName,pat,year),appointmentYear(appYear),
    autobiographyLines(0),autobiographyCapacity(10) {

    size_t len = strlen(commName) + 1;
    commissionName = new char[len];
    strcpy_s(commissionName,len,commName);

    len = strlen(certNum) + 1;
    certificateNumber = new char[len];
    strcpy_s(certificateNumber,len,certNum);

    autobiography = new char* [autobiographyCapacity];
}

CommissionMember::~CommissionMember() {
    delete[] commissionName;
    delete[] certificateNumber;

    for (int i = 0; i < autobiographyLines; i++) {
        delete[] autobiography[i];
    }
    delete[] autobiography;
}

void CommissionMember::display() const {
    std::cout << "���� ��������:\n";
    std::cout << "���: " << lastName << " " << firstName << " " << patronymic << "\n";
    std::cout << "��� ��������: " << birthYear << "\n";
    std::cout << "�������� ��������: " << commissionName << "\n";
    std::cout << "��� ����������: " << appointmentYear << "\n";
    std::cout << "����� �������������: " << certificateNumber << "\n";
    std::cout << "������������� (" << autobiographyLines << " �����):\n";
    for (int i = 0; i < autobiographyLines; i++) {
        std::cout << "  " << autobiography[i] << "\n";
    }
}

void CommissionMember::input() {
    char buffer[100];

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

    std::cout << "������� �������� ��������: ";
    std::cin.ignore();
    std::cin.getline(buffer,100);
    setCommissionName(buffer);

    std::cout << "������� ��� ����������: ";
    std::cin >> appointmentYear;

    std::cout << "������� ����� �������������: ";
    std::cin.ignore();
    std::cin.getline(buffer,100);
    setCertificateNumber(buffer);
}

void CommissionMember::addAutobiographyLine(const char* line) {
    if (autobiographyLines >= autobiographyCapacity) {
        autobiographyCapacity *= 2;
        char** newAutobiography = new char* [autobiographyCapacity];
        for (int i = 0; i < autobiographyLines; i++) {
            newAutobiography[i] = autobiography[i];
        }
        delete[] autobiography;
        autobiography = newAutobiography;
    }

    size_t len = strlen(line) + 1;
    autobiography[autobiographyLines] = new char[len];
    strcpy_s(autobiography[autobiographyLines],len,line);
    autobiographyLines++;
}

void CommissionMember::removeAutobiographyLine(int index) {
    if (index < 0 || index >= autobiographyLines) return;

    delete[] autobiography[index];
    for (int i = index; i < autobiographyLines - 1; i++) {
        autobiography[i] = autobiography[i + 1];
    }
    autobiographyLines--;
}

void CommissionMember::updateAutobiographyLine(int index,const char* newLine) {
    if (index < 0 || index >= autobiographyLines) return;

    delete[] autobiography[index];
    size_t len = strlen(newLine) + 1;
    autobiography[index] = new char[len];
    strcpy_s(autobiography[index],len,newLine);
}

const char* CommissionMember::getAutobiographyLine(int index) const {
    if (index < 0 || index >= autobiographyLines) return nullptr;
    return autobiography[index];
}

void CommissionMember::setCommissionName(const char* commName) {
    delete[] commissionName;
    size_t len = strlen(commName) + 1;
    commissionName = new char[len];
    strcpy_s(commissionName,len,commName);
}

void CommissionMember::setAppointmentYear(int year) {
    appointmentYear = year;
}

void CommissionMember::setCertificateNumber(const char* certNum) {
    delete[] certificateNumber;
    size_t len = strlen(certNum) + 1;
    certificateNumber = new char[len];
    strcpy_s(certificateNumber,len,certNum);
}