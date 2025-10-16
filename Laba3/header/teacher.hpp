#pragma once
#include "person.hpp"
#include "linkedList.hpp"

class Teacher: public virtual Person {
private:
    String position;
    String degree;
    String specialty;
    LinkedList works;

public:
    Teacher() = default;
    Teacher(const String& name,const String& surname,const String& patronymic,int yearOfBirth,
            const String& position,const String& degree,const String& specialty);

    void addWork(const String& work);
    void printInfo() const override;
};
