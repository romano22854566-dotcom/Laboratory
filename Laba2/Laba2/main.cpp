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
}

// ������� ��� ����������� ����� ������ ����
int safeMenuInput() {
    std::string input;
    int choice;

    while (true) {
        std::cout << "��������: ";
        std::getline(std::cin, input);

        if (input.empty()) {
            continue;
        }

        std::stringstream ss(input);
        ss >> choice;

        if (ss.fail() || !ss.eof() || choice < 1 || choice > 4) {
            std::cout << "������! ������� ����� �� 1 �� 4\n";
        }
        else {
            return choice;
        }
    }
}

void showMatrix(const Matrix& matrix, const std::string& name) {
    std::cout << "\n" << name << ":\n";
    if (matrix.getRows() > 0 && matrix.getCols() > 0) {
        std::cout << matrix;
    }
    else {
        std::cout << "������� �� �������!\n";
    }
}

void multiplyMatrices(const Matrix& matrix1, const Matrix& matrix2) {
    std::cout << "\n��������� ������:\n";
    if (matrix1.getRows() > 0 && matrix1.getCols() > 0 &&
        matrix2.getRows() > 0 && matrix2.getCols() > 0) {
        Matrix result = matrix1 & matrix2;
        if (result.getRows() > 0) {
            std::cout << "���������:\n" << result;
        }
    }
    else {
        std::cout << "��� ������� ������ ���� �������!\n";
    }
}

int main() {
    setlocale(0, "rus");
    Matrix matrix1;
    Matrix matrix2;

    std::cout << "=== ��������� ������ ===\n\n";

    // ���� ������ �������
    std::cout << "������ �������:\n";
    std::cin >> matrix1;

    // ���� ������ �������
    std::cout << "\n������ �������:\n";
    std::cin >> matrix2;

    int choice;

    do {
        printMenu();
        choice = safeMenuInput();

        switch (choice) {
        case 1:
            showMatrix(matrix1, "������ �������");
            break;

        case 2:
            showMatrix(matrix2, "������ �������");
            break;

        case 3:
            multiplyMatrices(matrix1, matrix2);
            break;

        case 4:
            std::cout << "�����...\n";
            break;

        default:
            // ���� case ������� �� ���������� ��-�� �������� � safeMenuInput
            break;
        }

    } while (choice != 4);

    return 0;
}