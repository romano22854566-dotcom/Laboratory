#include <iostream>
#include <locale>
#include "Matrix.h"

int main() {
    setlocale(0,"rus");
    Matrix matrix1;
    Matrix matrix2;
    std::cout << "=== ��������� ��� ��������� ������ ===\n";
    std::cout << "������ ������A:\n";
    input(matrix1);
    std::cout << "\n������ ������A:\n";
    input(matrix2);
    int choice;
    do {
        printMenu();
        choice = safeMenuInput();
        switch (choice) {
        case 1:
        showMatrix(matrix1,"������ �������");
        break;
        case 2:
        showMatrix(matrix2,"������ �������");
        break;
        case 3:
        multiplyMatrices(matrix1,matrix2);
        break;
        case 4:
        std::cout << "�����\n";
        break;
        default:
        break;
        }
    } while (choice != 4);
    return 0;
}