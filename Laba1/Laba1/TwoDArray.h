#ifndef TWO_D_ARRAY_H
#define TWO_D_ARRAY_H

class TwoDArray {
private:
    int** array1;
    int** array2;
    int rows1;
    int cols1;
    int rows2;
    int cols2;

    TwoDArray(const TwoDArray&) = delete;
    TwoDArray& operator=(const TwoDArray&) = delete;

public:
    TwoDArray(int r1, int c1, int r2, int c2);
    ~TwoDArray();

    void fillArraysFromKeyboard();
    void getIntersection() const;
    void getUnion() const;
    void printArray(int** arr, int r, int c, const char* name) const;

    int** getArray1() const { return array1; }
    int** getArray2() const { return array2; }
    int getRows1() const { return rows1; }
    int getCols1() const { return cols1; }
    int getRows2() const { return rows2; }
    int getCols2() const { return cols2; }
};

#endif