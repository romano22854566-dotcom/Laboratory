#include <iostream>
#include <vector>
#include <algorithm>
#include "TwoDArray.h"

using namespace std;

TwoDArray::TwoDArray(int r1, int c1, int r2, int c2) :
    rows1(r1 > 0 ? r1 : 1),
    cols1(c1 > 0 ? c1 : 1),
    rows2(r2 > 0 ? r2 : 1),
    cols2(c2 > 0 ? c2 : 1) {
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

bool isElementInArray(int element, const vector<int>& array) {
    // Используем std::ranges::contains если доступен C++23, иначе std::find
#if __cplusplus >= 202002L
    return ranges::contains(array, element);
#else
    return find(array.begin(), array.end(), element) != array.end();
#endif
}

bool isElementInMatrix(int element, int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == element) {
                return true;
            }
        }
    }
    return false;
}

void TwoDArray::showIntersection() const {
    if (!isValid()) {
        cout << "Ошибка: массивы не инициализированы\n";
        return;
    }

    cout << "\n=== ПЕРЕСЕЧЕНИЕ МАССИВОВ ===\n";

    vector<int> intersection;

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            int current = array1[i][j];

            bool inSecondArray = isElementInMatrix(current, array2, rows2, cols2);
            bool alreadyAdded = isElementInArray(current, intersection);

            if (inSecondArray && !alreadyAdded) {
                intersection.push_back(current);
            }
        }
    }

    if (intersection.empty()) {
        cout << "Пересечение пустое - нет общих элементов\n";
    }
    else {
        cout << "Пересечение (" << intersection.size() << " элементов):\n";

        const int cols = 3;
        for (size_t i = 0; i < intersection.size(); i++) {
            cout << intersection[i] << " ";
            if ((i + 1) % cols == 0) cout << endl;
        }
        if (intersection.size() % cols != 0) cout << endl;
    }
}

void TwoDArray::showUnion() const {
    if (!isValid()) {
        cout << "Ошибка: массивы не инициализированы\n";
        return;
    }

    cout << "\n=== ОБЪЕДИНЕНИЕ МАССИВОВ ===\n";

    vector<int> unionElements;

    // Добавляем элементы из первого массива
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            int current = array1[i][j];
            if (!isElementInArray(current, unionElements)) {
                unionElements.push_back(current);
            }
        }
    }

    // Добавляем элементы из второго массива
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            int current = array2[i][j];
            if (!isElementInArray(current, unionElements)) {
                unionElements.push_back(current);
            }
        }
    }

    cout << "Объединение (" << unionElements.size() << " элементов):\n";

    const int cols = 3;
    for (size_t i = 0; i < unionElements.size(); i++) {
        cout << unionElements[i] << " ";
        if ((i + 1) % cols == 0) cout << endl;
    }
    if (unionElements.size() % cols != 0) cout << endl;
}