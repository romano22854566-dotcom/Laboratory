#include "CommissionMember.h"
#include <iostream>

CommissionMember::CommissionMember():
    commissionName(nullptr),appointmentYear(0),certificateNumber(nullptr),
    autobiography(nullptr),autobiographyLines(0),autobiographyCapacity(5) {
    autobiography = new char* [autobiographyCapacity];
    for (int i = 0; i < autobiographyCapacity; i++) {
        autobiography[i] = nullptr;
    }
}

CommissionMember::CommissionMember(const char* fName,const char* lName,const char* pat,int year,
                                 const char* commName,int appYear,const char* certNum)
    : Human(fName,lName,pat,year),appointmentYear(appYear),
    autobiographyLines(0),autobiographyCapacity(5) {

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
    std::cout << "ФИО: " << lastName << " " << firstName << " " << patronymic << "\n";
    std::cout << "Год рождения: " << birthYear << "\n";
    std::cout << "Название комиссии: " << (commissionName ? commissionName : "") << "\n";
    std::cout << "Год назначения: " << appointmentYear << "\n";
    std::cout << "Номер свидетельства: " << (certificateNumber ? certificateNumber : "") << "\n";
    std::cout << "Автобиография (" << autobiographyLines << " строк):\n";
    for (int i = 0; i < autobiographyLines; i++) {
        std::cout << "  " << autobiography[i] << "\n";
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

    std::cout << "Введите год рождения: ";
    std::cin >> birthYear;
    std::cin.ignore();

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

void CommissionMember::addAutobiographyLine(const char* line) {
    if (!line) return;

    if (autobiographyLines >= autobiographyCapacity) {
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

    autobiography[autobiographyLines] = safeCopy(line);
    autobiographyLines++;
}
const char* CommissionMember::getAutobiographyLine(int index) const {
    if (index < 0 || index >= autobiographyLines) return nullptr;
    return autobiography[index];
}

void CommissionMember::updateAutobiographyLine(int index,const char* newLine) {
    if (index < 0 || index >= autobiographyLines || !newLine) return;
    delete[] autobiography[index];
    autobiography[index] = safeCopy(newLine);
}