#pragma once
#include "string.hpp"

class Person {
protected:
    String name_;
    String surname_;
    String patronymic_;
    int birthYear_;

public:
    Person();
    Person(const String& name,const String& surname,const String& patronymic,int year);
    virtual ~Person();

    void setName(const String& name);
    void setSurname(const String& surname);
    void setPatronymic(const String& patronymic);
    void setBirthYear(int year);

    const String& getName() const;
    const String& getSurname() const;
    const String& getPatronymic() const;
    int getBirthYear() const;

    virtual void printInfo() const;
};
