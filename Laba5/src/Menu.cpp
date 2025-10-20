#include "Menu.hpp"
#include "LinkedList.hpp"
#include "Utilities.hpp"
#include <iostream>

using namespace std;

template<typename Type>
void runMenu() {
    LinkedList<Type> list;
    int choice;

    while (true) {
        cout << "\n=== ���� ===\n";
        cout << "1. �������� � ������\n";
        cout << "2. �������� � �����\n";
        cout << "3. ������� �� ������\n";
        cout << "4. ������� �� �����\n";
        cout << "5. ������� �� �������\n";
        cout << "6. ���� ������\n";
        cout << "7. �������� ������\n";
        cout << "8. ������ ������\n";
        cout << "0. �����\n> ";

        choice = InputInt("");

        switch (choice) {
        case 1: {
            Type val;
            if constexpr (is_same<Type,int>::value) val = InputInt("������� �����: ");
            else if constexpr (is_same<Type,float>::value) val = InputFloat("������� �����: ");
            else if constexpr (is_same<Type,string>::value) val = InputString("������� ������: ");
            else if constexpr (is_same<Type,char>::value) val = InputChar("������� ������: ");
            list.pushFront(val);
            break;
        }
        case 2: {
            Type val;
            if constexpr (is_same<Type,int>::value) val = InputInt("������� �����: ");
            else if constexpr (is_same<Type,float>::value) val = InputFloat("������� �����: ");
            else if constexpr (is_same<Type,string>::value) val = InputString("������� ������: ");
            else if constexpr (is_same<Type,char>::value) val = InputChar("������� ������: ");
            list.pushBack(val);
            break;
        }
        case 3: list.popFront(); break;
        case 4: list.popBack(); break;
        case 5: {
            int idx = InputInt("������� ������: ");
            if (!list.removeAt(idx)) cout << "�������� ������!\n";
            break;
        }
        case 6: list.printList(); break;
        case 7: list.clear(); break;
        case 8: cout << "������ ������: " << list.size() << endl; break;
        case 0: return;
        default: cout << "�������� �����!\n";
        }
    }
}

void runProgram() {
    cout << "�������� ��� ������:\n1. int\n2. float\n3. string\n4. char\n> ";
    int type = InputInt("");
    switch (type) {
    case 1: runMenu<int>(); break;
    case 2: runMenu<float>(); break;
    case 3: runMenu<string>(); break;
    case 4: runMenu<char>(); break;
    default: cout << "�������� �����!\n";
    }
}
