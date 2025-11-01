#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream>
#include <fstream>

class Employee {
private:
    char* firstName;
    char* lastName;
    char* middleName;
    int employeeNumber;

    void allocateString(char*& dest,const char* src);
    void deallocateString(char*& str);

public:
    Employee();
    Employee(const char* fName,const char* lName,const char* mName,int number);
    Employee(const Employee& other);
    Employee& operator=(const Employee& other);
    ~Employee();

    const char* getFirstName() const;
    const char* getLastName() const;
    const char* getMiddleName() const;
    int getEmployeeNumber() const;

    void setFirstName(const char* fName);
    void setLastName(const char* lName);
    void setMiddleName(const char* mName);
    void setEmployeeNumber(int number);

    friend std::ostream& operator<<(std::ostream& out,const Employee& emp);
    friend std::istream& operator>>(std::istream& in,Employee& emp);

    void display() const;
};

#endif