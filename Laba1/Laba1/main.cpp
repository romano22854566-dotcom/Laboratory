#include <iostream>
#include <string>
#include "TwoDArray.h"
#include <locale>
using namespace std;

// ������� ��� ����������� ����� ����� (������ � main.cpp)
int getNumber(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        cin >> input;

        // ��������� ������ ������
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
            cout << "������! ������� ����� ��� ����: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}

int main() {
    setlocale(0, "rus");
    cout << "=== ��������� ��� ������ � ���������� ��������� ===\n";

    int rows1, cols1, rows2, cols2;

    cout << "=== ������� ������� ������� ===\n";
    rows1 = getNumber("������� ���������� �����: ");
    cols1 = getNumber("������� ���������� ��������: ");

    cout << "\n=== ������� ������� ������� ===\n";
    rows2 = getNumber("������� ���������� �����: ");
    cols2 = getNumber("������� ���������� ��������: ");

    TwoDArray arrays(rows1, cols1, rows2, cols2);
    arrays.fillArrays();

    int choice;
    do {
        cout << "\n=== ���� ===\n";
        cout << "1. �������� �����������\n";
        cout << "2. �������� �����������\n";
        cout << "3. �������� ��� �������\n";
        cout << "4. ����� �� ���������\n";
        choice = getNumber("�������� �����: ");

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
            cout << "����� �� ���������...\n";
            break;
        default:
            cout << "������! �������� �� 1 �� 4.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}