#include "Matrix.h"
#include <iostream>
#include <sstream> 
#include <string>

double Matrix::safeInput(const std::string& prompt) {
    std::string input;
    double value;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin,input);
        if (input.empty()) {
            continue;
        }
        std::stringstream ss(input);
        ss >> value;
        if (ss.fail() || !ss.eof()) {
            std::cout << "Ошибка! Введите только число.\n";
        }
        else {
            return value;
        }
    }
}

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

void Matrix::freeMemory() {
    if (data != nullptr) {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
}

void Matrix::copyDataFrom(const Matrix& other) const {
    if (rows > 0 && cols > 0) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }
}

Matrix::Matrix(int r,int c): rows(r),cols(c) {
    allocateMemory();
}

Matrix::Matrix(const Matrix& other): rows(other.rows),cols(other.cols) {
    allocateMemory();
    copyDataFrom(other);
}

Matrix::~Matrix() {
    freeMemory();
}

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

int Matrix::getRows() const {
    return rows;
}

int Matrix::getCols() const {
    return cols;
}

bool Matrix::isValid() const {
    return rows > 0 && cols > 0;
}

void print(const Matrix& matrix) {
    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.cols; ++j) {
            std::cout << matrix.data[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void input(Matrix& matrix) {
    matrix.freeMemory();
    matrix.rows = static_cast<int>(Matrix::safeInput("Введите количество строк: "));
    matrix.cols = static_cast<int>(Matrix::safeInput("Введите количество столбцов: "));
    if (matrix.rows > 0 && matrix.cols > 0) {
        matrix.allocateMemory();
        std::cout << "Введите элементы матрицы:\n";
        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j) {
                std::cout << "Элемент [" << (i + 1) << "][" << (j + 1) << "]: ";
                matrix.data[i][j] = Matrix::safeInput("");
            }
        }
    }
}

void showMatrix(const Matrix& matrix,const std::string& name) {
    std::cout << "\n" << name << ":\n";
    if (matrix.isValid()) {
        print(matrix);
    }
    else {
        std::cout << "Матрица не создана!\n";
    }
}

Matrix multiplyMatrices(const Matrix& matrix1,const Matrix& matrix2) {
    if (matrix1.isValid() && matrix2.isValid()) {
        return matrix1 & matrix2;
    }
    else {
        std::cout << "Ошибка!\n";
        return Matrix(0,0);
    }
}

void showMultiplyMatrices(const Matrix& matrix1,const Matrix& matrix2) {
    std::cout << "\nУмножение матриц:\n";
    Matrix result = multiplyMatrices(matrix1,matrix2);
    if (result.isValid()) {
        std::cout << "Результат:\n";
        print(result);
    }
}

int safeMenuInput() {
    std::string input;
    int choice;
    while (true) {
        std::cout << "Выберите: ";
        std::getline(std::cin,input);
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

void printMenu() {
    std::cout << "\n=== МЕНЮ ===\n";
    std::cout << "1. Показать первую матрицу\n";
    std::cout << "2. Показать вторую матрицу\n";
    std::cout << "3. Умножить матрицы\n";
    std::cout << "4. Выйти из программы.\n";
}