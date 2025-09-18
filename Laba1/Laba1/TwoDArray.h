class TwoDArray {
private:
    int rows1;
    int cols1;
    int rows2;
    int cols2;
    int** array1 = nullptr;
    int** array2 = nullptr;
    TwoDArray(const TwoDArray&);
    TwoDArray& operator=(const TwoDArray&);
public:
    TwoDArray(int r1,int c1,int r2,int c2);
    ~TwoDArray();
    bool initializeArrays();
    void fillArrays() const;
    void showIntersection() const;
    void showUnion() const;
    void showArrays() const;
    bool isValid() const { return array1 != nullptr && array2 != nullptr; }
};
int getSafeNumber(const std::string& prompt);
int getMenuChoice();
bool isElementInMatrix(int element,int** matrix,int rows,int cols);
bool isElementInArray(int element,const int* array,int size);
