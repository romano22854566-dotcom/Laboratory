#pragma once
#include "teacher.hpp"
#include "commissionMember.hpp"

class TeacherCommissionMember: public Teacher,public CommissionMember {
private:
    LinkedList commissionWorks_;

public:
    TeacherCommissionMember();
    TeacherCommissionMember(const String& name,const String& surname,const String& patronymic,int year,
                            const String& position,const String& degree,const String& specialty,
                            const String& commissionName,int yearAppointed,int certificateNumber);
    virtual ~TeacherCommissionMember();

    void addCommissionWork(const String& work,double value);
    void printInfo() const override;
};
