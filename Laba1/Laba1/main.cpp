#include <iostream>
#include <string>
#include <cctype>
#include "TwoDArray.h"
#include <locale>
using namespace std;

int getSafeNumber(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        cin >> input;

        bool valid = true;
        for (char c : input) {
            if (!isdigit(static_cast<unsigned char>(c))) {
                valid = false;
                break;
            }
        }

        if (valid && !input.empty()) {
            int num = stoi(input);
            if (num > 0) return num;
        }

        cout << "Ошибка! Введите положительное число: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

int getMenuChoice() {
    string input;
    while (true) {
        cout << "\n=== МЕНЮ ===\n";
        cout << "1. Показать пересечение\n";
        cout << "2. Показать объединение\n";
        cout << "3. Показать оба массива\n";
        cout << "4. Выйти из программы\n";
        cout << "Выберите пункт: ";

        cin >> input;

        if (input.length() == 1 && input[0] >= '1' && input[0] <= '4') {
            return input[0] - '0';
        }

        cout << "Ошибка! Введите цифру от 1 до 4: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

int main() {
    setlocale(0, "rus");
    cout << "=== ПРОГРАММА ДЛЯ РАБОТЫ С ДВУМЕРНЫМИ МАССИВАМИ ===\n";

    int rows1 = getSafeNumber("Введите количество строк первого массива: ");
    int cols1 = getSafeNumber("Введите количество столбцов первого массива: ");
    int rows2 = getSafeNumber("Введите количество строк второго массива: ");
    int cols2 = getSafeNumber("Введите количество столбцов второго массива: ");

    TwoDArray arrays(rows1, cols1, rows2, cols2);

    if (!arrays.initializeArrays()) {
        cout << "Ошибка создания массивов!\n";
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
            cout << "Выход из программы...\n";
            break;
        default:
            break;
        }
    } while (choice != 4);

    return 0;
}