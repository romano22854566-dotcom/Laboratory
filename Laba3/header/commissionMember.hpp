#pragma once
#include "person.hpp"
#include "linkedList.hpp"

class CommissionMember: virtual public Person {
protected:
    String commissionName_;
    int yearAppointed_;
    int certificateNumber_;
    LinkedList biography_;

public:
    CommissionMember();
    CommissionMember(const String& name,const String& surname,const String& patronymic,int year,
                     const String& commissionName,int yearAppointed,int certificateNumber);
    virtual ~CommissionMember();

    void setCommissionName(const String& commissionName);
    void setYearAppointed(int year);
    void setCertificateNumber(int number);

    const String& getCommissionName() const;
    int getYearAppointed() const;
    int getCertificateNumber() const;

    void addBio(const String& line,double value);
    void printInfo() const override;
};
