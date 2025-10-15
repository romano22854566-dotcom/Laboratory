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
            std::cout << "������! ������� ������ �����.\n";
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
    matrix.rows = static_cast<int>(Matrix::safeInput("������� ���������� �����: "));
    matrix.cols = static_cast<int>(Matrix::safeInput("������� ���������� ��������: "));
    if (matrix.rows > 0 && matrix.cols > 0) {
        matrix.allocateMemory();
        std::cout << "������� �������� �������:\n";
        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j) {
                std::cout << "������� [" << (i + 1) << "][" << (j + 1) << "]: ";
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
        std::cout << "������� �� �������!\n";
    }
}

Matrix multiplyMatrices(const Matrix& matrix1,const Matrix& matrix2) {
    if (matrix1.isValid() && matrix2.isValid()) {
        return matrix1 & matrix2;
    }
    else {
        std::cout << "������!\n";
        return Matrix(0,0);
    }
}

void showMultiplyMatrices(const Matrix& matrix1,const Matrix& matrix2) {
    std::cout << "\n��������� ������:\n";
    Matrix result = multiplyMatrices(matrix1,matrix2);
    if (result.isValid()) {
        std::cout << "���������:\n";
        print(result);
    }
}

int safeMenuInput() {
    std::string input;
    int choice;
    while (true) {
        std::cout << "��������: ";
        std::getline(std::cin,input);
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

void printMenu() {
    std::cout << "\n=== ���� ===\n";
    std::cout << "1. �������� ������ �������\n";
    std::cout << "2. �������� ������ �������\n";
    std::cout << "3. �������� �������\n";
    std::cout << "4. ����� �� ���������.\n";
}