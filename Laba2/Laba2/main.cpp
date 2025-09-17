#include <iostream>
#include "Matrix.h"
#include <locale>
#include <string>
#include <sstream>

using namespace std;

// ������� ��� ����������� ����� ����� � ����
int safeInputMenu(const string& prompt) {
    string input;
    int value;

    while (true) {
        cout << prompt;
        getline(cin, input);

        // ���������, ��� ������ �� ������
        if (input.empty()) {
            cout << "������: ���� �� ����� ���� ������! ���������� �����.\n";
            continue;
        }

        stringstream ss(input);
        ss >> value;

        // ���������, ��� ��� ������� ���� ���������� � ��� ������
        if (ss.fail() || !ss.eof()) {
            cout << "������ �����! ����������, ������� ����� �� 1 �� 5.\n";
            cin.clear();
        }
        else if (value < 1 || value > 5) {
            cout << "�������� �����! ����������, �������� �� 1 �� 5.\n";
        }
        else {
            return value;
        }
    }
}

void printMenu() {
    cout << "\n=== ���� ������ � ��������� ===\n";
    cout << "1. �������� ������ �������\n";
    cout << "2. �������� ������ �������\n";
    cout << "3. �������� ������� (�������� &)\n";
    cout << "4. ����������� �������\n";
    cout << "5. �����\n";
    cout << "�������� ����� (1-5): ";
}

void inputMatrix(Matrix& matrix, const string& name) {
    cout << "\n=== ���� " << name << " ������� ===\n";
    cin >> matrix;
    cout << name << " ������� ������� �������!\n";
}

int main() {
    setlocale(0, "rus");
    Matrix matrix1, matrix2, result;

    cout << "=== ��������� ��� ������ � ��������� ===\n";
    cout << "��� ��������� ������ ���������� �������� ������ �������\n";
    cout << "������ ��������� ���������� ����� ������ �������!\n\n";

    // ���� ������ ����� ����� �������
    inputMatrix(matrix1, "������");
    inputMatrix(matrix2, "������");

    int choice;

    do {
        printMenu();
        choice = safeInputMenu("");

        switch (choice) {
        case 1:
            cout << "\n=== ������ ������� ===\n";
            if (matrix1.getRows() > 0 && matrix1.getCols() > 0) {
                cout << "������: " << matrix1.getRows() << "x" << matrix1.getCols() << endl;
                cout << matrix1;
            }
            else {
                cout << "������� �� �������!\n";
            }
            break;

        case 2:
            cout << "\n=== ������ ������� ===\n";
            if (matrix2.getRows() > 0 && matrix2.getCols() > 0) {
                cout << "������: " << matrix2.getRows() << "x" << matrix2.getCols() << endl;
                cout << matrix2;
            }
            else {
                cout << "������� �� �������!\n";
            }
            break;

        case 3:
            cout << "\n=== ��������� ������ ===\n";
            if (matrix1.getRows() > 0 && matrix1.getCols() > 0 &&
                matrix2.getRows() > 0 && matrix2.getCols() > 0) {
                result = matrix1 & matrix2;
                if (result.getRows() > 0) {
                    cout << "��������� ��������� (" << result.getRows() << "x" << result.getCols() << "):\n";
                    cout << result;
                }
            }
            else {
                cout << "��� ������� ������ ���� �������!\n";
            }
            break;

        case 4:
            cout << "\n=== ������������ ������ ===\n";
            inputMatrix(matrix1, "������");
            inputMatrix(matrix2, "������");
            break;

        case 5:
            cout << "����� �� ���������...\n";
            break;
        }

    } while (choice != 5);

    return 0;
}