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

int main() {
    setlocale(0, "rus");
    // ���� �������� ������� �������
    cout << "=== ������� ������� ������� ===\n";
    int rows1 = getPositiveInt("������� ���������� ����� ��� ������� �������: ");
    int cols1 = getPositiveInt("������� ���������� �������� ��� ������� �������: ");

    // ���� �������� ������� �������
    cout << "\n=== ������� ������� ������� ===\n";
    int rows2 = getPositiveInt("������� ���������� ����� ��� ������� �������: ");
    int cols2 = getPositiveInt("������� ���������� �������� ��� ������� �������: ");

    // ������� ������ � ��������� ������ ��������
    TwoDArray arrays(rows1, cols1, rows2, cols2);

    // ��������� ������� � ����������
    arrays.fillArraysFromKeyboard();

    cout << "\n=== �������� ������� ===\n";

    // ������� �������� �������
    arrays.printArray(arrays.getArray1(), arrays.getRows1(), arrays.getCols1(), "������ 1");
    cout << endl;
    arrays.printArray(arrays.getArray2(), arrays.getRows2(), arrays.getCols2(), "������ 2");

    // �������� �����������
    arrays.getIntersection();

    // �������� �����������
    arrays.getUnion();

    cout << "\n��������� ���������. ������� Enter ��� ������...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}