#include <iostream>
#include "TwoDArray.h"

using namespace std;

// Функция для получения пересечения
void TwoDArray::getIntersection() {
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
                    }
                }
            }
        }
    }

    if (intersectionSize == 0) {
        cout << "Пересечение пустое - нет общих элементов\n";
        return;
    }

    // Создаем одномерный массив для пересечения
    int* intersection = new int[intersectionSize];
    int index = 0;

    // Заполняем массив пересечения
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            for (int k = 0; k < rows2; k++) {
                for (int l = 0; l < cols2; l++) {
                    if (array1[i][j] == array2[k][l]) {
                        intersection[index++] = array1[i][j];
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

    // Освобождаем память
    delete[] intersection;
}