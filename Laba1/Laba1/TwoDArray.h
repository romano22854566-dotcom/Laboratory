#ifndef TWO_D_ARRAY_H
#define TWO_D_ARRAY_H

class TwoDArray {
private:
    int** array1;
    int** array2;
    int rows1, cols1; // размеры первого массива
    int rows2, cols2; // размеры второго массива

public:
    TwoDArray(int r1, int c1, int r2, int c2);
    ~TwoDArray();

    void fillArraysFromKeyboard();
    void getIntersection();
    void getUnion();
    void printArray(int** arr, int r, int c, const char* name);

    int** getArray1();
    int** getArray2();
    int getRows1() { return rows1; }
    int getCols1() { return cols1; }
    int getRows2() { return rows2; }
    int getCols2() { return cols2; }
};

#endif