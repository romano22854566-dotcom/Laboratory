#pragma once
#include "teacher.hpp"
#include "commissionMember.hpp"
#include "linkedList.hpp"

class TeacherCommissionMember: public Teacher,public CommissionMember {
private:
    LinkedList commissionWorks;

public:
    TeacherCommissionMember();
    TeacherCommissionMember(const String& name,const String& surname,const String& patronymic,int yearOfBirth,
                            const String& position,const String& degree,const String& specialty,
                            const String& commissionName,int yearAppointed,int certificateNumber);

    void addCommissionWork(const String& work);
    void printInfo() const override;
};
