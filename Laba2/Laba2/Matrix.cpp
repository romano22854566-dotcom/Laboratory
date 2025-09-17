#include "Matrix.h"
#include <iostream>

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
void Matrix::copyDataFrom(const Matrix& other) const {
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