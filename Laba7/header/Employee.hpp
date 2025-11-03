#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream>
#include <string>

class Employee {
private:
    std::string firstName{""};
    std::string lastName{""};
    std::string middleName{""};
    int employeeNumber{0};

public:
    Employee() = default;
    Employee(const std::string& fName,
             const std::string& lName,
             const std::string& mName,
             int number);

    // Rule of 0
    Employee(const Employee&) = default;
    Employee& operator=(const Employee&) = default;
    ~Employee() = default;

    const std::string& getFirstName() const;
    const std::string& getLastName() const;
    const std::string& getMiddleName() const;
    int getEmployeeNumber() const;

    void setFirstName(const std::string& fName);
    void setLastName(const std::string& lName);
    void setMiddleName(const std::string& mName);
    void setEmployeeNumber(int number);

    void display() const;

    // hidden friends
    friend std::ostream& operator<<(std::ostream& out,const Employee& emp);
    friend std::istream& operator>>(std::istream& in,Employee& emp);
};

#endif
