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
    commissionName(safeCopy("")),appointmentYear(0),certificateNumber(safeCopy("")),
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
    std::cout << "Commission Member:\n";
    std::cout << "Name: " << getLastName() << " " << getFirstName() << " " << getPatronymic() << "\n";
    std::cout << "Birth Year: " << birthYear << "\n";
    std::cout << "Commission Name: " << getCommissionName() << "\n";
    std::cout << "Appointment Year: " << appointmentYear << "\n";
    std::cout << "Certificate Number: " << getCertificateNumber() << "\n";
    std::cout << "Autobiography (" << autobiographyLines << " lines):\n";
    for (int i = 0; i < autobiographyLines; i++) {
        if (autobiography[i]) {
            std::cout << "  " << autobiography[i] << "\n";
        }
    }
}

void CommissionMember::input() {
    char buffer[256];

    std::cout << "Enter first name: ";
    if (std::cin >> buffer) {
        setFirstName(buffer);
    }

    std::cout << "Enter last name: ";
    if (std::cin >> buffer) {
        setLastName(buffer);
    }

    std::cout << "Enter patronymic: ";
    if (std::cin >> buffer) {
        setPatronymic(buffer);
    }

    std::cout << "Enter birth year: ";
    if (std::cin >> birthYear) {
        // valid input
    }
    std::cin.ignore();

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

void CommissionMember::addAutobiographyLine(const char* line) {
    if (!line || strlen(line) == 0) return;

    if (autobiographyLines >= autobiographyCapacity) {
        resizeAutobiography();
    }

    autobiography[autobiographyLines] = safeCopy(line);
    autobiographyLines++;
}

const char* CommissionMember::getAutobiographyLine(int index) const {
    if (index < 0 || index >= autobiographyLines || !autobiography[index]) {
        return "";
    }
    return autobiography[index];
}

void CommissionMember::updateAutobiographyLine(int index,const char* newLine) {
    if (index < 0 || index >= autobiographyLines || !newLine || strlen(newLine) == 0) return;

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