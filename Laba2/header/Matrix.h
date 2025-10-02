#pragma once
#include <iostream>
#include <string> 

class Matrix {
private:
    int rows = 0;
    int cols = 0;
    double** data = nullptr;
    void allocateMemory();
    void copyDataFrom(const Matrix& other) const;
    void freeMemory();
    static double safeInput(const std::string& prompt);
public:
    explicit Matrix(int r = 0,int c = 0);
    Matrix(const Matrix& other);
    ~Matrix();
    Matrix& operator=(const Matrix& other);
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    bool isValid() const { return rows > 0 && cols > 0; }
    friend Matrix operator&(const Matrix& lhs,const Matrix& rhs) {
        if (lhs.cols != rhs.rows) {
            std::cout << "Ошибка: нельзя умножить матрицы таких размеров!\n";
            return Matrix(0,0);
        }
        Matrix result(lhs.rows,rhs.cols);
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

    friend void print(const Matrix& matrix);
    friend void input(Matrix& matrix);
};

void showMatrix(const Matrix& matrix,const std::string& name);
void multiplyMatrices(const Matrix& matrix1,const Matrix& matrix2);
int safeMenuInput();
void printMenu();