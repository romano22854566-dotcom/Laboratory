#include <iostream>
#include <locale>
#include "TwoDArray.h"

using namespace std;

int getPositiveInt(const char* prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value > 0) {
            return value;
        }
        else {
            cout << "Ошибка! Введите положительное целое число.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void inputArrays(TwoDArray*& arrays) {
    cout << "=== РАЗМЕРЫ ПЕРВОГО МАССИВА ===\n";
    int rows1 = getPositiveInt("Введите количество строк для первого массива: ");
    int cols1 = getPositiveInt("Введите количество столбцов для первого массива: ");

    cout << "\n=== РАЗМЕРЫ ВТОРОГО МАССИВА ===\n";
    int rows2 = getPositiveInt("Введите количество строк для второго массива: ");
    int cols2 = getPositiveInt("Введите количество столбцов для второго массива: ");

    if (arrays != nullptr) {
        delete arrays;
    }

    arrays = new TwoDArray(rows1, cols1, rows2, cols2);
    arrays->fillArraysFromKeyboard();
}

void showMenu() {
    cout << "\n=== МЕНЮ ===\n";
    cout << "1. Показать пересечение\n";
    cout << "2. Показать объединение\n";
    cout << "3. Ввести новые массивы\n";
    cout << "4. Выйти из программы\n";
    cout << "Выберите пункт: ";
}

int main() {
    setlocale(0, "rus");
    TwoDArray* arrays = nullptr;

    cout << "=== ПРОГРАММА ДЛЯ РАБОТЫ С ДВУМЕРНЫМИ МАССИВАМИ ===\n";
    inputArrays(arrays);

    int choice;
    do {
        showMenu();

        while (!(cin >> choice) || choice < 1 || choice > 4) {
            cout << "Ошибка! Введите число от 1 до 4: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
        case 1:
            arrays->getIntersection();
            break;
        case 2:
            arrays->getUnion();
            break;
        case 3:
            inputArrays(arrays);
            break;
        case 4:
            cout << "Выход из программы...\n";
            break;
        }
    } while (choice != 4);

    if (arrays != nullptr) {
        delete arrays;
    }

    return 0;
}