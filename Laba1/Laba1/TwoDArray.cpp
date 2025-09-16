#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include "TwoDArray.h"

using namespace std;

// Функция для безопасного ввода целого числа
int getSafeInt(const string& prompt) {
    string input;
    int value;

    while (true) {
        cout << prompt;
        getline(cin, input);

        // Проверяем, не пустая ли строка
        if (input.empty()) {
            cout << "Ошибка! Введите число.\n";
            continue;
        }

        // Проверяем каждый символ на цифру или знак
        bool isValid = true;
        bool hasDigit = false;
        for (size_t i = 0; i < input.length(); i++) {
            char c = input[i];
            if (i == 0 && (c == '-' || c == '+')) {
                continue; // Разрешаем знак в начале
            }
            if (!isdigit(c)) {
                isValid = false;
                break;
            }
            hasDigit = true;
        }

        if (!isValid || !hasDigit) {
            cout << "Ошибка! Введите целое число без букв и символов.\n";
            continue;
        }

        // Пробуем преобразовать строку в число
        stringstream ss(input);
        if (ss >> value) {
            // Проверяем, что в строке не осталось лишних символов
            if (ss.eof()) {
                return value;
            }
        }

        cout << "Ошибка! Введите корректное целое число.\n";
    }
}

// Функция для безопасного ввода положительного целого числа
int getSafePositiveInt(const string& prompt) {
    int value;
    while (true) {
        value = getSafeInt(prompt);
        if (value > 0) {
            return value;
        }
        else {
            cout << "Ошибка! Введите положительное число.\n";
        }
    }
}

TwoDArray::TwoDArray(int r1, int c1, int r2, int c2) : rows1(r1), cols1(c1), rows2(r2), cols2(c2) {
    if (rows1 <= 0 || cols1 <= 0 || rows2 <= 0 || cols2 <= 0) {
        cerr << "Error: Array dimensions must be positive integers" << endl;
        array1 = nullptr;
        array2 = nullptr;
        return;
    }

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

void TwoDArray::fillArraysFromKeyboard() {
    if (array1 == nullptr || array2 == nullptr) {
        cerr << "Error: Arrays not properly initialized" << endl;
        return;
    }

    cout << "=== Заполнение первого массива " << rows1 << "x" << cols1 << " ===\n";
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            string prompt = "Массив 1[" + to_string(i) + "][" + to_string(j) + "] = ";
            array1[i][j] = getSafeInt(prompt);
        }
    }

    cout << "\n=== Заполнение второго массива " << rows2 << "x" << cols2 << " ===\n";
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            string prompt = "Массив 2[" + to_string(i) + "][" + to_string(j) + "] = ";
            array2[i][j] = getSafeInt(prompt);
        }
    }
}

void TwoDArray::printArrays() const {
    if (array1 == nullptr || array2 == nullptr) {
        cerr << "Error: Arrays not properly initialized" << endl;
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

void TwoDArray::getIntersection() const {
    if (array1 == nullptr || array2 == nullptr) {
        cerr << "Error: Arrays not properly initialized" << endl;
        return;
    }

    cout << "\n=== ПЕРЕСЕЧЕНИЕ МАССИВОВ ===\n";

    int maxSize = rows1 * cols1;
    int* tempIntersection = new int[maxSize];
    int tempSize = 0;

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            bool foundInArray2 = false;
            for (int k = 0; k < rows2 && !foundInArray2; k++) {
                for (int l = 0; l < cols2 && !foundInArray2; l++) {
                    if (array1[i][j] == array2[k][l]) {
                        foundInArray2 = true;
                    }
                }
            }

            if (foundInArray2) {
                bool alreadyAdded = false;
                for (int m = 0; m < tempSize; m++) {
                    if (tempIntersection[m] == array1[i][j]) {
                        alreadyAdded = true;
                        break;
                    }
                }
                if (!alreadyAdded) {
                    tempIntersection[tempSize] = array1[i][j];
                    tempSize++;
                }
            }
        }
    }

    if (tempSize == 0) {
        cout << "Пересечение пустое - нет общих элементов\n";
        delete[] tempIntersection;
        return;
    }

    int resultCols = 3;
    int resultRows = (tempSize + resultCols - 1) / resultCols;

    cout << "Пересечение (" << tempSize << " уникальных элементов):\n";
    for (int i = 0; i < resultRows; i++) {
        for (int j = 0; j < resultCols; j++) {
            int index = i * resultCols + j;
            if (index < tempSize) {
                cout << tempIntersection[index] << "\t";
            }
        }
        cout << endl;
    }

    delete[] tempIntersection;
}

void TwoDArray::getUnion() const {
    if (array1 == nullptr || array2 == nullptr) {
        cerr << "Error: Arrays not properly initialized" << endl;
        return;
    }

    cout << "\n=== ОБЪЕДИНЕНИЕ МАССИВОВ ===\n";

    int maxSize = rows1 * cols1 + rows2 * cols2;
    int* tempUnion = new int[maxSize];
    int tempSize = 0;

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            bool found = false;
            for (int k = 0; k < tempSize; k++) {
                if (tempUnion[k] == array1[i][j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                tempUnion[tempSize] = array1[i][j];
                tempSize++;
            }
        }
    }

    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            bool found = false;
            for (int k = 0; k < tempSize; k++) {
                if (tempUnion[k] == array2[i][j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                tempUnion[tempSize] = array2[i][j];
                tempSize++;
            }
        }
    }

    int resultCols = 3;
    int resultRows = (tempSize + resultCols - 1) / resultCols;

    cout << "Объединение (" << tempSize << " уникальных элементов):\n";
    for (int i = 0; i < resultRows; i++) {
        for (int j = 0; j < resultCols; j++) {
            int index = i * resultCols + j;
            if (index < tempSize) {
                cout << tempUnion[index] << "\t";
            }
        }
        cout << endl;
    }

    delete[] tempUnion;
}