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
        cout << "\n=== МЕНЮ ===\n";
        cout << "1. Добавить в начало\n";
        cout << "2. Добавить в конец\n";
        cout << "3. Удалить из начала\n";
        cout << "4. Удалить из конца\n";
        cout << "5. Удалить по индексу\n";
        cout << "6. Весь список\n";
        cout << "7. Очистить список\n";
        cout << "8. Размер списка\n";
        cout << "0. Выход\n> ";

        choice = InputInt("");

        switch (choice) {
        case 1: {
            Type val;
            if constexpr (is_same<Type,int>::value) val = InputInt("Введите число: ");
            else if constexpr (is_same<Type,float>::value) val = InputFloat("Введите число: ");
            else if constexpr (is_same<Type,string>::value) val = InputString("Введите строку: ");
            else if constexpr (is_same<Type,char>::value) val = InputChar("Введите символ: ");
            list.pushFront(val);
            break;
        }
        case 2: {
            Type val;
            if constexpr (is_same<Type,int>::value) val = InputInt("Введите число: ");
            else if constexpr (is_same<Type,float>::value) val = InputFloat("Введите число: ");
            else if constexpr (is_same<Type,string>::value) val = InputString("Введите строку: ");
            else if constexpr (is_same<Type,char>::value) val = InputChar("Введите символ: ");
            list.pushBack(val);
            break;
        }
        case 3: list.popFront(); break;
        case 4: list.popBack(); break;
        case 5: {
            int idx = InputInt("Введите индекс: ");
            if (!list.removeAt(idx)) cout << "Неверный индекс!\n";
            break;
        }
        case 6: list.printList(); break;
        case 7: list.clear(); break;
        case 8: cout << "Размер списка: " << list.size() << endl; break;
        case 0: return;
        default: cout << "Неверный выбор!\n";
        }
    }
}

void runProgram() {
    cout << "Выберите тип данных:\n1. int\n2. float\n3. string\n4. char\n> ";
    int type = InputInt("");
    switch (type) {
    case 1: runMenu<int>(); break;
    case 2: runMenu<float>(); break;
    case 3: runMenu<string>(); break;
    case 4: runMenu<char>(); break;
    default: cout << "Неверный выбор!\n";
    }
}
