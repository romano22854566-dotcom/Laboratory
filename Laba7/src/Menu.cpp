#include "Menu.hpp"
#include "Employee.hpp"
#include "FileManager.hpp"
#include <iostream>
#include <limits>
#include <string>

void Menu::run() {
    int choice;
    bool running = true;

    while (running) {
        displayMainMenu();
        choice = getUserChoice();

        switch (choice) {
        case 1: handleAddEmployee(); break;
        case 2: handleShowAllEmployees(); break;
        case 3: handleFindByNumber(); break;
        case 4: handleFindByLastName(); break;
        case 5: handleClearDatabase(); break;
        case 0:
        std::cout << "\nВыход\n";
        running = false;
        break;
        default:
        std::cout << "\nОшибка: неверный выбор.\n";
        break;
        }
    }
}

void Menu::displayMainMenu() {
    std::cout << "=== Меню ===\n";
    std::cout << "1. Добавить сотрудника\n";
    std::cout << "2. Показать всех сотрудников\n";
    std::cout << "3. Найти по номеру\n";
    std::cout << "4. Найти по фамилии\n";
    std::cout << "5. Очистить базу\n";
    std::cout << "0. Выход\n";
    std::cout << "Выбор: ";
}

int Menu::getUserChoice() {
    int choice;
    while (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Ошибка, введите число: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    return choice;
}

void Menu::handleAddEmployee() {
    std::string firstName;
    std::string lastName;
    std::string middleName;
    int number;

    std::cout << "\nВведите данные сотрудника\n";
    std::cout << "Фамилия: ";
    std::cin >> lastName;
    std::cout << "Имя: ";
    std::cin >> firstName;
    std::cout << "Отчество: ";
    std::cin >> middleName;

    std::cout << "Номер сотрудника: ";
    while (!(std::cin >> number) || number <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Ошибка, введите положительное число: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    Employee newEmployee(firstName,lastName,middleName,number);
    if (FileManager::writeEmployee(newEmployee)) {
        std::cout << "\nСотрудник добавлен.\n";
    }
    else {
        std::cout << "\nОшибка записи.\n";
    }
}

void Menu::handleShowAllEmployees() {
    int count = 0;
    Employee* employees = FileManager::readAllEmployees(count);

    if (!employees || count == 0) {
        std::cout << "\nНет сотрудников.\n";
        return;
    }

    std::cout << "\nСписок сотрудников:\n";
    for (int i = 0; i < count; i++) {
        std::cout << "\n[" << (i + 1) << "]\n";
        employees[i].display();
    }
    std::cout << "\nВсего сотрудников: " << count << "\n";

    delete[] employees;
}

void Menu::handleFindByNumber() {
    int number;
    std::cout << "\nВведите номер сотрудника: ";
    while (!(std::cin >> number) || number <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Ошибка, введите положительное число: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    bool found = false;
    Employee* employee = FileManager::findEmployeeByNumber(number,found);

    if (found && employee) {
        std::cout << "\nНайден сотрудник:\n";
        employee->display();
        delete employee;
    }
    else {
        std::cout << "\nСотрудник с номером " << number << " не найден.\n";
    }
}

void Menu::handleFindByLastName() {
    std::string lastName;
    std::cout << "\nВведите фамилию для поиска: ";
    std::getline(std::cin,lastName);

    int count = 0;
    Employee* employees = FileManager::findEmployeesByLastName(lastName.c_str(),count);

    if (!employees || count == 0) {
        std::cout << "\nСотрудники с фамилией \"" << lastName << "\" не найдены.\n";
        return;
    }

    std::cout << "\nНайденные сотрудники:\n";
    for (int i = 0; i < count; i++) {
        std::cout << "\n[" << (i + 1) << "]\n";
        employees[i].display();
    }
    std::cout << "\nВсего найдено: " << count << "\n";

    delete[] employees;
}

void Menu::handleClearDatabase() {
    char confirm;
    std::cout << "\nВы уверены, что хотите очистить базу? (y/n): ";
    std::cin >> confirm;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    if (confirm == 'y' || confirm == 'Y') {
        if (FileManager::clearFile()) {
            std::cout << "\nБаза очищена.\n";
        }
        else {
            std::cout << "\nОшибка очистки базы.\n";
        }
    }
    else {
        std::cout << "\nОтмена операции.\n";
    }
}
