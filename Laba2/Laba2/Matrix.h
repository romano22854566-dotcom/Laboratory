#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
private:
    int rows = 0;
    int cols = 0;
    double** data = nullptr;

public:
    // Конструкторы
    explicit Matrix(int r = 0, int c = 0);
    Matrix(const Matrix& other);
    ~Matrix();

    // Оператор присваивания
    Matrix& operator=(const Matrix& other);

    // Оператор умножения матриц
    Matrix operator&(const Matrix& other) const;

    // Методы доступа
    int getRows() const { return rows; }
    int getCols() const { return cols; }

    // Скрытые дружественные функции
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (int i = 0; i < matrix.rows; i++) {
            for (int j = 0; j < matrix.cols; j++) {
                os << matrix.data[i][j] << " ";
            }
            os << "\n";
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Matrix& matrix);
};

#endif