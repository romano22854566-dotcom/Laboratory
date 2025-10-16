#include "menu.hpp"
#include <iostream>
#include <locale.h>

    int main() {
        setlocale(0,"rus");
        Menu menu;
        int choice{};

        do {
            std::cout << "\n=== ���� ===\n"
                << "1. ������� �������������\n"
                << "2. ������� ����� ��������\n"
                << "3. ������� �������������-����� ��������\n"
                << "4. �������� ���� ��������� �����\n"
                << "5. �������� ������� ���� �������������\n"
                << "6. �������� ������ ������������� ����� ��������\n"
                << "7. �������� ������ � ��������\n"
                << "0. �����\n"
                << "�������� �����: ";
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
            case 0: std::cout << "�����...\n"; break;
            default: std::cout << "�������� �����!\n"; break;
            }
        } while (choice != 0);

        return 0;
    }
