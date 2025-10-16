#include "teacherCommissionMember.hpp"
#include <iostream>

TeacherCommissionMember::TeacherCommissionMember(const String& name,const String& surname,const String& patronymic,int yearOfBirth,
                                                 const String& position,const String& degree,const String& specialty,
                                                 const String& commissionName,int yearAppointed,int certificateNumber)
    : Person(name,surname,patronymic,yearOfBirth),
    Teacher(name,surname,patronymic,yearOfBirth,position,degree,specialty),
    CommissionMember(name,surname,patronymic,yearOfBirth,commissionName,yearAppointed,certificateNumber) {
}

void TeacherCommissionMember::addCommissionWork(const String& work) {
    commissionWorks.pushBack(work);
}

void TeacherCommissionMember::printInfo() const {
    Teacher::printInfo();
    CommissionMember::printInfo();
    if (!commissionWorks.empty()) {
        std::cout << "Работы в комиссии:\n";
        commissionWorks.print();
    }
}
