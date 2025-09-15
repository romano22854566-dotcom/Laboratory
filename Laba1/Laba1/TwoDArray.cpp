#include "TwoDArray.h"
#include <iostream>
#include <algorithm>
#include <locale>
#include <limits>

TwoDArray::TwoDArray(int r, int c) : rows(r), cols(c) {
    if (rows <= 0 || cols <= 0) {
        throw std::invalid_argument("Размеры массива должны быть положительными числами");
    }

    data = new int* [rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols](); // Инициализация нулями
    }
}

TwoDArray::~TwoDArray() {
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
}

void TwoDArray::fillArray() {
    std::cout << "Заполните массив " << rows << "x" << cols << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::string prompt = "Элемент [" + std::to_string(i) + "][" + std::to_string(j) + "]: ";
            data[i][j] = getValidatedInt(prompt);
        }
    }
}

void TwoDArray::printArray(const std::string& name) const {
    std::cout << name << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::set<int> TwoDArray::getUniqueElements() const {
    std::set<int> uniqueElements;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            uniqueElements.insert(data[i][j]);
        }
    }
    return uniqueElements;
}

int TwoDArray::getElement(int i, int j) const {
    if (i < 0 || i >= rows || j < 0 || j >= cols) {
        throw std::out_of_range("Индекс выходит за границы массива");
    }
    return data[i][j];
}

void TwoDArray::setElement(int i, int j, int value) {
    if (i < 0 || i >= rows || j < 0 || j >= cols) {
        throw std::out_of_range("Индекс выходит за границы массива");
    }
    data[i][j] = value;
}

void printVector(const std::vector<int>& vec, const std::string& name) {
    std::cout << name << ": ";
    if (vec.empty()) {
        std::cout << "пусто";
    }
    else {
        for (int num : vec) {
            std::cout << num << " ";
        }
    }
    std::cout << std::endl;
}

int getValidatedInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка! Пожалуйста, введите целое число.\n";
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}