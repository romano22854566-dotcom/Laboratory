#include "menu.hpp"
#include <iostream>
#include <locale.h>

int main() {
    setlocale(0,"rus");
    int choice;
    do {
        std::cout << "\n=== МЕНЮ ===\n";
        std::cout << "1. Создать преподавателя университета\n";
        std::cout << "2. Создать члена комиссии\n";
        std::cout << "3. Создать преподавателя-члена комиссии\n";
        std::cout << "4. Показать всех созданных людей\n";
        std::cout << "5. Добавить научный труд преподавателю\n";
        std::cout << "6. Добавить строку автобиографии члену комиссии\n";
        std::cout << "7. Добавить работу в комиссии\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите опцию: ";
        std::cin >> choice;

        switch (choice) {
        case 1: createTeacher(); break;
        case 2: createCommissionMember(); break;
        case 3: createTeacherCommissionMember(); break;
        case 4: showAllPeople(); break;
        case 5: addWorkToTeachers(); break;
        case 6: addBioToCommissionMembers(); break;
        case 7: addCommissionWorkToTCM(); break;
        case 0: std::cout << "Выход...\n"; break;
        default: std::cout << "Неверный выбор!\n"; break;
        }
    } while (choice != 0);
    for (int i = 0; i < peopleCount; i++) delete people[i];
    delete[] people;
    return 0;
}
