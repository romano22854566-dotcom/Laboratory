#include <iostream>
#include <string>
#include <cctype>
#include "TwoDArray.h"

using namespace std;
int getSafeNumber(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        cin >> input;
        bool valid = true;
        for (char c : input) {
            if (!isdigit(static_cast<unsigned char>(c))) {
                valid = false;
                break;
            }
        }
        if (valid && !input.empty()) {
            int num = stoi(input);
            if (num > 0) return num;
        }
        cout << "������! ������� �����:";
        cin.clear();
        cin.ignore(1000,'\n');
    }
}

int getMenuChoice() {
    string input;
    while (true) {
        cout << "\n=== ���� ===\n";
        cout << "1.�������� �����������\n";
        cout << "2.�������� �����������\n";
        cout << "3.�������� ��� �������\n";
        cout << "4.����� �� ���������\n";
        cout << "�������� �����:";
        cin >> input;
        if (input.length() == 1 && input[0] >= '1' && input[0] <= '4') {
            return input[0] - '0';
        }
        cout << "������! ������� �� 1 �� 4:\n";
        cin.clear();
        cin.ignore(1000,'\n');
    }
}

bool isElementInMatrix(int element,int** matrix,int rows,int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == element) {
                return true;
            }
        }
    }
    return false;
}

bool isElementInArray(int element,const int* array,int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return true;
        }
    }
    return false;
}

TwoDArray::TwoDArray(int r,int c):
    rows(r > 0 ? r : 1),
    cols(c > 0 ? c : 1) {
}

TwoDArray::~TwoDArray() {
    if (array != nullptr) {
        for (int i = 0; i < rows; i++) {
            delete[] array[i];
        }
        delete[] array;
    }
}

bool TwoDArray::initializeArray() {
    if (array != nullptr) {
        return false;
    }
    array = new int* [rows];
    if (array == nullptr) return false;
    for (int i = 0; i < rows; i++) {
        array[i] = new int[cols]();
        if (array[i] == nullptr) {
            for (int j = 0; j < i; j++) {
                delete[] array[j];
            }
            delete[] array;
            array = nullptr;
            return false;
        }
    }
    return true;
}

void TwoDArray::fillArray() const {
    if (!isValid()) {
        cout << "������: ������ �� ���������������\n";
        return;
    }
    cout << "=== ���������� ������� " << rows << "x" << cols << " ===\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "������ [" << i << "][" << j << "] = ";
            if (!(cin >> array[i][j])) {
                cin.clear();
                cin.ignore(1000,'\n');
                cout << "������ �����! ������� �����.\n";
                j--;
            }
        }
    }
}

void TwoDArray::showArray() const {
    if (!isValid()) {
        cout << "������: ������ �� ���������������\n";
        return;
    }
    cout << "\n������ (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
}

void showIntersection(const TwoDArray& arr1,const TwoDArray& arr2) {
    if (!arr1.isValid() || !arr2.isValid()) {
        cout << "������: ������� �� ����������������\n";
        return;
    }
    cout << "\n=== ����������� �������� ===\n";
    int maxSize = arr1.getRows() * arr1.getCols() + arr2.getRows() * arr2.getCols();
    auto intersection = new int[maxSize];
    int intersectionSize = 0;
    int** array1 = arr1.getArray();
    int** array2 = arr2.getArray();
    for (int i = 0; i < arr1.getRows(); i++) {
        for (int j = 0; j < arr1.getCols(); j++) {
            auto current = array1[i][j];
            bool inSecondArray = isElementInMatrix(current,array2,arr2.getRows(),arr2.getCols());
            bool alreadyAdded = isElementInArray(current,intersection,intersectionSize);
            if (inSecondArray && !alreadyAdded) {
                intersection[intersectionSize++] = current;
            }
        }
    }
    if (intersectionSize == 0) {
        cout << "����������� ������ - ��� ����� ���������\n";
    }
    else {

        cout << "����������� (" << intersectionSize << " ���������):\n";
        int cols = arr1.getCols() + arr2.getCols();

        for (int i = 0; i < intersectionSize; i++) {
            cout << intersection[i] << " ";
            if ((i + 1) % cols == 0) cout << endl;
        }
        if (intersectionSize % cols != 0) cout << endl;
    }
    delete[] intersection;
}

void showUnion(const TwoDArray& arr1,const TwoDArray& arr2) {
    if (!arr1.isValid() || !arr2.isValid()) {
        cout << "������: ������� �� ����������������\n";
        return;
    }
    cout << "\n=== ����������� �������� ===\n";
    int maxSize = arr1.getRows() * arr1.getCols() + arr2.getRows() * arr2.getCols();
    auto unionElements = new int[maxSize];
    int unionSize = 0;
    int** array1 = arr1.getArray();
    int** array2 = arr2.getArray();
    for (int i = 0; i < arr1.getRows(); i++) {
        for (int j = 0; j < arr1.getCols(); j++) {
            auto current = array1[i][j];
            if (!isElementInArray(current,unionElements,unionSize)) {
                unionElements[unionSize++] = current;
            }
        }
    }
    for (int i = 0; i < arr2.getRows(); i++) {
        for (int j = 0; j < arr2.getCols(); j++) {
            auto current = array2[i][j];
            if (!isElementInArray(current,unionElements,unionSize)) {
                unionElements[unionSize++] = current;
            }
        }
    }
    cout << "����������� (" << unionSize << " ���������):\n";
    int cols = arr1.getCols() + arr2.getCols();

    for (int i = 0; i < unionSize; i++) {
        cout << unionElements[i] << " ";
        if ((i + 1) % cols == 0) cout << endl;
    }
    if (unionSize % cols != 0) cout << endl;
    delete[] unionElements;
}

void showBothArrays(const TwoDArray& arr1,const TwoDArray& arr2) {
    if (!arr1.isValid() || !arr2.isValid()) {
        cout << "������: ������� �� ����������������\n";
        return;
    }
    cout << "\n=== ��� ������� ===\n";
    cout << "������ ������:\n";
    arr1.showArray();
    cout << "\n������ ������:\n";
    arr2.showArray();
}