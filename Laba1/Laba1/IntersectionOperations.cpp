#include <iostream>
#include "TwoDArray.h"

using namespace std;

// Функция для получения пересечения
void TwoDArray::getIntersection() const {
    if (array1 == nullptr || array2 == nullptr) {
        cerr << "Error: Arrays not properly initialized" << endl;
        return;
    }

    cout << "\n=== ПЕРЕСЕЧЕНИЕ МАССИВОВ ===\n";

    // Создаем новый массив для пересечения
    int intersectionSize = 0;

    // Сначала подсчитаем количество общих элементов
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            for (int k = 0; k < rows2; k++) {
                for (int l = 0; l < cols2; l++) {
                    if (array1[i][j] == array2[k][l]) {
                        intersectionSize++;
                        break; // Нашли совпадение, выходим из внутреннего цикла
                    }
                }
            }
        }
    }

    if (intersectionSize == 0) {
        cout << "Пересечение пустое - нет общих элементов\n";
        return;
    }

    // Создаем одномерный массив для пересечения с помощью new
    int* intersection = new int[intersectionSize];
    int index = 0;

    // Заполняем массив пересечения
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            bool found = false;
            for (int k = 0; k < rows2 && !found; k++) {
                for (int l = 0; l < cols2 && !found; l++) {
                    if (array1[i][j] == array2[k][l]) {
                        intersection[index] = array1[i][j];
                        index++;
                        found = true;
                    }
                }
            }
        }
    }

    cout << "Пересечение (" << intersectionSize << " элементов): ";
    for (int i = 0; i < intersectionSize; i++) {
        cout << intersection[i] << " ";
    }
    cout << endl;

    // Освобождаем память с помощью delete
    delete[] intersection;
}