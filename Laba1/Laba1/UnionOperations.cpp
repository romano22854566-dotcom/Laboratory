#include <iostream>
#include "TwoDArray.h"

using namespace std;

// Функция для получения объединения
void TwoDArray::getUnion() {
    cout << "\n=== ОБЪЕДИНЕНИЕ МАССИВОВ ===\n";

    // Максимально возможный размер объединения
    int maxSize = rows1 * cols1 + rows2 * cols2;
    int* unionArray = new int[maxSize];
    int unionSize = 0;

    // Добавляем все элементы из первого массива
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            bool found = false;
            // Проверяем, нет ли уже такого элемента
            for (int k = 0; k < unionSize; k++) {
                if (unionArray[k] == array1[i][j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                unionArray[unionSize++] = array1[i][j];
            }
        }
    }

    // Добавляем элементы из второго массива, которых еще нет
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            bool found = false;
            for (int k = 0; k < unionSize; k++) {
                if (unionArray[k] == array2[i][j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                unionArray[unionSize++] = array2[i][j];
            }
        }
    }

    cout << "Объединение (" << unionSize << " уникальных элементов): ";
    for (int i = 0; i < unionSize; i++) {
        cout << unionArray[i] << " ";
    }
    cout << endl;

    // Освобождаем память
    delete[] unionArray;
}