#include <sstream>
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
    friend std::ostream& operator<<(std::ostream& os,const Matrix& matrix);
    friend std::istream& operator>>(std::istream& is,Matrix& matrix);
    friend Matrix operator&(const Matrix& lhs,const Matrix& rhs);
};
void showMatrix(const Matrix& matrix,const std::string& name);
void multiplyMatrices(const Matrix& matrix1,const Matrix& matrix2);
int safeMenuInput();
void printMenu();



