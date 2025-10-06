#include <iostream>
#include <locale.h>
#include "MenuFunctions.h"

int main() {
    setlocale(LC_ALL,"Russian");
    Human** people = nullptr;
    int peopleCount = 0;
    int capacity = 0;

    initializePeople(people,capacity);

    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
        createUniversityTeacher(people,peopleCount,capacity);
        break;

        case 2:
        createCommissionMember(people,peopleCount,capacity);
        break;

        case 3:
        createTeacherCommissionMember(people,peopleCount,capacity);
        break;

        case 4:
        displayAllPeople(people,peopleCount);
        break;

        case 5:
        addScientificWork(people,peopleCount);
        break;

        case 6:
        addAutobiographyLine(people,peopleCount);
        break;

        case 7:
        addCommissionWork(people,peopleCount);
        break;

        case 0:
        std::cout << "Выход из программы.\n";
        break;

        default:
        std::cout << "Неверный выбор!\n";
        }

    } while (choice != 0);

    cleanup(people,peopleCount);
    return 0;
}