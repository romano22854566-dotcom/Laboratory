#include "Employee.hpp"
#include <iostream>
#include <string>

Employee::Employee(const std::string& fName,
                   const std::string& lName,
                   const std::string& mName,
                   int number)
    : firstName(fName),lastName(lName),middleName(mName),employeeNumber(number) {
}

const std::string& Employee::getFirstName() const {
    return firstName;
}

const std::string& Employee::getLastName() const {
    return lastName;
}

const std::string& Employee::getMiddleName() const {
    return middleName;
}

int Employee::getEmployeeNumber() const {
    return employeeNumber;
}

void Employee::setFirstName(const std::string& fName) {
    firstName = fName;
}

void Employee::setLastName(const std::string& lName) {
    lastName = lName;
}

void Employee::setMiddleName(const std::string& mName) {
    middleName = mName;
}

void Employee::setEmployeeNumber(int number) {
    employeeNumber = number;
}

// hidden friend Ч объ€влен в Employee.hpp
std::ostream& operator<<(std::ostream& out,const Employee& emp) {
    out << emp.lastName << ' '
        << emp.firstName << ' '
        << emp.middleName << ' '
        << emp.employeeNumber;
    return out;
}

// hidden friend Ч объ€влен в Employee.hpp
std::istream& operator>>(std::istream& in,Employee& emp) {
    std::string l,f,m;
    int num{};
    if (!(in >> l >> f >> m >> num)) {
        return in;
    }
    emp.lastName = std::move(l);
    emp.firstName = std::move(f);
    emp.middleName = std::move(m);
    emp.employeeNumber = num;
    return in;
}

void Employee::display() const {
    std::cout << "‘амили€: " << lastName << "\n"
        << "»м€: " << firstName << "\n"
        << "ќтчество: " << middleName << "\n"
        << "“абельный номер: " << employeeNumber << "\n";
}
