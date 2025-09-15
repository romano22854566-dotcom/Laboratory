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
            cout << "������! ������� ������������� ����� �����.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void inputArrays(TwoDArray*& arrays) {
    cout << "=== ������� ������� ������� ===\n";
    int rows1 = getPositiveInt("������� ���������� ����� ��� ������� �������: ");
    int cols1 = getPositiveInt("������� ���������� �������� ��� ������� �������: ");

    cout << "\n=== ������� ������� ������� ===\n";
    int rows2 = getPositiveInt("������� ���������� ����� ��� ������� �������: ");
    int cols2 = getPositiveInt("������� ���������� �������� ��� ������� �������: ");

    if (arrays != nullptr) {
        delete arrays;
    }

    arrays = new TwoDArray(rows1, cols1, rows2, cols2);
    arrays->fillArraysFromKeyboard();
}

void showMenu() {
    cout << "\n=== ���� ===\n";
    cout << "1. �������� �����������\n";
    cout << "2. �������� �����������\n";
    cout << "3. ������ ����� �������\n";
    cout << "4. ����� �� ���������\n";
    cout << "�������� �����: ";
}

int main() {
    setlocale(0, "rus");
    TwoDArray* arrays = nullptr;

    cout << "=== ��������� ��� ������ � ���������� ��������� ===\n";
    inputArrays(arrays);

    int choice;
    do {
        showMenu();

        while (!(cin >> choice) || choice < 1 || choice > 4) {
            cout << "������! ������� ����� �� 1 �� 4: ";
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
            cout << "����� �� ���������...\n";
            break;
        }
    } while (choice != 4);

    if (arrays != nullptr) {
        delete arrays;
    }

    return 0;
}