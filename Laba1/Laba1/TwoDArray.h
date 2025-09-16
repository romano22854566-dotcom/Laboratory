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

public:
    TwoDArray(int r1, int c1, int r2, int c2);
    ~TwoDArray();

    void fillArrays();
    void showIntersection();
    void showUnion();
    void showArrays();
};

#endif