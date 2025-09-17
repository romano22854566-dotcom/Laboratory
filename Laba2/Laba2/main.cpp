#include <iostream>
#include "Matrix.h"
#include <string>
#include <sstream>
#include <locale>
void printMenu() {
    std::cout << "\n=== ���� ===\n";
    std::cout << "1. �������� ������ �������\n";
    std::cout << "2. �������� ������ �������\n";
    std::cout << "3. �������� �������\n";
    std::cout << "4. �����\n";
    std::cout << "��������: ";
}

// ������� ��� ����������� ����� ������ ����
int safeMenuInput() {
    std::string input;
    int choice;

    while (true) {
        printMenu();
        std::getline(std::cin, input);

        if (input.empty()) {
            continue;
        }

        std::stringstream ss(input);
        ss >> choice;

        if (ss.fail() || !ss.eof() || choice < 1 || choice > 4) {
            std::cout << "������! ������� ����� �� 1 �� 4: ";
        }
        else {
            return choice;
        }
    }
}

int main() {
    setlocale(0, "rus");
    Matrix matrix1, matrix2, result;

    std::cout << "=== ��������� ������ ===\n\n";

    // ���� ������ �������
    std::cout << "������ �������:\n";
    std::cin >> matrix1;

    // ���� ������ �������
    std::cout << "\n������ �������:\n";
    std::cin >> matrix2;

    int choice;

    do {
        choice = safeMenuInput();

        switch (choice) {
        case 1:
            std::cout << "\n������ �������:\n" << matrix1;
            break;

        case 2:
            std::cout << "\n������ �������:\n" << matrix2;
            break;

        case 3:
            result = matrix1 & matrix2;
            if (result.getRows() > 0) {
                std::cout << "\n��������� ���������:\n" << result;
            }
            break;

        case 4:
            std::cout << "�����...\n";
            break;
        }

    } while (choice != 4);

    return 0;
}