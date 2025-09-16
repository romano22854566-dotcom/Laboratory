#include <iostream>
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

void TwoDArray::fillArrays() const {
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

bool isElementInArray(int element, const int* array, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return true;
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

    // Создаем временный массив для хранения пересечения
    int maxSize = rows1 * cols1;
    int* intersection = new int[maxSize];
    int intersectionSize = 0;

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            auto current = array1[i][j];

            bool inSecondArray = isElementInMatrix(current, array2, rows2, cols2);
            bool alreadyAdded = isElementInArray(current, intersection, intersectionSize);

            if (inSecondArray && !alreadyAdded) {
                intersection[intersectionSize++] = current;
            }
        }
    }

    if (intersectionSize == 0) {
        cout << "Пересечение пустое - нет общих элементов\n";
    }
    else {
        cout << "Пересечение (" << intersectionSize << " элементов):\n";

        const int cols = 3;
        for (int i = 0; i < intersectionSize; i++) {
            cout << intersection[i] << " ";
            if ((i + 1) % cols == 0) cout << endl;
        }
        if (intersectionSize % cols != 0) cout << endl;
    }

    delete[] intersection;
}

void TwoDArray::showUnion() const {
    if (!isValid()) {
        cout << "Ошибка: массивы не инициализированы\n";
        return;
    }

    cout << "\n=== ОБЪЕДИНЕНИЕ МАССИВОВ ===\n";

    // Создаем временный массив для хранения объединения
    int maxSize = rows1 * cols1 + rows2 * cols2;
    int* unionElements = new int[maxSize];
    int unionSize = 0;

    // Добавляем элементы из первого массива
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            auto current = array1[i][j];
            if (!isElementInArray(current, unionElements, unionSize)) {
                unionElements[unionSize++] = current;
            }
        }
    }

    // Добавляем элементы из второго массива
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            auto current = array2[i][j];
            if (!isElementInArray(current, unionElements, unionSize)) {
                unionElements[unionSize++] = current;
            }
        }
    }

    cout << "Объединение (" << unionSize << " элементов):\n";

    const int cols = 3;
    for (int i = 0; i < unionSize; i++) {
        cout << unionElements[i] << " ";
        if ((i + 1) % cols == 0) cout << endl;
    }
    if (unionSize % cols != 0) cout << endl;

    delete[] unionElements;
}