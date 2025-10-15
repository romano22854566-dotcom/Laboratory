#include "CommissionMember.h"
#include <iostream>

void CommissionMember::resizeAutobiography() {
    int newCapacity = autobiographyCapacity * 2;
    char** newAutobiography = new char* [newCapacity];

    for (int i = 0; i < autobiographyLines; i++) {
        newAutobiography[i] = autobiography[i];
    }
    for (int i = autobiographyLines; i < newCapacity; i++) {
        newAutobiography[i] = nullptr;
    }

    delete[] autobiography;
    autobiography = newAutobiography;
    autobiographyCapacity = newCapacity;
}

CommissionMember::CommissionMember():
    commissionName(safeCopy("")),
    appointmentYear(0),
    certificateNumber(safeCopy("")) {
    autobiography = new char* [autobiographyCapacity];
    for (int i = 0; i < autobiographyCapacity; i++) {
        autobiography[i] = nullptr;
    }
}

CommissionMember::CommissionMember(const char* fName,const char* lName,const char* pat,int year,
                                 const char* commName,int appYear,const char* certNum)
    : Human(fName,lName,pat,year),appointmentYear(appYear) {
    commissionName = safeCopy(commName);
    certificateNumber = safeCopy(certNum);

    autobiography = new char* [autobiographyCapacity];
    for (int i = 0; i < autobiographyCapacity; i++) {
        autobiography[i] = nullptr;
    }
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
    std::cout << "Член комиссии:\n";
    std::cout << "ФИО: " << getLastName() << " " << getFirstName() << " " << getPatronymic() << "\n";
    std::cout << "Год рождения: " << getBirthYear() << "\n";
    std::cout << "Название комиссии: " << getCommissionName() << "\n";
    std::cout << "Год назначения: " << appointmentYear << "\n";
    std::cout << "Номер свидетельства: " << getCertificateNumber() << "\n";
    std::cout << "Автобиография (" << autobiographyLines << " строк):\n";
    for (int i = 0; i < autobiographyLines; i++) {
        if (autobiography[i] != nullptr) {
            std::cout << "  " << autobiography[i] << "\n";
        }
    }
}

void CommissionMember::input() {
    char buffer[256];

    std::cout << "Введите имя: ";
    std::cin >> buffer;
    setFirstName(buffer);

    std::cout << "Введите фамилию: ";
    std::cin >> buffer;
    setLastName(buffer);

    std::cout << "Введите отчество: ";
    std::cin >> buffer;
    setPatronymic(buffer);

    int year;
    std::cout << "Введите год рождения: ";
    std::cin >> year;
    setBirthYear(year);
    std::cin.ignore();

    std::cout << "Введите название комиссии: ";
    std::cin.getline(buffer,256);
    setCommissionName(buffer);

    std::cout << "Введите год назначения: ";
    std::cin >> appointmentYear;
    std::cin.ignore();

    std::cout << "Введите номер свидетельства: ";
    std::cin.getline(buffer,256);
    setCertificateNumber(buffer);
}

void CommissionMember::addAutobiographyLine(const char* line) {
    if (line == nullptr || std::strlen(line) == 0) return;

    if (autobiographyLines >= autobiographyCapacity) {
        resizeAutobiography();
    }

    autobiography[autobiographyLines] = safeCopy(line);
    autobiographyLines++;
}

const char* CommissionMember::getAutobiographyLine(int index) const {
    if (index < 0 || index >= autobiographyLines || autobiography[index] == nullptr) {
        return "";
    }
    return autobiography[index];
}

void CommissionMember::updateAutobiographyLine(int index,const char* newLine) {
    if (index < 0 || index >= autobiographyLines || newLine == nullptr || std::strlen(newLine) == 0) return;

    delete[] autobiography[index];
    autobiography[index] = safeCopy(newLine);
}

void CommissionMember::setCommissionName(const char* commName) {
    delete[] commissionName;
    commissionName = safeCopy(commName);
}

void CommissionMember::setAppointmentYear(int year) {
    appointmentYear = year;
}

void CommissionMember::setCertificateNumber(const char* certNum) {
    delete[] certificateNumber;
    certificateNumber = safeCopy(certNum);
}