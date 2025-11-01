#include "Employee.hpp"
#include "StringUtils.hpp"

void Employee::allocateString(char*& dest,const char* src) {
    if (src) {
        size_t len = StringUtils::stringLength(src);
        dest = new char[len + 1];
        StringUtils::stringCopy(dest,src);
    }
    else {
        dest = new char[1];
        dest[0] = '\0';
    }
}

void Employee::deallocateString(char*& str) {
    if (str) {
        delete[] str;
        str = nullptr;
    }
}

Employee::Employee()
    : firstName(nullptr),lastName(nullptr),middleName(nullptr),employeeNumber(0) {
    allocateString(firstName,"");
    allocateString(lastName,"");
    allocateString(middleName,"");
}

Employee::Employee(const char* fName,const char* lName,const char* mName,int number)
    : firstName(nullptr),lastName(nullptr),middleName(nullptr),employeeNumber(number) {
    allocateString(firstName,fName);
    allocateString(lastName,lName);
    allocateString(middleName,mName);
}

Employee::Employee(const Employee& other)
    : firstName(nullptr),lastName(nullptr),middleName(nullptr),employeeNumber(other.employeeNumber) {
    allocateString(firstName,other.firstName);
    allocateString(lastName,other.lastName);
    allocateString(middleName,other.middleName);
}

Employee& Employee::operator=(const Employee& other) {
    if (this != &other) {
        deallocateString(firstName);
        deallocateString(lastName);
        deallocateString(middleName);

        allocateString(firstName,other.firstName);
        allocateString(lastName,other.lastName);
        allocateString(middleName,other.middleName);
        employeeNumber = other.employeeNumber;
    }
    return *this;
}

Employee::~Employee() {
    deallocateString(firstName);
    deallocateString(lastName);
    deallocateString(middleName);
}

const char* Employee::getFirstName() const {
    return firstName ? firstName : "";
}

const char* Employee::getLastName() const {
    return lastName ? lastName : "";
}

const char* Employee::getMiddleName() const {
    return middleName ? middleName : "";
}

int Employee::getEmployeeNumber() const {
    return employeeNumber;
}

void Employee::setFirstName(const char* fName) {
    deallocateString(firstName);
    allocateString(firstName,fName);
}

void Employee::setLastName(const char* lName) {
    deallocateString(lastName);
    allocateString(lastName,lName);
}

void Employee::setMiddleName(const char* mName) {
    deallocateString(middleName);
    allocateString(middleName,mName);
}

void Employee::setEmployeeNumber(int number) {
    employeeNumber = number;
}

std::ostream& operator<<(std::ostream& out,const Employee& emp) {
    if (emp.lastName && emp.firstName && emp.middleName) {
        out << emp.lastName << " "
            << emp.firstName << " "
            << emp.middleName << " "
            << emp.employeeNumber;
    }
    return out;
}

std::istream& operator>>(std::istream& in,Employee& emp) {
    char buffer[256];

    // Читаем фамилию
    if (!(in >> buffer)) {
        return in;
    }
    emp.setLastName(buffer);

    // Читаем имя
    if (!(in >> buffer)) {
        return in;
    }
    emp.setFirstName(buffer);

    // Читаем отчество
    if (!(in >> buffer)) {
        return in;
    }
    emp.setMiddleName(buffer);

    // Читаем номер
    if (!(in >> emp.employeeNumber)) {
        return in;
    }

    return in;
}

void Employee::display() const {
    if (lastName && firstName && middleName) {
        std::cout << "Фамилия: " << lastName << "\n";
        std::cout << "Имя: " << firstName << "\n";
        std::cout << "Отчество: " << middleName << "\n";
        std::cout << "Табельный номер: " << employeeNumber << "\n";
    }
    else {
        std::cout << "Ошибка: некорректные данные сотрудника\n";
    }
}