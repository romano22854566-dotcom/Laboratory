#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <string>
#include <sstream>

class Matrix {
private:
    int rows = 0;
    int cols = 0;
    double** data = nullptr;

    // Вспомогательные методы
    void allocateMemory();
    void copyDataFrom(const Matrix& other) const;
    void freeMemory();

    // Вспомогательная функция для безопасного ввода
    static double safeInput(const std::string& prompt) {
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
                std::cout << "Ошибка! Введите только число: ";
            }
            else {
                return value;
            }
        }
    }

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

    // Скрытые дружественные функции (реализация внутри класса)
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j) {
                os << matrix.data[i][j] << " ";
            }
            os << "\n";
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Matrix& matrix) {
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

        return is;
    }

    friend Matrix operator&(const Matrix& lhs, const Matrix& rhs) {
        if (lhs.cols != rhs.rows) {
            std::cout << "Ошибка: нельзя умножить матрицы таких размеров!\n";
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
};

// Вспомогательные функции
void showMatrix(const Matrix& matrix, const std::string& name);
void multiplyMatrices(const Matrix& matrix1, const Matrix& matrix2);

#endif