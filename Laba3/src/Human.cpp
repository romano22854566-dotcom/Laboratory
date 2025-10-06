#include "Human.h"

Human::Human(): firstName(nullptr),lastName(nullptr),patronymic(nullptr),birthYear(0) {}

Human::Human(const char* fName,const char* lName,const char* pat,int year): birthYear(year) {
    firstName = safeCopy(fName);
    lastName = safeCopy(lName);
    patronymic = safeCopy(pat);
}

Human::~Human() {
    delete[] firstName;
    delete[] lastName;
    delete[] patronymic;
}

void Human::setFirstName(const char* fName) {
    delete[] firstName;
    firstName = safeCopy(fName);
}

void Human::setLastName(const char* lName) {
    delete[] lastName;
    lastName = safeCopy(lName);
}

void Human::setPatronymic(const char* pat) {
    delete[] patronymic;
    patronymic = safeCopy(pat);
}

void Human::setBirthYear(int year) {
    birthYear = year;
}