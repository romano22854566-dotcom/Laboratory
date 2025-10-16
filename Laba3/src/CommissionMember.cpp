#include "commissionMember.hpp"
#include <iostream>

CommissionMember::CommissionMember(): yearAppointed(0),certificateNumber(0) {}

CommissionMember::CommissionMember(const String& name,const String& surname,const String& patronymic,int yearOfBirth,
                                   const String& commissionName,int yearAppointed,int certificateNumber)
    : Person(name,surname,patronymic,yearOfBirth),
    commissionName(commissionName),
    yearAppointed(yearAppointed),
    certificateNumber(certificateNumber) {
}

void CommissionMember::addBio(const String& line) {
    biography.pushBack(line);
}

void CommissionMember::printInfo() const {
    printBase();
    std::cout << "Комиссия: " << commissionName.cStr()
        << ", Год назначения: " << yearAppointed
        << ", Свидетельство: " << certificateNumber << std::endl;
    if (!biography.empty()) {
        std::cout << "Автобиография:\n";
        biography.print();
    }
}
