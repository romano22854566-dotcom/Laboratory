#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
private:
    int rows;
    int cols;
    double** data;

public:
    // ������������
    Matrix(int r = 0, int c = 0);
    Matrix(const Matrix& other); // ����������� �����������
    ~Matrix();

    // ���������
    Matrix operator&(const Matrix& other) const; // ������������ ������

    // ������ �������
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    double getElement(int i, int j) const { return data[i][j]; }
    void setElement(int i, int j, double value) { data[i][j] = value; }

    // ������������� ������� ��� �����/������
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
    friend std::istream& operator>>(std::istream& is, Matrix& matrix);
};

#endif