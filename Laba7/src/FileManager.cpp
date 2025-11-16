#include "FileManager.hpp"
#include "StringUtils.hpp"
#include <fstream>

const char* FileManager::FILENAME = "employees.txt";

bool FileManager::writeEmployee(const Employee& emp) {
    std::ofstream out(FILENAME,std::ios::app);

    if (!out.is_open()) {
        return false;
    }

    out << emp << "\n";
    out.close();

    return true;
}

Employee* FileManager::readAllEmployees(int& count) {
    count = 0;

    int recordCount = countRecords();
    if (recordCount == 0) {
        return nullptr;
    }

    std::ifstream in(FILENAME);
    if (!in.is_open()) {
        return nullptr;
    }

     auto employees = new Employee[recordCount];

    while (count < recordCount && in >> employees[count]) {
        count++;
    }

    in.close();

    if (count == 0) {
        delete[] employees;
        return nullptr;
    }

    return employees;
}

Employee* FileManager::findEmployeeByNumber(int number,bool& found) {
    found = false;

    std::ifstream in(FILENAME);
    if (!in.is_open()) {
        return nullptr;
    }

    auto emp = new Employee();

    while (in >> *emp) {
        if (emp->getEmployeeNumber() == number) {
            found = true;
            in.close();
            return emp;
        }
    }

    in.close();
    delete emp;
    return nullptr;
}

Employee* FileManager::findEmployeesByLastName(const char* lastName,int& count) {
    count = 0;

    if (!lastName || std::string(lastName).empty()) {
        return nullptr;
    }

    std::ifstream in(FILENAME);
    if (!in.is_open()) {
        return nullptr;
    }

    int totalRecords = countRecords();
    if (totalRecords == 0) {
        in.close();
        return nullptr;
    }

    auto tempEmployees = new Employee[totalRecords];
    Employee currentEmp;
    int readCount = 0;

    std::string searchStr(lastName);

    while (readCount < totalRecords && in >> currentEmp) {
        if (currentEmp.getLastName().find(searchStr) != std::string::npos) {
            tempEmployees[count] = currentEmp;
            count++;
        }
        readCount++;
    }

    in.close();

    if (count == 0) {
        delete[] tempEmployees;
        return nullptr;
    }

    auto result = new Employee[count];
    for (int i = 0; i < count; i++) {
        result[i] = tempEmployees[i];
    }

    delete[] tempEmployees;
    return result;
}


int FileManager::countRecords() {
    std::ifstream in(FILENAME);

    if (!in.is_open()) {
        return 0;  
    }

    int count = 0;
    Employee temp;

    while (in >> temp) {
        count++;
    }

    in.close();
    return count;
}

bool FileManager::clearFile() {
    std::ofstream out(FILENAME,std::ios::trunc);

    if (!out.is_open()) {
        return false;
    }

    out.close();
    return true;
}

bool FileManager::fileExists() {
    std::ifstream in(FILENAME);
    bool exists = in.good();
    in.close();
    return exists;
}