#include <iostream>
#include "Matrix.h"
#include <string>
#include <sstream>
#include <locale>
void printMenu() {
    std::cout << "\n=== МЕНЮ ===\n";
    std::cout << "1. Показать первую матрицу\n";
    std::cout << "2. Показать вторую матрицу\n";
    std::cout << "3. Умножить матрицы\n";
    std::cout << "4. Выход\n";
}

// Функция для безопасного ввода выбора меню
int safeMenuInput() {
    std::string input;
    int choice;

    while (true) {
        std::cout << "Выберите: ";
        std::getline(std::cin, input);

        if (input.empty()) {
            continue;
        }

        std::stringstream ss(input);
        ss >> choice;

        if (ss.fail() || !ss.eof() || choice < 1 || choice > 4) {
            std::cout << "Ошибка! Введите число от 1 до 4\n";
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
        std::cout << "Матрица не создана!\n";
    }
}

void multiplyMatrices(const Matrix& matrix1, const Matrix& matrix2) {
    std::cout << "\nУмножение матриц:\n";
    if (matrix1.getRows() > 0 && matrix1.getCols() > 0 &&
        matrix2.getRows() > 0 && matrix2.getCols() > 0) {
        Matrix result = matrix1 & matrix2;
        if (result.getRows() > 0) {
            std::cout << "Результат:\n" << result;
        }
    }
    else {
        std::cout << "Обе матрицы должны быть созданы!\n";
    }
}

int main() {
    setlocale(0, "rus");
    Matrix matrix1;
    Matrix matrix2;

    std::cout << "=== УМНОЖЕНИЕ МАТРИЦ ===\n\n";

    // Ввод первой матрицы
    std::cout << "ПЕРВАЯ МАТРИЦА:\n";
    std::cin >> matrix1;

    // Ввод второй матрицы
    std::cout << "\nВТОРАЯ МАТРИЦА:\n";
    std::cin >> matrix2;

    int choice;

    do {
        printMenu();
        choice = safeMenuInput();

        switch (choice) {
        case 1:
            showMatrix(matrix1, "Первая матрица");
            break;

        case 2:
            showMatrix(matrix2, "Вторая матрица");
            break;

        case 3:
            multiplyMatrices(matrix1, matrix2);
            break;

        case 4:
            std::cout << "Выход...\n";
            break;

        default:
            // Этот case никогда не выполнится из-за проверки в safeMenuInput
            break;
        }

    } while (choice != 4);

    return 0;
}