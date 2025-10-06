#define _CRT_SECURE_NO_WARNINGS
#include "Human.h"

Human::Human(): firstName(nullptr),lastName(nullptr),patronymic(nullptr),birthYear(0) {}

Human::Human(const char* fName,const char* lName,const char* pat,int year): birthYear(year) {
    firstName = new char[strlen(fName) + 1];
    strcpy(firstName,fName);

    lastName = new char[strlen(lName) + 1];
    strcpy(lastName,lName);

    patronymic = new char[strlen(pat) + 1];
    strcpy(patronymic,pat);
}

Human::~Human() {
    delete[] firstName;
    delete[] lastName;
    delete[] patronymic;
}

void Human::setFirstName(const char* fName) {
    delete[] firstName;
    firstName = new char[strlen(fName) + 1];
    strcpy(firstName,fName);
}

void Human::setLastName(const char* lName) {
    delete[] lastName;
    lastName = new char[strlen(lName) + 1];
    strcpy(lastName,lName);
}

void Human::setPatronymic(const char* pat) {
    delete[] patronymic;
    patronymic = new char[strlen(pat) + 1];
    strcpy(patronymic,pat);
}

void Human::setBirthYear(int year) {
    birthYear = year;
}