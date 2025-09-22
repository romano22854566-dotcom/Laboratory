#ifndef TWO_D_ARRAY_H
#define TWO_D_ARRAY_H

class TwoDArray {
private:
    int rows;
    int cols;
    int** array = nullptr;
    TwoDArray(const TwoDArray&);
    TwoDArray& operator=(const TwoDArray&);
public:
    TwoDArray(int r,int c);
    ~TwoDArray();
    bool initializeArray();
    void fillArray() const;
    void showArray() const;
    int** getArray() const { return array; }
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    bool isValid() const { return array != nullptr; }
};
int getSafeNumber(const std::string& prompt);
int getMenuChoice();
bool isElementInMatrix(int element,int** matrix,int rows,int cols);
bool isElementInArray(int element,const int* array,int size);
void showIntersection(const TwoDArray& arr1,const TwoDArray& arr2);
void showUnion(const TwoDArray& arr1,const TwoDArray& arr2);
void showBothArrays(const TwoDArray& arr1,const TwoDArray& arr2);

#endif