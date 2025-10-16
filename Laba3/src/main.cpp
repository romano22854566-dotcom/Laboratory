#include "menu.hpp"
#include <iostream>
#include <locale.h>

    int main() {
        setlocale(0,"rus");
        Menu menu;
        int choice{};

        do {
            std::cout << "\n=== МЕНЮ ===\n"
                << "1. Создать преподавателя\n"
                << "2. Создать члена комиссии\n"
                << "3. Создать преподавателя-члена комиссии\n"
                << "4. Показать всех созданных людей\n"
                << "5. Добавить научный труд преподавателю\n"
                << "6. Добавить строку автобиографии члену комиссии\n"
                << "7. Добавить работу в комиссии\n"
                << "0. Выход\n"
                << "Выберите опцию: ";
            std::cin >> choice;
            std::cin.ignore();

            switch (choice) {
            case 1: menu.createTeacher(); break;
            case 2: menu.createCommissionMember(); break;
            case 3: menu.createTeacherCommissionMember(); break;
            case 4: menu.showAllPeople(); break;
            case 5: menu.addWorkToTeacher(); break;
            case 6: menu.addBioToCommissionMember(); break;
            case 7: menu.addCommissionWorkToTCM(); break;
            case 0: std::cout << "Выход...\n"; break;
            default: std::cout << "Неверный выбор!\n"; break;
            }
        } while (choice != 0);

        return 0;
    }
