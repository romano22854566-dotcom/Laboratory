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

        cout << "������! ������� ������������� �����: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

int getMenuChoice() {
    string input;
    while (true) {
        cout << "\n=== ���� ===\n";
        cout << "1. �������� �����������\n";
        cout << "2. �������� �����������\n";
        cout << "3. �������� ��� �������\n";
        cout << "4. ����� �� ���������\n";
        cout << "�������� �����: ";

        cin >> input;

        if (input.length() == 1 && input[0] >= '1' && input[0] <= '4') {
            return input[0] - '0';
        }

        cout << "������! ������� ����� �� 1 �� 4: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

int main() {
    setlocale(0, "rus");
    cout << "=== ��������� ��� ������ � ���������� ��������� ===\n";

    int rows1 = getSafeNumber("������� ���������� ����� ������� �������: ");
    int cols1 = getSafeNumber("������� ���������� �������� ������� �������: ");
    int rows2 = getSafeNumber("������� ���������� ����� ������� �������: ");
    int cols2 = getSafeNumber("������� ���������� �������� ������� �������: ");

    TwoDArray arrays(rows1, cols1, rows2, cols2);

    if (!arrays.initializeArrays()) {
        cout << "������ �������� ��������!\n";
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
            cout << "����� �� ���������...\n";
            break;
        default:
            break;
        }
    } while (choice != 4);

    return 0;
}