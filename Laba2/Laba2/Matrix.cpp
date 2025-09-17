#include "Matrix.h"
#include <iostream>
#include <limits>
#include <string>
#include <sstream>

using namespace std;

// Конструктор
Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    if (rows > 0 && cols > 0) {
        data = new double* [rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new double[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = 0.0;
            }
        }
    }
    else {
        data = nullptr;
    }
}

// Конструктор копирования
Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    if (rows > 0 && cols > 0) {
        data = new double* [rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new double[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    else {
        data = nullptr;
    }
}

// Деструктор
Matrix::~Matrix() {
    if (data != nullptr) {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
}

// Оператор умножения матриц (&)
Matrix Matrix::operator&(const Matrix& other) const {
    if (cols != other.rows) {
        cout << "Ошибка: размеры матриц не совместимы для умножения!\n";
        cout << "Кол-во столбцов первой матрицы (" << cols << ") ";
        cout << "должно равняться кол-ву строк второй матрицы (" << other.rows << ")\n";
        return Matrix(0, 0);
    }

    Matrix result(rows, other.cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            double sum = 0.0;
            for (int k = 0; k < cols; k++) {
                sum += data[i][k] * other.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }

    return result;
}

// Функция для безопасного ввода числа с полной проверкой строки
template<typename T>
T safeInput(const string& prompt) {
    string input;
    T value;

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
            cout << "Ошибка ввода! Пожалуйста, введите корректное число (без букв и символов).\n";
            cin.clear();
        }
        else {
            return value;
        }
    }
}

// Функция для безопасного ввода элемента матрицы
double safeInputElement(const string& prompt, int row, int col) {
    string input;
    double value;

    while (true) {
        cout << "Элемент [" << (row + 1) << "][" << (col + 1) << "]: ";
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
            cout << "Ошибка ввода! Пожалуйста, введите корректное число (например: 5, 3.14, -2).\n";
            cin.clear();
        }
        else {
            return value;
        }
    }
}

// Оператор вывода
ostream& operator<<(ostream& os, const Matrix& matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            os << matrix.data[i][j] << "\t";
        }
        os << endl;
    }
    return os;
}

// Оператор ввода
istream& operator>>(istream& is, Matrix& matrix) {
    // Используем getline для полного контроля над вводом
    string input;

    matrix.rows = safeInput<int>("Введите количество строк: ");
    matrix.cols = safeInput<int>("Введите количество столбцов: ");

    // Освобождаем старую память
    if (matrix.data != nullptr) {
        for (int i = 0; i < matrix.rows; i++) {
            delete[] matrix.data[i];
        }
        delete[] matrix.data;
    }

    // Выделяем новую память
    if (matrix.rows > 0 && matrix.cols > 0) {
        matrix.data = new double* [matrix.rows];
        cout << "Введите элементы матрицы построчно (" << matrix.rows << "x" << matrix.cols << "):\n";

        for (int i = 0; i < matrix.rows; i++) {
            matrix.data[i] = new double[matrix.cols];
            cout << "Строка " << (i + 1) << ":\n";

            for (int j = 0; j < matrix.cols; j++) {
                matrix.data[i][j] = safeInputElement("", i, j);
            }
        }
    }
    else {
        matrix.data = nullptr;
        cout << "Создана пустая матрица (0x0)\n";
    }

    return is;
}