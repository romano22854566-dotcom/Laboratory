#include "Matrix.h"
#include <iostream>
#include <string>
#include <sstream>

// Функция для безопасного ввода числа
double safeInput(const std::string& prompt) {
    std::string input;
    double value;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        // Пропускаем пустые строки
        if (input.empty()) {
            continue;
        }

        std::stringstream ss(input);
        ss >> value;

        // Проверяем, что ввод корректен и нет лишних символов
        if (ss.fail() || !ss.eof()) {
            std::cout << "Ошибка! Введите только число: ";
        }
        else {
            return value;
        }
    }
}

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

// Вспомогательная функция для освобождения памяти
void freeMatrixMemory(double** data, int rows) {
    if (data != nullptr) {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
}

// Вспомогательная функция для копирования матрицы
void copyMatrixData(double** dest, double** src, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dest[i][j] = src[i][j];
        }
    }
}

// Оператор присваивания
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        // Освобождаем старую память
        freeMatrixMemory(data, rows);

        // Копируем новые данные
        rows = other.rows;
        cols = other.cols;

        if (rows > 0 && cols > 0) {
            data = new double* [rows];
            for (int i = 0; i < rows; i++) {
                data[i] = new double[cols];
            }
            copyMatrixData(data, other.data, rows, cols);
        }
        else {
            data = nullptr;
        }
    }
    return *this;
}

// Оператор умножения матриц
Matrix Matrix::operator&(const Matrix& other) const {
    if (cols != other.rows) {
        std::cout << "Ошибка: нельзя умножить матрицы таких размеров!\n";
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

// Оператор ввода
std::istream& operator>>(std::istream& is, Matrix& matrix) {
    // Освобождаем старую память
    freeMatrixMemory(matrix.data, matrix.rows);

    matrix.rows = static_cast<int>(safeInput("Введите количество строк: "));
    matrix.cols = static_cast<int>(safeInput("Введите количество столбцов: "));

    if (matrix.rows > 0 && matrix.cols > 0) {
        matrix.data = new double* [matrix.rows];
        std::cout << "Введите элементы матрицы:\n";

        for (int i = 0; i < matrix.rows; i++) {
            matrix.data[i] = new double[matrix.cols];
            for (int j = 0; j < matrix.cols; j++) {
                std::string prompt = "Элемент [" + std::to_string(i + 1) + "][" + std::to_string(j + 1) + "]: ";
                matrix.data[i][j] = safeInput(prompt);
            }
        }
    }
    else {
        matrix.data = nullptr;
    }

    return is;
}