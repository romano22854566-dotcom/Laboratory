#include "teacherCommissionMember.hpp"
#include <iostream>

TeacherCommissionMember::TeacherCommissionMember()
    : Person(),Teacher(),CommissionMember(),commissionWorks_() {
}

TeacherCommissionMember::TeacherCommissionMember(const String& name,const String& surname,const String& patronymic,int year,
                                                 const String& position,const String& degree,const String& specialty,
                                                 const String& commissionName,int yearAppointed,int certificateNumber)
    : Person(name,surname,patronymic,year),
    Teacher(name,surname,patronymic,year,position,degree,specialty),
    CommissionMember(name,surname,patronymic,year,commissionName,yearAppointed,certificateNumber),
    commissionWorks_() {
}

TeacherCommissionMember::~TeacherCommissionMember() {}

void TeacherCommissionMember::addCommissionWork(const String& work,double value) {
    commissionWorks_.pushBack(work,value);
}

void TeacherCommissionMember::printInfo() const {
    Teacher::printInfo();
    CommissionMember::printInfo();

    if (commissionWorks_.find("") == nullptr) {
        std::cout << "Работы в комиссии:" << std::endl;
        commissionWorks_.print();
    }
}
