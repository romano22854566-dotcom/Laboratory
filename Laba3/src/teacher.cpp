#include "teacher.hpp"
#include <iostream>

Teacher::Teacher(): Person(),position_(),degree_(),specialty_(),works_() {}
Teacher::Teacher(const String& name,const String& surname,const String& patronymic,int year,
                 const String& position,const String& degree,const String& specialty)
    : Person(name,surname,patronymic,year),
    position_(position),degree_(degree),specialty_(specialty),works_() {
}
Teacher::~Teacher() {}

void Teacher::setPosition(const String& position) { position_ = position; }
void Teacher::setDegree(const String& degree) { degree_ = degree; }
void Teacher::setSpecialty(const String& specialty) { specialty_ = specialty; }

const String& Teacher::getPosition() const { return position_; }
const String& Teacher::getDegree() const { return degree_; }
const String& Teacher::getSpecialty() const { return specialty_; }

void Teacher::addWork(const String& work,double value) { works_.pushBack(work,value); }

void Teacher::printInfo() const {
    Person::printInfo();
    std::cout << "Должность: " << position_.cStr()
        << ", Степень: " << degree_.cStr()
        << ", Специальность: " << specialty_.cStr() << std::endl;

    if (works_.find("") == nullptr) { 
        std::cout << "Научные труды:" << std::endl;
        works_.print();
    }
}
