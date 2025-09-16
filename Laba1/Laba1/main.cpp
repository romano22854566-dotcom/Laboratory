#include <iostream>
#include <string>
#include "TwoDArray.h"
#include <locale>
using namespace std;

// Функция для безопасного ввода числа (только в main.cpp)
int getNumber(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        cin >> input;

        // Проверяем каждый символ
        bool isGood = true;
        for (char c : input) {
            if (c < '0' || c > '9') {
                isGood = false;
                break;
            }
        }

        if (isGood && !input.empty()) {
            return stoi(input);
        }
        else {
            cout << "Ошибка! Введите число без букв: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}

int main() {
    setlocale(0, "rus");
    cout << "=== ПРОГРАММА ДЛЯ РАБОТЫ С ДВУМЕРНЫМИ МАССИВАМИ ===\n";

    int rows1, cols1, rows2, cols2;

    cout << "=== РАЗМЕРЫ ПЕРВОГО МАССИВА ===\n";
    rows1 = getNumber("Введите количество строк: ");
    cols1 = getNumber("Введите количество столбцов: ");

    cout << "\n=== РАЗМЕРЫ ВТОРОГО МАССИВА ===\n";
    rows2 = getNumber("Введите количество строк: ");
    cols2 = getNumber("Введите количество столбцов: ");

    TwoDArray arrays(rows1, cols1, rows2, cols2);
    arrays.fillArrays();

    int choice;
    do {
        cout << "\n=== МЕНЮ ===\n";
        cout << "1. Показать пересечение\n";
        cout << "2. Показать объединение\n";
        cout << "3. Показать оба массива\n";
        cout << "4. Выйти из программы\n";
        choice = getNumber("Выберите пункт: ");

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
            cout << "Выход из программы...\n";
            break;
        default:
            cout << "Ошибка! Выберите от 1 до 4.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}