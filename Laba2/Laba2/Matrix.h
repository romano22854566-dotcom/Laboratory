#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <string>

class Matrix {
private:
    int rows = 0;
    int cols = 0;
    double** data = nullptr;

    // ��������������� ������
    void allocateMemory();
    void copyDataFrom(const Matrix& other);

public:
    // ������������
    explicit Matrix(int r = 0, int c = 0);
    Matrix(const Matrix& other);
    ~Matrix();

    // �������� ������������
    Matrix& operator=(const Matrix& other);

    // �������� ��������� ������
    Matrix operator&(const Matrix& other) const;

    // ������ �������
    int getRows() const { return rows; }
    int getCols() const { return cols; }

    // ������� ������������� �������
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j) {
                os << matrix.data[i][j] << " ";
            }
            os << "\n";
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Matrix& matrix);
};

// ��������������� �������
double safeInput(const std::string& prompt);
void showMatrix(const Matrix& matrix, const std::string& name);
void multiplyMatrices(const Matrix& matrix1, const Matrix& matrix2);

#endif