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

    // Проверяем существование файла
    std::ifstream testFile(FILENAME);
    if (!testFile.good()) {
        testFile.close();
        return nullptr;
    }
    testFile.close();

    // Подсчитываем записи
    int recordCount = countRecords();
    if (recordCount == 0) {
        return nullptr;
    }

    // Открываем файл для чтения
    std::ifstream in(FILENAME);
    if (!in.is_open()) {
        return nullptr;
    }

    // Выделяем память
    Employee* employees = new Employee[recordCount];

    // Читаем данные с проверкой
    while (count < recordCount && in >> employees[count]) {
        count++;
    }

    in.close();

    // Если ничего не прочитали, освобождаем память
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

    Employee* emp = new Employee();

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

    if (!lastName) {
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

    Employee* tempEmployees = new Employee[totalRecords];
    Employee currentEmp;
    int readCount = 0;

    while (readCount < totalRecords && in >> currentEmp) {
        if (StringUtils::stringCompare(currentEmp.getLastName(),lastName) == 0) {
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

    Employee* result = new Employee[count];
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