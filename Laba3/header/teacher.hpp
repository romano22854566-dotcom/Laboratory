#pragma once
#include "person.hpp"
#include "linkedList.hpp"

class Teacher: virtual public Person {
protected:
    String position_;
    String degree_;
    String specialty_;
    LinkedList works_;

public:
    Teacher();
    Teacher(const String& name,const String& surname,const String& patronymic,int year,
            const String& position,const String& degree,const String& specialty);
    virtual ~Teacher();

    void setPosition(const String& position);
    void setDegree(const String& degree);
    void setSpecialty(const String& specialty);

    const String& getPosition() const;
    const String& getDegree() const;
    const String& getSpecialty() const;

    void addWork(const String& work,double value);
    void printInfo() const override;
};
