#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <cstring>

class Human {
protected:
    char* firstName;
    char* lastName;
    char* patronymic;
    int birthYear;

public:
    Human();
    Human(const char* fName,const char* lName,const char* pat,int year);
    virtual ~Human();

    // Геттеры
    const char* getFirstName() const { return firstName; }
    const char* getLastName() const { return lastName; }
    const char* getPatronymic() const { return patronymic; }
    int getBirthYear() const { return birthYear; }

    // Сеттеры
    void setFirstName(const char* fName);
    void setLastName(const char* lName);
    void setPatronymic(const char* pat);
    void setBirthYear(int year);

    virtual void display() const = 0;
    virtual void input() = 0;
};

#endif