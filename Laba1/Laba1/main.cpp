#include "TwoDArray.h"
#include <iostream>
#include <locale>
#include <limits>

int main() {
    setlocale(0, "rus");

    try {
        int rows, cols;

        // Ввод размеров первого массива с проверкой
        while (true) {
            std::cout << "Введите размеры первого массива (строки столбцы): ";
            std::cin >> rows >> cols;

            if (std::cin.fail() || rows <= 0 || cols <= 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ошибка! Размеры должны быть положительными целыми числами.\n";
            }
            else {
                break;
            }
        }

        TwoDArray array1(rows, cols);
        array1.fillArray();

        // Ввод размеров второго массива с проверкой
        while (true) {
            std::cout << "Введите размеры второго массива (строки столбцы): ";
            std::cin >> rows >> cols;

            if (std::cin.fail() || rows <= 0 || cols <= 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ошибка! Размеры должны быть положительными целыми числами.\n";
            }
            else {
                break;
            }
        }

        TwoDArray array2(rows, cols);
        array2.fillArray();

        std::cout << "\n";
        array1.printArray("Первый массив");
        array2.printArray("Второй массив");

        std::vector<int> intersection = TwoDArray::getIntersection(array1, array2);
        printVector(intersection, "Пересечение элементов");

        std::vector<int> unionSet = TwoDArray::getUnion(array1, array2);
        printVector(unionSet, "Объединение элементов");

    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}