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

int main() {
    setlocale(0, "rus");
    // Ввод размеров первого массива
    cout << "=== РАЗМЕРЫ ПЕРВОГО МАССИВА ===\n";
    int rows1 = getPositiveInt("Введите количество строк для первого массива: ");
    int cols1 = getPositiveInt("Введите количество столбцов для первого массива: ");

    // Ввод размеров второго массива
    cout << "\n=== РАЗМЕРЫ ВТОРОГО МАССИВА ===\n";
    int rows2 = getPositiveInt("Введите количество строк для второго массива: ");
    int cols2 = getPositiveInt("Введите количество столбцов для второго массива: ");

    // Создаем объект с массивами разных размеров
    TwoDArray arrays(rows1, cols1, rows2, cols2);

    // Заполняем массивы с клавиатуры
    arrays.fillArraysFromKeyboard();

    cout << "\n=== ИСХОДНЫЕ МАССИВЫ ===\n";

    // Выводим исходные массивы
    arrays.printArray(arrays.getArray1(), arrays.getRows1(), arrays.getCols1(), "Массив 1");
    cout << endl;
    arrays.printArray(arrays.getArray2(), arrays.getRows2(), arrays.getCols2(), "Массив 2");

    // Получаем пересечение
    arrays.getIntersection();

    // Получаем объединение
    arrays.getUnion();

    cout << "\nПрограмма завершена. Нажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}