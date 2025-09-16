#include <iostream>
#include "TwoDArray.h"

using namespace std;

TwoDArray::TwoDArray(int r1, int c1, int r2, int c2) :
    rows1(r1), cols1(c1), rows2(r2), cols2(c2) {

    array1 = new int* [rows1];
    for (int i = 0; i < rows1; i++) {
        array1[i] = new int[cols1];
        for (int j = 0; j < cols1; j++) {
            array1[i][j] = 0;
        }
    }

    array2 = new int* [rows2];
    for (int i = 0; i < rows2; i++) {
        array2[i] = new int[cols2];
        for (int j = 0; j < cols2; j++) {
            array2[i][j] = 0;
        }
    }
}

TwoDArray::~TwoDArray() {
    for (int i = 0; i < rows1; i++) {
        delete[] array1[i];
    }
    delete[] array1;

    for (int i = 0; i < rows2; i++) {
        delete[] array2[i];
    }
    delete[] array2;
}

void TwoDArray::fillArrays() {
    cout << "=== Заполнение первого массива " << rows1 << "x" << cols1 << " ===\n";
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            cout << "Массив 1[" << i << "][" << j << "] = ";
            cin >> array1[i][j];
        }
    }

    cout << "\n=== Заполнение второго массива " << rows2 << "x" << cols2 << " ===\n";
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            cout << "Массив 2[" << i << "][" << j << "] = ";
            cin >> array2[i][j];
        }
    }
}

void TwoDArray::showArrays() {
    cout << "\nМассив 1 (" << rows1 << "x" << cols1 << "):\n";
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            cout << array1[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nМассив 2 (" << rows2 << "x" << cols2 << "):\n";
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            cout << array2[i][j] << "\t";
        }
        cout << endl;
    }
}

void TwoDArray::showIntersection() {
    cout << "\n=== ПЕРЕСЕЧЕНИЕ МАССИВОВ ===\n";

    int maxSize = rows1 * cols1;
    int* temp = new int[maxSize];
    int count = 0;

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            bool foundInSecond = false;

            for (int k = 0; k < rows2; k++) {
                for (int l = 0; l < cols2; l++) {
                    if (array1[i][j] == array2[k][l]) {
                        foundInSecond = true;
                        break;
                    }
                }
                if (foundInSecond) break;
            }

            if (foundInSecond) {
                bool alreadyAdded = false;
                for (int m = 0; m < count; m++) {
                    if (temp[m] == array1[i][j]) {
                        alreadyAdded = true;
                        break;
                    }
                }
                if (!alreadyAdded) {
                    temp[count] = array1[i][j];
                    count++;
                }
            }
        }
    }

    if (count == 0) {
        cout << "Пересечение пустое - нет общих элементов\n";
    }
    else {
        cout << "Пересечение (" << count << " элементов):\n";

        int cols = 3;
        int rows = (count + cols - 1) / cols;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int index = i * cols + j;
                if (index < count) {
                    cout << temp[index] << "\t";
                }
            }
            cout << endl;
        }
    }

    delete[] temp;
}

void TwoDArray::showUnion() {
    cout << "\n=== ОБЪЕДИНЕНИЕ МАССИВОВ ===\n";

    int maxSize = rows1 * cols1 + rows2 * cols2;
    int* temp = new int[maxSize];
    int count = 0;

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            bool found = false;
            for (int k = 0; k < count; k++) {
                if (temp[k] == array1[i][j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                temp[count] = array1[i][j];
                count++;
            }
        }
    }

    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            bool found = false;
            for (int k = 0; k < count; k++) {
                if (temp[k] == array2[i][j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                temp[count] = array2[i][j];
                count++;
            }
        }
    }

    cout << "Объединение (" << count << " элементов):\n";

    int cols = 3;
    int rows = (count + cols - 1) / cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int index = i * cols + j;
            if (index < count) {
                cout << temp[index] << "\t";
            }
        }
        cout << endl;
    }

    delete[] temp;
}