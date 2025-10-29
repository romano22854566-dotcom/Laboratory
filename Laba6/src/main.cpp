#include <iostream>
#include "menu.hpp"
#include <locale.h>
int main() {
    setlocale(0,"rus");
    int choice = -1;
    do {
        showMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            while (std::cin.get() != '\n' && std::cin.good()) {
            }
            std::cout << "�������� ����.\n";
            continue;
        }

        switch (choice) {
        case 1: handleCreateString(); 
            break;
        case 2: handlePrintString();     
            break;
        case 3: handleConcatTwoStrings(); 
            break;
        case 4: handleShowConcatenated(); 
            break;
        case 0: std::cout << "�����\n"; 
            break;
        default: std::cout << "������ �������� ����� ����.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
