#include <iostream>
#include <locale>
#include "TwoDArray.h"

using namespace std;
int main() {
    setlocale(0,"rus");
    cout << "=== ПРОГРАММА ДЛЯ РАБОТЫ С ДВУМЕРНЫМИ МАСИВАМИ ==\n";
    int rows1 = getSafeNumber("Введите количество строк первого масива:");
    int cols1 = getSafeNumber("Введите количество столбцов первого масива:");
    int rows2 = getSafeNumber("Введите количество строк второго масива:");
    int cols2 = getSafeNumber("Введите количество столбцов второго масива:");
    TwoDArray arrays(rows1,cols1,rows2,cols2);
    if (!arrays.initializeArrays()) {
        cout << "Ошибка\n";
        return 1;
    }
    arrays.fillArrays();
    int choice;
    do {
        choice = getMenuChoice();
        switch (choice) {
        case 1:
        arrays.showIntersection();
        break;
        case 2:
        arrays.showUnion();
        break;
        case 3:
        arrays.showArrays();
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