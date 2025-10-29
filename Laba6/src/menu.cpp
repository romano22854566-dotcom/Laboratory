#include "menu.hpp"
#include "MyString.hpp"
#include "MyException.hpp"
#include <iostream>
#include <string>

namespace{

MyString* gCurrentString = nullptr; 
MyString* gConcatResult = nullptr;  

void clearString(MyString*& ptr) {
    delete ptr;
    ptr = nullptr;
}

std::string readLine() {
    std::string s;
    std::getline(std::cin,s);
    return s;
}
}

void showMenu() {
    std::cout << "\n=== МЕНЮ ===\n";
    std::cout << "1. Создать строку\n";
    std::cout << "2. Вывести строку\n";
    std::cout << "3. Объединить две строки\n";
    std::cout << "4. Показать объединённые строки\n";
    std::cout << "0. Выход\n";
    std::cout << "Выбор: ";
}

void handleCreateString() {
    std::cout << "Введите строку (макс. " << MyString::max_length() << " символов): ";
    if (std::cin.peek() == '\n') std::cin.get();
    const std::string input = readLine();

    try {
        auto created = new MyString(input.c_str()); 
        clearString(gCurrentString);
        gCurrentString = created;
        std::cout << "Строка создана.\n";
    }
    catch (const StringTooLongException& e) {
        std::cout << e.what() << "\n";
    }
}

void handlePrintString() {
    if (!gCurrentString) {
        std::cout << "Строка не создана.\n";
        return;
    }
    std::cout << "Текущая строка: " << gCurrentString->c_str() << "\n";
}

void handleConcatTwoStrings() {
    std::cout << "Введите первую строку (макс. " << MyString::max_length() << "): ";
    if (std::cin.peek() == '\n') std::cin.get();
    const std::string s1 = readLine();

    std::cout << "Введите вторую строку (макс. " << MyString::max_length() << "): ";
    const std::string s2 = readLine();

    try {
        MyString m1(s1.c_str());
        MyString m2(s2.c_str());
        MyString res = m1 + m2;
        clearString(gConcatResult);
        gConcatResult = new MyString(res); 
        std::cout << "Строки успешно объединены.\n";
    }
    catch (const StringTooLongException& e) {
        std::cout << e.what() << "\n";
    }
    catch (const ConcatTooLongException& e) {
        std::cout << e.what() << "\n";
    }
}

void handleShowConcatenated() {
    if (!gConcatResult) {
        std::cout << "Объединённых строк пока нет.\n";
        return;
    }
    std::cout << "Результат объединения: " << gConcatResult->c_str() << "\n";
}
