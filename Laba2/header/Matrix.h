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
    inline Matrix operator&(const Matrix& rhs) const;
    friend void print(const Matrix& matrix);
    friend void input(Matrix& matrix);
};

void showMatrix(const Matrix& matrix,const std::string& name);
void multiplyMatrices(const Matrix& matrix1,const Matrix& matrix2);
int safeMenuInput();
void printMenu();