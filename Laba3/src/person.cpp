#include "person.hpp"
#include <iostream>

Person::Person(): name_(),surname_(),patronymic_(),birthYear_(0) {}
Person::Person(const String& name,const String& surname,const String& patronymic,int year)
    : name_(name),surname_(surname),patronymic_(patronymic),birthYear_(year) {
}
Person::~Person() {}

void Person::setName(const String& name) { name_ = name; }
void Person::setSurname(const String& surname) { surname_ = surname; }
void Person::setPatronymic(const String& patronymic) { patronymic_ = patronymic; }
void Person::setBirthYear(int year) { birthYear_ = year; }

const String& Person::getName() const { return name_; }
const String& Person::getSurname() const { return surname_; }
const String& Person::getPatronymic() const { return patronymic_; }
int Person::getBirthYear() const { return birthYear_; }

void Person::printInfo() const {
    std::cout << surname_.cStr() << " " << name_.cStr() << " " << patronymic_.cStr()
        << ", " << birthYear_ << std::endl;
}
