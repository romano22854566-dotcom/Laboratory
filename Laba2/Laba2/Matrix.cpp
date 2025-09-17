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

        if (input.empty()) {
            continue;
        }

        std::stringstream ss(input);
        ss >> value;

        if (ss.fail() || !ss.eof()) {
            std::cout << "Ошибка! Введите только число: ";
        }
        else {
            return value;
        }
    }
}

// Выделение памяти для матрицы
void Matrix::allocateMemory() {
    if (rows > 0 && cols > 0) {
        data = new double* [rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new double[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = 0.0;
            }
        }
    }
}

// Освобождение памяти
void Matrix::freeMemory() {
    if (data != nullptr) {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
}

// Копирование данных из другой матрицы
void Matrix::copyDataFrom(const Matrix& other) {
    if (rows > 0 && cols > 0) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }
}

// Конструктор
Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    allocateMemory();
}

// Конструктор копирования
Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    allocateMemory();
    copyDataFrom(other);
}

// Деструктор
Matrix::~Matrix() {
    freeMemory();
}

// Оператор присваивания
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        freeMemory();

        rows = other.rows;
        cols = other.cols;

        allocateMemory();
        copyDataFrom(other);
    }
    return *this;
}

// Оператор умножения матриц (скрытый друг)
Matrix Matrix::operator&(const Matrix& other) const {
    if (cols != other.rows) {
        std::cout << "Ошибка: нельзя умножить матрицы таких размеров!\n";
        return Matrix(0, 0);
    }

    Matrix result(rows, other.cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            double sum = 0.0;
            for (int k = 0; k < cols; ++k) {
                sum += data[i][k] * other.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }

    return result;
}

// Оператор ввода (скрытый друг)
std::istream& operator>>(std::istream& is, Matrix& matrix) {
    matrix.freeMemory();

    matrix.rows = static_cast<int>(safeInput("Введите количество строк: "));
    matrix.cols = static_cast<int>(safeInput("Введите количество столбцов: "));

    if (matrix.rows > 0 && matrix.cols > 0) {
        matrix.allocateMemory();
        std::cout << "Введите элементы матрицы:\n";

        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j) {
                std::cout << "Элемент [" << (i + 1) << "][" << (j + 1) << "]: ";
                matrix.data[i][j] = safeInput("");
            }
        }
    }

    return is;
}

// Функция для показа матрицы
void showMatrix(const Matrix& matrix, const std::string& name) {
    std::cout << "\n" << name << ":\n";
    if (matrix.isValid()) {
        std::cout << matrix;
    }
    else {
        std::cout << "Матрица не создана!\n";
    }
}

// Функция для умножения матриц
void multiplyMatrices(const Matrix& matrix1, const Matrix& matrix2) {
    std::cout << "\nУмножение матриц:\n";
    if (matrix1.isValid() && matrix2.isValid()) {
        Matrix result = matrix1 & matrix2;
        if (result.isValid()) {
            std::cout << "Результат:\n" << result;
        }
    }
    else {
        std::cout << "Обе матрицы должны быть созданы!\n";
    }
}