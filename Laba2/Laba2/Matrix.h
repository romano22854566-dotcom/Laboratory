#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
private:
    int rows;
    int cols;
    double** data;

public:
    // Конструкторы
    Matrix(int r = 0, int c = 0);
    Matrix(const Matrix& other);
    ~Matrix();

    // Оператор присваивания
    Matrix& operator=(const Matrix& other);

    // Оператор умножения матриц
    Matrix operator&(const Matrix& other) const;

    // Методы доступа
    int getRows() const { return rows; }
    int getCols() const { return cols; }

    // Дружественные функции
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
    friend std::istream& operator>>(std::istream& is, Matrix& matrix);
};

#endif