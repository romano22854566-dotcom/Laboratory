#include <iostream>
#include <locale.h>
#include "menu.hpp"
#include "SinglyLinkedList.hpp"

int main() {
    setlocale(0,"rus");
    ds::SinglyLinkedList list;
    int choice = -1;

    do {
        showMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            while (std::cin.get() != '\n' && std::cin.good());
            std::cout << "Ошибка ввода\n";
            continue;
        }

        switch (choice) {
        case 1: handleAddFront(list);
            break;
        case 2: handleAddBack(list);
            break;
        case 3: handleSortAsc(list); 
            break;
        case 4: handleSortDesc(list);
            break;
        case 5: handlePrintList(list);
            break;
        case 6: handleClearList(list);
            break;
        case 0: std::cout << "Выход\n";
            break;
        default: std::cout << "Неизвестная команда.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
