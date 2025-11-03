#include "Employee.hpp"

Employee::Employee(const std::string& fName,
                   const std::string& lName,
                   const std::string& mName,
                   int number)
    : firstName(fName),lastName(lName),middleName(mName),employeeNumber(number) {
}

const std::string& Employee::getFirstName() const { return firstName; }
const std::string& Employee::getLastName() const { return lastName; }
const std::string& Employee::getMiddleName() const { return middleName; }
int Employee::getEmployeeNumber() const { return employeeNumber; }

void Employee::setFirstName(const std::string& fName) { firstName = fName; }
void Employee::setLastName(const std::string& lName) { lastName = lName; }
void Employee::setMiddleName(const std::string& mName) { middleName = mName; }
void Employee::setEmployeeNumber(int number) { employeeNumber = number; }

std::ostream& operator<<(std::ostream& out,const Employee& emp) {
    out << emp.lastName << " "
        << emp.firstName << " "
        << emp.middleName << " "
        << emp.employeeNumber;
    return out;
}

std::istream& operator>>(std::istream& in,Employee& emp) {
    return in >> emp.lastName >> emp.firstName >> emp.middleName >> emp.employeeNumber;
}

void Employee::display() const {
    std::cout << "Фамилия: " << lastName << "\n"
        << "Имя: " << firstName << "\n"
        << "Отчество: " << middleName << "\n"
        << "Табельный номер: " << employeeNumber << "\n";
}
