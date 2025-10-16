#pragma once
#include "person.hpp"
#include "linkedList.hpp"

class CommissionMember: public virtual Person {
private:
    String commissionName;
    int yearAppointed;
    int certificateNumber;
    LinkedList biography;

public:
    CommissionMember();
    CommissionMember(const String& name,const String& surname,const String& patronymic,int yearOfBirth,
                     const String& commissionName,int yearAppointed,int certificateNumber);

    void addBio(const String& line);
    void printInfo() const override;
};
