#define _CRT_SECURE_NO_WARNINGS
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

    commissionName = new char[strlen(commName) + 1];
    strcpy(commissionName,commName);

    certificateNumber = new char[strlen(certNum) + 1];
    strcpy(certificateNumber,certNum);

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

    autobiography[autobiographyLines] = new char[strlen(line) + 1];
    strcpy(autobiography[autobiographyLines],line);
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
    autobiography[index] = new char[strlen(newLine) + 1];
    strcpy(autobiography[index],newLine);
}

const char* CommissionMember::getAutobiographyLine(int index) const {
    if (index < 0 || index >= autobiographyLines) return nullptr;
    return autobiography[index];
}

void CommissionMember::setCommissionName(const char* commName) {
    delete[] commissionName;
    commissionName = new char[strlen(commName) + 1];
    strcpy(commissionName,commName);
}

void CommissionMember::setAppointmentYear(int year) {
    appointmentYear = year;
}

void CommissionMember::setCertificateNumber(const char* certNum) {
    delete[] certificateNumber;
    certificateNumber = new char[strlen(certNum) + 1];
    strcpy(certificateNumber,certNum);
}