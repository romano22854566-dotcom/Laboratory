#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include "Employee.hpp"

class FileManager {
private:
    static const char* FILENAME;

public:
    static bool writeEmployee(const Employee& emp);
    static Employee* readAllEmployees(int& count);
    static Employee* findEmployeeByNumber(int number,bool& found);
    static Employee* findEmployeesByLastName(const char* lastName,int& count);
    static int countRecords();
    static bool clearFile();
    static bool fileExists();
};

#endif