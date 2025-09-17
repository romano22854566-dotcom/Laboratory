#include <iostream>
#include "Matrix.h"
#include <locale>
#include <string>
#include <sstream>

using namespace std;

// Функция для безопасного ввода числа в меню
int safeInputMenu(const string& prompt) {
    string input;
    int value;

    while (true) {
        cout << prompt;
        getline(cin, input);

        // Проверяем, что строка не пустая
        if (input.empty()) {
            cout << "Ошибка: ввод не может быть пустым! Попробуйте снова.\n";
            continue;
        }

        stringstream ss(input);
        ss >> value;

        // Проверяем, что все символы были обработаны и нет ошибок
        if (ss.fail() || !ss.eof()) {
            cout << "Ошибка ввода! Пожалуйста, введите число от 1 до 5.\n";
            cin.clear();
        }
        else if (value < 1 || value > 5) {
            cout << "Неверный выбор! Пожалуйста, выберите от 1 до 5.\n";
        }
        else {
            return value;
        }
    }
}

void printMenu() {
    cout << "\n=== МЕНЮ РАБОТЫ С МАТРИЦАМИ ===\n";
    cout << "1. Показать первую матрицу\n";
    cout << "2. Показать вторую матрицу\n";
    cout << "3. Умножить матрицы (оператор &)\n";
    cout << "4. Пересоздать матрицы\n";
    cout << "5. Выход\n";
    cout << "Выберите опцию (1-5): ";
}

void inputMatrix(Matrix& matrix, const string& name) {
    cout << "\n=== ВВОД " << name << " МАТРИЦЫ ===\n";
    cin >> matrix;
    cout << name << " матрица успешно создана!\n";
}

int main() {
    setlocale(0, "rus");
    Matrix matrix1, matrix2, result;

    cout << "=== ПРОГРАММА ДЛЯ РАБОТЫ С МАТРИЦАМИ ===\n";
    cout << "Для умножения матриц количество столбцов первой матрицы\n";
    cout << "должно равняться количеству строк второй матрицы!\n\n";

    // Ввод матриц сразу после запуска
    inputMatrix(matrix1, "ПЕРВОЙ");
    inputMatrix(matrix2, "ВТОРОЙ");

    int choice;

    do {
        printMenu();
        choice = safeInputMenu("");

        switch (choice) {
        case 1:
            cout << "\n=== ПЕРВАЯ МАТРИЦА ===\n";
            if (matrix1.getRows() > 0 && matrix1.getCols() > 0) {
                cout << "Размер: " << matrix1.getRows() << "x" << matrix1.getCols() << endl;
                cout << matrix1;
            }
            else {
                cout << "Матрица не создана!\n";
            }
            break;

        case 2:
            cout << "\n=== ВТОРАЯ МАТРИЦА ===\n";
            if (matrix2.getRows() > 0 && matrix2.getCols() > 0) {
                cout << "Размер: " << matrix2.getRows() << "x" << matrix2.getCols() << endl;
                cout << matrix2;
            }
            else {
                cout << "Матрица не создана!\n";
            }
            break;

        case 3:
            cout << "\n=== УМНОЖЕНИЕ МАТРИЦ ===\n";
            if (matrix1.getRows() > 0 && matrix1.getCols() > 0 &&
                matrix2.getRows() > 0 && matrix2.getCols() > 0) {
                result = matrix1 & matrix2;
                if (result.getRows() > 0) {
                    cout << "Результат умножения (" << result.getRows() << "x" << result.getCols() << "):\n";
                    cout << result;
                }
            }
            else {
                cout << "Обе матрицы должны быть созданы!\n";
            }
            break;

        case 4:
            cout << "\n=== ПЕРЕСОЗДАНИЕ МАТРИЦ ===\n";
            inputMatrix(matrix1, "ПЕРВОЙ");
            inputMatrix(matrix2, "ВТОРОЙ");
            break;

        case 5:
            cout << "Выход из программы...\n";
            break;
        }

    } while (choice != 5);

    return 0;
}