#include "person.hpp"
#include <iostream>

Person::Person(const String& name,const String& surname,const String& patronymic,int yearOfBirth)
    : name(name),surname(surname),patronymic(patronymic),yearOfBirth(yearOfBirth) {
}

void Person::printBase() const {
    std::cout << surname.cStr() << " " << name.cStr() << " " << patronymic.cStr()
        << ", " << yearOfBirth << std::endl;
}
