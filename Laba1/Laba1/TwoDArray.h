#ifndef TWO_D_ARRAY_H
#define TWO_D_ARRAY_H

#include <vector>
#include <set>
#include <string>

class TwoDArray {
private:
    int** data;
    int rows;
    int cols;

public:
    TwoDArray(int r, int c);
    ~TwoDArray();

    // ������ ����������� � ������������ ��� ��������� ������� � �������
    TwoDArray(const TwoDArray&) = delete;
    TwoDArray& operator=(const TwoDArray&) = delete;

    void fillArray();
    void printArray(const std::string& name) const;
    std::set<int> getUniqueElements() const;

    // �������
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    int getElement(int i, int j) const;
    void setElement(int i, int j, int value);

    // ����������� ������ ��� �������� � �����������
    static std::vector<int> getIntersection(const TwoDArray& arr1, const TwoDArray& arr2);
    static std::vector<int> getUnion(const TwoDArray& arr1, const TwoDArray& arr2);
};

// ��������������� �������
void printVector(const std::vector<int>& vec, const std::string& name);
int getValidatedInt(const std::string& prompt);

#endif
