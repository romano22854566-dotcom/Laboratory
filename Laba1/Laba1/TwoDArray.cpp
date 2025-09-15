#include <iostream>
#include <limits>
#include "TwoDArray.h"

using namespace std;

// Конструктор с разными размерами для двух массивов
TwoDArray::TwoDArray(int r1, int c1, int r2, int c2) : rows1(r1), cols1(c1), rows2(r2), cols2(c2),
array1(nullptr), array2(nullptr) {
    // Проверка валидности размеров
    if (rows1 <= 0 || cols1 <= 0 || rows2 <= 0 || cols2 <= 0) {
        cerr << "Error: Array dimensions must be positive integers" << endl;
        return;
    }

    // Выделяем память для первого массива
    array1 = new int* [rows1];
    for (int i = 0; i < rows1; i++) {
        array1[i] = new int[cols1];
        // Заполняем нулями вручную
        for (int j = 0; j < cols1; j++) {
            array1[i][j] = 0;
        }
    }

    // Выделяем память для второго массива
    array2 = new int* [rows2];
    for (int i = 0; i < rows2; i++) {
        array2[i] = new int[cols2];
        // Заполняем нулями вручную
        for (int j = 0; j < cols2; j++) {
            array2[i][j] = 0;
        }
    }
}

// Деструктор
TwoDArray::~TwoDArray() {
    // Освобождаем память первого массива
    if (array1 != nullptr) {
        for (int i = 0; i < rows1; i++) {
            delete[] array1[i];
        }
        delete[] array1;
    }

    // Освобождаем память второго массива
    if (array2 != nullptr) {
        for (int i = 0; i < rows2; i++) {
            delete[] array2[i];
        }
        delete[] array2;
    }
}

// Функция для заполнения массивов с клавиатуры
void TwoDArray::fillArraysFromKeyboard() {
    if (array1 == nullptr || array2 == nullptr) {
        cerr << "Error: Arrays not properly initialized" << endl;
        return;
    }

    cout << "=== Заполнение первого массива " << rows1 << "x" << cols1 << " ===\n";
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            while (true) {
                cout << "Массив 1[" << i << "][" << j << "] = ";
                if (cin >> array1[i][j]) {
                    break; // Успешный ввод
                }
                else {
                    cout << "Ошибка! Введите целое число.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        }
    }

    cout << "\n=== Заполнение второго массива " << rows2 << "x" << cols2 << " ===\n";
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            while (true) {
                cout << "Массив 2[" << i << "][" << j << "] = ";
                if (cin >> array2[i][j]) {
                    break; // Успешный ввод
                }
                else {
                    cout << "Ошибка! Введите целое число.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        }
    }
}

// Функция для вывода массива
void TwoDArray::printArray(int** arr, int r, int c, const char* name) const {
    if (arr == nullptr) {
        cerr << "Error: Array is null" << endl;
        return;
    }

    cout << name << " (" << r << "x" << c << "):\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}