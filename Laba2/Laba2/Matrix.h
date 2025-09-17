#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <string>

class Matrix {
private:
    int rows = 0;
    int cols = 0;
    double** data = nullptr;

    // Вспомогательные методы
    void allocateMemory();
    void copyDataFrom(const Matrix& other) const; // const добавлен
    void freeMemory();

public:
    // Конструкторы
    explicit Matrix(int r = 0, int c = 0);
    Matrix(const Matrix& other);
    ~Matrix();

    // Оператор присваивания
    Matrix& operator=(const Matrix& other);

    // Методы доступа
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    bool isValid() const { return rows > 0 && cols > 0; }

    // Скрытые дружественные функции (только объявления)
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
    friend std::istream& operator>>(std::istream& is, Matrix& matrix);
    friend Matrix operator&(const Matrix& lhs, const Matrix& rhs); // Дружественная функция
};

// Вспомогательные функции
double safeInput(const std::string& prompt);
void showMatrix(const Matrix& matrix, const std::string& name);
void multiplyMatrices(const Matrix& matrix1, const Matrix& matrix2);

#endif