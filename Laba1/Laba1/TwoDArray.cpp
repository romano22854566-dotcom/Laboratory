#include <iostream>
#include <string>
#include <cstdlib>
#include "TwoDArray.h"

using namespace std;

TwoDArray::TwoDArray(int r1, int c1, int r2, int c2) :
    rows1(r1 > 0 ? r1 : 1),
    cols1(c1 > 0 ? c1 : 1),
    rows2(r2 > 0 ? r2 : 1),
    cols2(c2 > 0 ? c2 : 1),
    array1(nullptr),
    array2(nullptr) {
}

TwoDArray::~TwoDArray() {
    if (array1 != nullptr) {
        for (int i = 0; i < rows1; i++) {
            delete[] array1[i];
        }
        delete[] array1;
    }

    if (array2 != nullptr) {
        for (int i = 0; i < rows2; i++) {
            delete[] array2[i];
        }
        delete[] array2;
    }
}

bool TwoDArray::initializeArrays() {
    if (array1 != nullptr || array2 != nullptr) {
        return false;
    }

    array1 = new int* [rows1];
    if (array1 == nullptr) return false;

    for (int i = 0; i < rows1; i++) {
        array1[i] = new int[cols1]();
        if (array1[i] == nullptr) {
            for (int j = 0; j < i; j++) {
                delete[] array1[j];
            }
            delete[] array1;
            array1 = nullptr;
            return false;
        }
    }

    array2 = new int* [rows2];
    if (array2 == nullptr) {
        for (int i = 0; i < rows1; i++) {
            delete[] array1[i];
        }
        delete[] array1;
        array1 = nullptr;
        return false;
    }

    for (int i = 0; i < rows2; i++) {
        array2[i] = new int[cols2]();
        if (array2[i] == nullptr) {
            for (int j = 0; j < i; j++) {
                delete[] array2[j];
            }
            delete[] array2;
            array2 = nullptr;

            for (int j = 0; j < rows1; j++) {
                delete[] array1[j];
            }
            delete[] array1;
            array1 = nullptr;

            return false;
        }
    }

    return true;
}

void TwoDArray::fillArrays() {
    if (!isValid()) {
        cout << "Ошибка: массивы не инициализированы\n";
        return;
    }

    cout << "=== Заполнение первого массива " << rows1 << "x" << cols1 << " ===\n";
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            cout << "Массив 1[" << i << "][" << j << "] = ";
            if (!(cin >> array1[i][j])) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Ошибка ввода! Введите число.\n";
                j--;
            }
        }
    }

    cout << "\n=== Заполнение второго массива " << rows2 << "x" << cols2 << " ===\n";
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            cout << "Массив 2[" << i << "][" << j << "] = ";
            if (!(cin >> array2[i][j])) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Ошибка ввода! Введите число.\n";
                j--;
            }
        }
    }
}

void TwoDArray::showArrays() const {
    if (!isValid()) {
        cout << "Ошибка: массивы не инициализированы\n";
        return;
    }

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

void TwoDArray::showIntersection() const {
    if (!isValid()) {
        cout << "Ошибка: массивы не инициализированы\n";
        return;
    }

    cout << "\n=== ПЕРЕСЕЧЕНИЕ МАССИВОВ ===\n";

    const int maxSize = rows1 * cols1;
    int* temp = new int[maxSize];
    int count = 0;

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            bool foundInSecond = false;

            for (int k = 0; k < rows2 && !foundInSecond; k++) {
                for (int l = 0; l < cols2 && !foundInSecond; l++) {
                    if (array1[i][j] == array2[k][l]) {
                        foundInSecond = true;
                    }
                }
            }

            if (foundInSecond) {
                bool alreadyAdded = false;
                for (int m = 0; m < count; m++) {
                    if (temp[m] == array1[i][j]) {
                        alreadyAdded = true;
                        break;
                    }
                }
                if (!alreadyAdded && count < maxSize) {
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

        const int cols = 3;
        for (int i = 0; i < count; i++) {
            cout << temp[i] << " ";
            if ((i + 1) % cols == 0) cout << endl;
        }
        if (count % cols != 0) cout << endl;
    }

    delete[] temp;
}

void TwoDArray::showUnion() const {
    if (!isValid()) {
        cout << "Ошибка: массивы не инициализированы\n";
        return;
    }

    cout << "\n=== ОБЪЕДИНЕНИЕ МАССИВОВ ===\n";

    const int maxSize = rows1 * cols1 + rows2 * cols2;
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
            if (!found && count < maxSize) {
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
            if (!found && count < maxSize) {
                temp[count] = array2[i][j];
                count++;
            }
        }
    }

    cout << "Объединение (" << count << " элементов):\n";

    const int cols = 3;
    for (int i = 0; i < count; i++) {
        cout << temp[i] << " ";
        if ((i + 1) % cols == 0) cout << endl;
    }
    if (count % cols != 0) cout << endl;

    delete[] temp;
}