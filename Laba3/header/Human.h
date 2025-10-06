#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>

class Human {
protected:
    char* firstName;
    char* lastName;
    char* patronymic;
    int birthYear;
    static char* safeCopy(const char* source) {
        if (!source) return nullptr;
        size_t len = 0;
        while (source[len] != '\0') len++;
        char* dest = new char[len + 1];
        for (size_t i = 0; i < len; i++) {
            dest[i] = source[i];
        }
        dest[len] = '\0';
        return dest;
    }

public:
    Human();
    Human(const char* fName, const char* lName, const char* pat, int year);
    virtual ~Human();
    const char* getFirstName() const { return firstName; }
    const char* getLastName() const { return lastName; }
    const char* getPatronymic() const { return patronymic; }
    int getBirthYear() const { return birthYear; }
    void setFirstName(const char* fName);
    void setLastName(const char* lName);
    void setPatronymic(const char* pat);
    void setBirthYear(int year);
    virtual void display() const = 0;
    virtual void input() = 0;
private:
    Human(const Human&) = delete;
    Human& operator=(const Human&) = delete;
};

#endif