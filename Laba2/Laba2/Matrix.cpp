#include "Matrix.h"
#include <iostream>
#include <limits>
#include <string>
#include <sstream>

using namespace std;

// �����������
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

// ����������� �����������
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

// ����������
Matrix::~Matrix() {
    if (data != nullptr) {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
}

// �������� ��������� ������ (&)
Matrix Matrix::operator&(const Matrix& other) const {
    if (cols != other.rows) {
        cout << "������: ������� ������ �� ���������� ��� ���������!\n";
        cout << "���-�� �������� ������ ������� (" << cols << ") ";
        cout << "������ ��������� ���-�� ����� ������ ������� (" << other.rows << ")\n";
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

// ������� ��� ����������� ����� ����� � ������ ��������� ������
template<typename T>
T safeInput(const string& prompt) {
    string input;
    T value;

    while (true) {
        cout << prompt;
        getline(cin, input);

        // ���������, ��� ������ �� ������
        if (input.empty()) {
            cout << "������: ���� �� ����� ���� ������! ���������� �����.\n";
            continue;
        }

        stringstream ss(input);
        ss >> value;

        // ���������, ��� ��� ������� ���� ���������� � ��� ������
        if (ss.fail() || !ss.eof()) {
            cout << "������ �����! ����������, ������� ���������� ����� (��� ���� � ��������).\n";
            cin.clear();
        }
        else {
            return value;
        }
    }
}

// ������� ��� ����������� ����� �������� �������
double safeInputElement(const string& prompt, int row, int col) {
    string input;
    double value;

    while (true) {
        cout << "������� [" << (row + 1) << "][" << (col + 1) << "]: ";
        getline(cin, input);

        // ���������, ��� ������ �� ������
        if (input.empty()) {
            cout << "������: ���� �� ����� ���� ������! ���������� �����.\n";
            continue;
        }

        stringstream ss(input);
        ss >> value;

        // ���������, ��� ��� ������� ���� ���������� � ��� ������
        if (ss.fail() || !ss.eof()) {
            cout << "������ �����! ����������, ������� ���������� ����� (��������: 5, 3.14, -2).\n";
            cin.clear();
        }
        else {
            return value;
        }
    }
}

// �������� ������
ostream& operator<<(ostream& os, const Matrix& matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            os << matrix.data[i][j] << "\t";
        }
        os << endl;
    }
    return os;
}

// �������� �����
istream& operator>>(istream& is, Matrix& matrix) {
    // ���������� getline ��� ������� �������� ��� ������
    string input;

    matrix.rows = safeInput<int>("������� ���������� �����: ");
    matrix.cols = safeInput<int>("������� ���������� ��������: ");

    // ����������� ������ ������
    if (matrix.data != nullptr) {
        for (int i = 0; i < matrix.rows; i++) {
            delete[] matrix.data[i];
        }
        delete[] matrix.data;
    }

    // �������� ����� ������
    if (matrix.rows > 0 && matrix.cols > 0) {
        matrix.data = new double* [matrix.rows];
        cout << "������� �������� ������� ��������� (" << matrix.rows << "x" << matrix.cols << "):\n";

        for (int i = 0; i < matrix.rows; i++) {
            matrix.data[i] = new double[matrix.cols];
            cout << "������ " << (i + 1) << ":\n";

            for (int j = 0; j < matrix.cols; j++) {
                matrix.data[i][j] = safeInputElement("", i, j);
            }
        }
    }
    else {
        matrix.data = nullptr;
        cout << "������� ������ ������� (0x0)\n";
    }

    return is;
}