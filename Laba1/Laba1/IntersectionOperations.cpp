#include <iostream>
#include "TwoDArray.h"

using namespace std;

void TwoDArray::getIntersection() const {
    if (array1 == nullptr || array2 == nullptr) {
        cerr << "Error: Arrays not properly initialized" << endl;
        return;
    }

    cout << "\n=== ПЕРЕСЕЧЕНИЕ МАССИВОВ ===\n";

    int intersectionSize = 0;

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            for (int k = 0; k < rows2; k++) {
                for (int l = 0; l < cols2; l++) {
                    if (array1[i][j] == array2[k][l]) {
                        intersectionSize++;
                        break;
                    }
                }
            }
        }
    }

    if (intersectionSize == 0) {
        cout << "Пересечение пустое - нет общих элементов\n";
        return;
    }

    int* intersection = new int[intersectionSize];
    int index = 0;

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

    // Вывод в виде массива
    cout << "Пересечение (" << intersectionSize << " элементов):\n";
    for (int i = 0; i < intersectionSize; i++) {
        cout << intersection[i] << " ";
    }
    cout << endl;

    delete[] intersection;
}