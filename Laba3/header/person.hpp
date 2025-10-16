#pragma once
#include "string.hpp"

class Person {
private:
    String name;
    String surname;
    String patronymic;
    int yearOfBirth{};

public:
    Person() = default;
    Person(const String& name,const String& surname,const String& patronymic,int yearOfBirth);
    virtual ~Person() = default;

    virtual void printInfo() const = 0;

protected:
    void printBase() const;
};
