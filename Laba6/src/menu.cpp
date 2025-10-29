#include "menu.hpp"
#include "MyString.hpp"
#include "MyException.hpp"
#include <iostream>
#include <string>

namespace{
MyString*& currentStringRef() {
    static MyString* ptr = nullptr;
    return ptr;
}
MyString*& concatResultRef() {
    static MyString* ptr = nullptr;
    return ptr;
}

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
    std::cout << "\n=== ���� ===\n";
    std::cout << "1. ������� ������\n";
    std::cout << "2. ������� ������\n";
    std::cout << "3. ���������� ��� ������\n";
    std::cout << "4. �������� ����������� ������\n";
    std::cout << "0. �����\n";
    std::cout << "�����: ";
}

void handleCreateString() {
    std::cout << "������� ������ (����. " << MyString::max_length() << " ��������): ";
    if (std::cin.peek() == '\n') std::cin.get();
    const std::string input = readLine();

    try {
        auto created = new MyString(input.c_str());
        auto& cur = currentStringRef();
        clearString(cur);
        cur = created;
        std::cout << "������ �������.\n";
    }
    catch (const StringTooLongException& e) {
        std::cout << e.what() << "\n";
    }
}

void handlePrintString() {
    auto& cur = currentStringRef();
    if (!cur) {
        std::cout << "������ �� �������.\n";
        return;
    }
    std::cout << "������� ������: " << cur->c_str() << "\n";
}

void handleConcatTwoStrings() {
    std::cout << "������� ������ ������ (����. " << MyString::max_length() << "): ";
    if (std::cin.peek() == '\n') std::cin.get();
    const std::string s1 = readLine();

    std::cout << "������� ������ ������ (����. " << MyString::max_length() << "): ";
    const std::string s2 = readLine();

    try {
        MyString m1(s1.c_str());
        MyString m2(s2.c_str());
        MyString res = m1 + m2;
        auto& cr = concatResultRef();
        clearString(cr);
        cr = new MyString(res);
        std::cout << "������ ������� ����������.\n";
    }
    catch (const StringTooLongException& e) {
        std::cout << e.what() << "\n";
    }
    catch (const ConcatTooLongException& e) {
        std::cout << e.what() << "\n";
    }
}

void handleShowConcatenated() {
    auto& cr = concatResultRef();
    if (!cr) {
        std::cout << "����������� ����� ���� ���.\n";
        return;
    }
    std::cout << "��������� �����������: " << cr->c_str() << "\n";
}
