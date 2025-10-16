#include "teacher.hpp"
#include <iostream>

Teacher::Teacher() = default;

Teacher::Teacher(const String& name,const String& surname,const String& patronymic,int yearOfBirth,
                 const String& position,const String& degree,const String& specialty)
    : Person(name,surname,patronymic,yearOfBirth),
    position(position),degree(degree),specialty(specialty) {
}

void Teacher::addWork(const String& work) {
    works.pushBack(work);
}

void Teacher::printInfo() const {
    printBase();
    std::cout << "���������: " << position.cStr()
        << ", �������: " << degree.cStr()
        << ", �������������: " << specialty.cStr() << std::endl;
    if (!works.empty()) {
        std::cout << "������� �����:\n";
        works.print();
    }
}
