#include <iostream>
#include <locale>
#include <string>
#include <sstream>
#include "TwoDArray.h"

using namespace std;

// Функция для безопасного выбора из меню
int getMenuChoice() {
    string input;
    int choice;

    while (true) {
        cout << "Выберите пункт: ";
        getline(cin, input);

        if (input.empty()) {
            cout << "Ошибка! Введите число от 1 до 5.\n";
            continue;
        }

        // Проверяем, что ввод состоит только из одной цифры
        if (input.length() != 1 || !isdigit(input[0])) {
            cout << "Ошибка! Введите одну цифру от 1 до 5.\n";
            continue;
        }

        choice = input[0] - '0';
        if (choice >= 1 && choice <= 5) {
            return choice;
        }
        else {
            cout << "Ошибка! Введите число от 1 до 5.\n";
        }
    }
}

TwoDArray* createArrays() {
    cout << "=== РАЗМЕРЫ ПЕРВОГО МАССИВА ===\n";
    int rows1;
    int cols1;
    int rows2;
    int cols2;

    // Используем функции из TwoDArray.cpp
    extern int getSafePositiveInt(const string & prompt);

    rows1 = getSafePositiveInt("Введите количество строк для первого массива: ");
    cols1 = getSafePositiveInt("Введите количество столбцов для первого массива: ");

    cout << "\n=== РАЗМЕРЫ ВТОРОГО МАССИВА ===\n";
    rows2 = getSafePositiveInt("Введите количество строк для второго массива: ");
    cols2 = getSafePositiveInt("Введите количество столбцов для второго массива: ");

    return new TwoDArray(rows1, cols1, rows2, cols2);
}

void showMenu() {
    cout << "\n=== МЕНЮ ===\n";
    cout << "1. Показать пересечение\n";
    cout << "2. Показать объединение\n";
    cout << "3. Показать оба массива\n";
    cout << "4. Ввести новые массивы\n";
    cout << "5. Выйти из программы\n";
}

int main() {
    setlocale(0, "rus");

    cout << "=== ПРОГРАММА ДЛЯ РАБОТЫ С ДВУМЕРНЫМИ МАССИВАМИ ===\n";

    TwoDArray* arrays = createArrays();
    arrays->fillArraysFromKeyboard();

    int choice;
    do {
        showMenu();
        choice = getMenuChoice();

        switch (choice) {
        case 1:
            arrays->getIntersection();
            break;
        case 2:
            arrays->getUnion();
            break;
        case 3:
            arrays->printArrays();
            break;
        case 4:
            delete arrays;
            arrays = createArrays();
            arrays->fillArraysFromKeyboard();
            break;
        case 5:
            cout << "Выход из программы...\n";
            break;
        }
    } while (choice != 5);

    delete arrays;
    return 0;
}