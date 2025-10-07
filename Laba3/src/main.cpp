#include <iostream>
#include <locale.h>
#include "MenuFunctions.h"

int main() {
    setlocale(0,"rus");
    Human** people = nullptr;
    int peopleCount = 0;
    int capacity = 0;

    initializePeople(people,capacity);

    int choice = -1;

    do {
        displayMenu();
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input!\n";
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            continue;
        }

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
        std::cout << "Exiting program.\n";
        break;
        default:
        std::cout << "Invalid choice!\n";
        break;
        }

    } while (choice != 0);

    cleanup(people,peopleCount);
    return 0;
}