#include "Matrix.h"
#include <iostream>
#include <string>
#include <sstream>

// ������� ��� ����������� ����� �����
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
            std::cout << "������! ������� ������ �����: ";
        }
        else {
            return value;
        }
    }
}

// ��������������� ������� ��� ������������ ������
void freeMatrixMemory(double** data, int rows) {
    if (data != nullptr) {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
}

// ��������� ������ ��� �������
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

// ����������� ������ �� ������ �������
void Matrix::copyDataFrom(const Matrix& other) {
    if (rows > 0 && cols > 0) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }
}

// �����������
Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    allocateMemory();
}

// ����������� �����������
Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    allocateMemory();
    copyDataFrom(other);
}

// ����������
Matrix::~Matrix() {
    freeMatrixMemory(data, rows);
}

// �������� ������������
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        freeMatrixMemory(data, rows);

        rows = other.rows;
        cols = other.cols;

        allocateMemory();
        copyDataFrom(other);
    }
    return *this;
}

// �������� ��������� ������
Matrix Matrix::operator&(const Matrix& other) const {
    if (cols != other.rows) {
        std::cout << "������: ������ �������� ������� ����� ��������!\n";
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

// �������� �����
std::istream& operator>>(std::istream& is, Matrix& matrix) {
    freeMatrixMemory(matrix.data, matrix.rows);

    matrix.rows = static_cast<int>(safeInput("������� ���������� �����: "));
    matrix.cols = static_cast<int>(safeInput("������� ���������� ��������: "));

    if (matrix.rows > 0 && matrix.cols > 0) {
        matrix.allocateMemory();
        std::cout << "������� �������� �������:\n";

        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j) {
                std::string prompt = "������� [" + std::to_string(i + 1) + "][" + std::to_string(j + 1) + "]: ";
                matrix.data[i][j] = safeInput(prompt);
            }
        }
    }

    return is;
}

// ������� ��� ������ �������
void showMatrix(const Matrix& matrix, const std::string& name) {
    std::cout << "\n" << name << ":\n";
    if (matrix.getRows() > 0 && matrix.getCols() > 0) {
        std::cout << matrix;
    }
    else {
        std::cout << "������� �� �������!\n";
    }
}

// ������� ��� ��������� ������
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