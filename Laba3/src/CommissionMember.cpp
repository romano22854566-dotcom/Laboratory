#include "commissionMember.hpp"
#include <iostream>

CommissionMember::CommissionMember()
    : Person(),commissionName_(),yearAppointed_(0),certificateNumber_(0),biography_() {
}

CommissionMember::CommissionMember(const String& name,const String& surname,const String& patronymic,int year,
                                   const String& commissionName,int yearAppointed,int certificateNumber)
    : Person(name,surname,patronymic,year),
    commissionName_(commissionName),
    yearAppointed_(yearAppointed),
    certificateNumber_(certificateNumber),
    biography_() {
}

CommissionMember::~CommissionMember() {}

void CommissionMember::setCommissionName(const String& commissionName) { commissionName_ = commissionName; }
void CommissionMember::setYearAppointed(int year) { yearAppointed_ = year; }
void CommissionMember::setCertificateNumber(int number) { certificateNumber_ = number; }

const String& CommissionMember::getCommissionName() const { return commissionName_; }
int CommissionMember::getYearAppointed() const { return yearAppointed_; }
int CommissionMember::getCertificateNumber() const { return certificateNumber_; }

void CommissionMember::addBio(const String& line,double value) {
    biography_.pushBack(line,value);
}

void CommissionMember::printInfo() const {
    Person::printInfo();
    std::cout << "Комиссия: " << commissionName_.cStr()
        << ", Год назначения: " << yearAppointed_
        << ", Свидетельство: " << certificateNumber_ << std::endl;

    if (biography_.find("") == nullptr) {
        std::cout << "Автобиография:" << std::endl;
        biography_.print();
    }
}
