#include <iostream>
#include <locale>
#include <string>
#include <sstream>
#include "TwoDArray.h"

using namespace std;

// ������� ��� ����������� ������ �� ����
int getMenuChoice() {
    string input;
    int choice;

    while (true) {
        cout << "�������� �����: ";
        getline(cin, input);

        if (input.empty()) {
            cout << "������! ������� ����� �� 1 �� 5.\n";
            continue;
        }

        // ���������, ��� ���� ������� ������ �� ����� �����
        if (input.length() != 1 || !isdigit(input[0])) {
            cout << "������! ������� ���� ����� �� 1 �� 5.\n";
            continue;
        }

        choice = input[0] - '0';
        if (choice >= 1 && choice <= 5) {
            return choice;
        }
        else {
            cout << "������! ������� ����� �� 1 �� 5.\n";
        }
    }
}

TwoDArray* createArrays() {
    cout << "=== ������� ������� ������� ===\n";
    int rows1;
    int cols1;
    int rows2;
    int cols2;

    // ���������� ������� �� TwoDArray.cpp
    extern int getSafePositiveInt(const string & prompt);

    rows1 = getSafePositiveInt("������� ���������� ����� ��� ������� �������: ");
    cols1 = getSafePositiveInt("������� ���������� �������� ��� ������� �������: ");

    cout << "\n=== ������� ������� ������� ===\n";
    rows2 = getSafePositiveInt("������� ���������� ����� ��� ������� �������: ");
    cols2 = getSafePositiveInt("������� ���������� �������� ��� ������� �������: ");

    return new TwoDArray(rows1, cols1, rows2, cols2);
}

void showMenu() {
    cout << "\n=== ���� ===\n";
    cout << "1. �������� �����������\n";
    cout << "2. �������� �����������\n";
    cout << "3. �������� ��� �������\n";
    cout << "4. ������ ����� �������\n";
    cout << "5. ����� �� ���������\n";
}

int main() {
    setlocale(0, "rus");

    cout << "=== ��������� ��� ������ � ���������� ��������� ===\n";

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
            cout << "����� �� ���������...\n";
            break;
        }
    } while (choice != 5);

    delete arrays;
    return 0;
}