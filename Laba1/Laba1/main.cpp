#include "TwoDArray.h"
#include <iostream>
#include <locale>
#include <limits>

int main() {
    setlocale(0, "rus");

    try {
        int rows, cols;

        // ���� �������� ������� ������� � ���������
        while (true) {
            std::cout << "������� ������� ������� ������� (������ �������): ";
            std::cin >> rows >> cols;

            if (std::cin.fail() || rows <= 0 || cols <= 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "������! ������� ������ ���� �������������� ������ �������.\n";
            }
            else {
                break;
            }
        }

        TwoDArray array1(rows, cols);
        array1.fillArray();

        // ���� �������� ������� ������� � ���������
        while (true) {
            std::cout << "������� ������� ������� ������� (������ �������): ";
            std::cin >> rows >> cols;

            if (std::cin.fail() || rows <= 0 || cols <= 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "������! ������� ������ ���� �������������� ������ �������.\n";
            }
            else {
                break;
            }
        }

        TwoDArray array2(rows, cols);
        array2.fillArray();

        std::cout << "\n";
        array1.printArray("������ ������");
        array2.printArray("������ ������");

        std::vector<int> intersection = TwoDArray::getIntersection(array1, array2);
        printVector(intersection, "����������� ���������");

        std::vector<int> unionSet = TwoDArray::getUnion(array1, array2);
        printVector(unionSet, "����������� ���������");

    }
    catch (const std::exception& e) {
        std::cerr << "������: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}