#include "menu.hpp"
#include <iostream>
#include <locale.h>

int main() {
    setlocale(0,"rus");
    int choice;
    do {
        std::cout << "\n=== ���� ===\n";
        std::cout << "1. ������� ������������� ������������\n";
        std::cout << "2. ������� ����� ��������\n";
        std::cout << "3. ������� �������������-����� ��������\n";
        std::cout << "4. �������� ���� ��������� �����\n";
        std::cout << "5. �������� ������� ���� �������������\n";
        std::cout << "6. �������� ������ ������������� ����� ��������\n";
        std::cout << "7. �������� ������ � ��������\n";
        std::cout << "0. �����\n";
        std::cout << "�������� �����: ";
        std::cin >> choice;

        switch (choice) {
        case 1: createTeacher(); break;
        case 2: createCommissionMember(); break;
        case 3: createTeacherCommissionMember(); break;
        case 4: showAllPeople(); break;
        case 5: addWorkToTeachers(); break;
        case 6: addBioToCommissionMembers(); break;
        case 7: addCommissionWorkToTCM(); break;
        case 0: std::cout << "�����...\n"; break;
        default: std::cout << "�������� �����!\n"; break;
        }
    } while (choice != 0);
    for (int i = 0; i < peopleCount; i++) delete people[i];
    delete[] people;
    return 0;
}
