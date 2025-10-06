#include "MenuFunctions.h"
#include <iostream>

void displayMenu() {
    std::cout << "\n=== MENU ===\n";
    std::cout << "1. Create university teacher\n";
    std::cout << "2. Create commission member\n";
    std::cout << "3. Create teacher-commission member\n";
    std::cout << "4. Show all people\n";
    std::cout << "5. Add scientific work to teacher\n";
    std::cout << "6. Add autobiography line to commission member\n";
    std::cout << "7. Add commission work\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose option: ";
}

void resizePeopleArray(Human**& people,int& capacity,int peopleCount) {
    int newCapacity = capacity * 2;
    Human** newPeople = new Human * [newCapacity];
    for (int i = 0; i < peopleCount; i++) {
        newPeople[i] = people[i];
    }
    for (int i = peopleCount; i < newCapacity; i++) {
        newPeople[i] = nullptr;
    }
    delete[] people;
    people = newPeople;
    capacity = newCapacity;
}

void initializePeople(Human**& people,int& capacity) {
    capacity = 2;
    people = new Human * [capacity];
    for (int i = 0; i < capacity; i++) {
        people[i] = nullptr;
    }
}

void cleanup(Human** people,int peopleCount) {
    for (int i = 0; i < peopleCount; i++) {
        if (people[i]) {
            delete people[i];
        }
    }
    delete[] people;
}

void createUniversityTeacher(Human**& people,int& peopleCount,int& capacity) {
    if (peopleCount >= capacity) {
        resizePeopleArray(people,capacity,peopleCount);
    }
    people[peopleCount] = new UniversityTeacher();
    if (people[peopleCount]) {
        people[peopleCount]->input();
        peopleCount++;
        std::cout << "University teacher created!\n";
    }
}

void createCommissionMember(Human**& people,int& peopleCount,int& capacity) {
    if (peopleCount >= capacity) {
        resizePeopleArray(people,capacity,peopleCount);
    }
    people[peopleCount] = new CommissionMember();
    if (people[peopleCount]) {
        people[peopleCount]->input();
        peopleCount++;
        std::cout << "Commission member created!\n";
    }
}

void createTeacherCommissionMember(Human**& people,int& peopleCount,int& capacity) {
    if (peopleCount >= capacity) {
        resizePeopleArray(people,capacity,peopleCount);
    }
    people[peopleCount] = new TeacherCommissionMember();
    if (people[peopleCount]) {
        people[peopleCount]->input();
        peopleCount++;
        std::cout << "Teacher-commission member created!\n";
    }
}

void displayAllPeople(Human** people,int peopleCount) {
    if (peopleCount == 0) {
        std::cout << "No people created.\n";
    }
    else {
        std::cout << "\n=== ALL CREATED PEOPLE (" << peopleCount << ") ===\n";
        for (int i = 0; i < peopleCount; i++) {
            if (people[i]) {
                std::cout << "\n--- Person " << (i + 1) << " ---\n";
                people[i]->display();
            }
        }
    }
}

void addScientificWork(Human** people,int peopleCount) {
    if (peopleCount == 0) {
        std::cout << "No people created.\n";
        return;
    }

    std::cout << "Choose teacher (1-" << peopleCount << "): ";
    int index;
    if (!(std::cin >> index)) {
        std::cout << "Invalid input!\n";
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        return;
    }
    index--;

    if (index < 0 || index >= peopleCount || !people[index]) {
        std::cout << "Invalid index!\n";
        return;
    }

    UniversityTeacher* teacher = dynamic_cast<UniversityTeacher*>(people[index]);
    if (!teacher) {
        std::cout << "Selected person is not a university teacher!\n";
        return;
    }

    char work[256];
    std::cout << "Enter scientific work: ";
    std::cin.ignore();
    if (std::cin.getline(work,256)) {
        teacher->addScientificWork(work);
        std::cout << "Scientific work added!\n";
    }
}

void addAutobiographyLine(Human** people,int peopleCount) {
    if (peopleCount == 0) {
        std::cout << "No people created.\n";
        return;
    }

    std::cout << "Choose commission member (1-" << peopleCount << "): ";
    int index;
    if (!(std::cin >> index)) {
        std::cout << "Invalid input!\n";
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        return;
    }
    index--;

    if (index < 0 || index >= peopleCount || !people[index]) {
        std::cout << "Invalid index!\n";
        return;
    }

    CommissionMember* member = dynamic_cast<CommissionMember*>(people[index]);
    if (!member) {
        std::cout << "Selected person is not a commission member!\n";
        return;
    }

    char line[256];
    std::cout << "Enter autobiography line: ";
    std::cin.ignore();
    if (std::cin.getline(line,256)) {
        member->addAutobiographyLine(line);
        std::cout << "Autobiography line added!\n";
    }
}

void addCommissionWork(Human** people,int peopleCount) {
    if (peopleCount == 0) {
        std::cout << "No people created.\n";
        return;
    }

    std::cout << "Choose teacher-commission member (1-" << peopleCount << "): ";
    int index;
    if (!(std::cin >> index)) {
        std::cout << "Invalid input!\n";
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        return;
    }
    index--;

    if (index < 0 || index >= peopleCount || !people[index]) {
        std::cout << "Invalid index!\n";
        return;
    }

    TeacherCommissionMember* tcm = dynamic_cast<TeacherCommissionMember*>(people[index]);
    if (!tcm) {
        std::cout << "Selected person is not a teacher-commission member!\n";
        return;
    }

    char work[256];
    std::cout << "Enter commission work: ";
    std::cin.ignore();
    if (std::cin.getline(work,256)) {
        tcm->addCommissionWork(work);
        std::cout << "Commission work added!\n";
    }
}