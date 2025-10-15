#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <cstring>

class Human {
private:
    char* firstName;
    char* lastName;
    char* patronymic;
    int birthYear;

protected:
    static char* safeCopy(const char* source);

public:
    Human();
    Human(const char* fName,const char* lName,const char* pat,int year);
    virtual ~Human();

    const char* getFirstName() const { return firstName ? firstName : ""; }
    const char* getLastName() const { return lastName ? lastName : ""; }
    const char* getPatronymic() const { return patronymic ? patronymic : ""; }
    int getBirthYear() const { return birthYear; }

    void setFirstName(const char* fName);
    void setLastName(const char* lName);
    void setPatronymic(const char* pat);
    void setBirthYear(int year);

    virtual void display() const = 0;
    virtual void input() = 0;

    Human(const Human&) = delete;
    Human& operator=(const Human&) = delete;
};

#endif