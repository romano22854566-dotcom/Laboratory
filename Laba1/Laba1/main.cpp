#include <iostream>
#include <locale>
#include "TwoDArray.h"

using namespace std;
int main() {
    setlocale(0,"rus");
    cout << "=== ПРОГРАММА ДЛЯ РАБОТЫ С ДВУМЕРНЫМИ МАССИВАМИ ===\n";
    int rows1 = getSafeNumber("Введите количество строк первого массива:");
    int cols1 = getSafeNumber("Введите количество столбцов первого массива:");
    int rows2 = getSafeNumber("Введите количество строк второго массива:");
    int cols2 = getSafeNumber("Введите количество столбцов второго массива:");
    TwoDArray array1(rows1,cols1);
    TwoDArray array2(rows2,cols2);
    if (!array1.initializeArray() || !array2.initializeArray()) {
        cout << "Ошибка инициализации массивов\n";
        return 1;
    }
    cout << "=== Заполнение первого массива ===\n";
    array1.fillArray();
    cout << "\n=== Заполнение второго массива ===\n";
    array2.fillArray();
    int choice;
    do {
        choice = getMenuChoice();
        switch (choice) {
        case 1:
        showIntersection(array1,array2);
        break;
        case 2:
        showUnion(array1,array2);
        break;
        case 3:
        showBothArrays(array1,array2);
        break;
        case 4:
        cout << "Выход\n";
        break;
        default:
        break;
        }
    } while (choice != 4);
    return 0;
}