#include "Matrix.h"
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

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

// ������������ ������
void Matrix::freeMemory() {
    if (data != nullptr) {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
}

// ����������� ������ �� ������ ������� (����������� �����)
void Matrix::copyDataFrom(const Matrix& other) const {
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
    freeMemory();
}

// �������� ������������
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

// �������� ������
std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.cols; ++j) {
            os << matrix.data[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}

// �������� �����
std::istream& operator>>(std::istream& is, Matrix& matrix) {
    matrix.freeMemory();

    matrix.rows = static_cast<int>(safeInput("������� ���������� �����: "));
    matrix.cols = static_cast<int>(safeInput("������� ���������� ��������: "));

    if (matrix.rows > 0 && matrix.cols > 0) {
        matrix.allocateMemory();
        std::cout << "������� �������� �������:\n";

        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j) {
                std::cout << "������� [" << (i + 1) << "][" << (j + 1) << "]: ";
                matrix.data[i][j] = safeInput("");
            }
        }
    }

    return is;
}

// �������� ��������� ������
Matrix operator&(const Matrix& lhs, const Matrix& rhs) {
    if (lhs.cols != rhs.rows) {
        std::cout << "������: ������ �������� ������� ����� ��������!\n";
        return Matrix(0, 0);
    }

    Matrix result(lhs.rows, rhs.cols);

    for (int i = 0; i < lhs.rows; ++i) {
        for (int j = 0; j < rhs.cols; ++j) {
            double sum = 0.0;
            for (int k = 0; k < lhs.cols; ++k) {
                sum += lhs.data[i][k] * rhs.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }

    return result;
}

// ������� ��� ������ �������
void showMatrix(const Matrix& matrix, const std::string& name) {
    std::cout << "\n" << name << ":\n";
    if (matrix.isValid()) {
        std::cout << matrix;
    }
    else {
        std::cout << "������� �� �������!\n";
    }
}

// ������� ��� ��������� ������
void multiplyMatrices(const Matrix& matrix1, const Matrix& matrix2) {
    std::cout << "\n��������� ������:\n";
    if (matrix1.isValid() && matrix2.isValid()) {
        Matrix result = matrix1 & matrix2;
        if (result.isValid()) {
            std::cout << "���������:\n" << result;
        }
    }
    else {
        std::cout << "��� ������� ������ ���� �������!\n";
    }
}