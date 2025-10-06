#include "Human.h"

Human::Human(): firstName(nullptr),lastName(nullptr),patronymic(nullptr),birthYear(0) {}

Human::Human(const char* fName,const char* lName,const char* pat,int year): birthYear(year) {
    size_t len = strlen(fName) + 1;
    firstName = new char[len];
    strcpy_s(firstName,len,fName);

    len = strlen(lName) + 1;
    lastName = new char[len];
    strcpy_s(lastName,len,lName);

    len = strlen(pat) + 1;
    patronymic = new char[len];
    strcpy_s(patronymic,len,pat);
}

Human::~Human() {
    delete[] firstName;
    delete[] lastName;
    delete[] patronymic;
}

void Human::setFirstName(const char* fName) {
    delete[] firstName;
    size_t len = strlen(fName) + 1;
    firstName = new char[len];
    strcpy_s(firstName,len,fName);
}

void Human::setLastName(const char* lName) {
    delete[] lastName;
    size_t len = strlen(lName) + 1;
    lastName = new char[len];
    strcpy_s(lastName,len,lName);
}

void Human::setPatronymic(const char* pat) {
    delete[] patronymic;
    size_t len = strlen(pat) + 1;
    patronymic = new char[len];
    strcpy_s(patronymic,len,pat);
}

void Human::setBirthYear(int year) {
    birthYear = year;
}