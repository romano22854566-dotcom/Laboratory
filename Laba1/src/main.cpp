#include <iostream>
#include <locale>
#include "TwoDArray.h"

using namespace std;
int main() {
    setlocale(0,"rus");
    cout << "=== ��������� ��� ������ � ���������� ��������� ===\n";
    int rows1 = getSafeNumber("������� ���������� ����� ������� �������:");
    int cols1 = getSafeNumber("������� ���������� �������� ������� �������:");
    int rows2 = getSafeNumber("������� ���������� ����� ������� �������:");
    int cols2 = getSafeNumber("������� ���������� �������� ������� �������:");
    TwoDArray array1(rows1,cols1);
    TwoDArray array2(rows2,cols2);
    if (!array1.initializeArray() || !array2.initializeArray()) {
        cout << "������ ������������� ��������\n";
        return 1;
    }
    cout << "=== ���������� ������� ������� ===\n";
    array1.fillArray();
    cout << "\n=== ���������� ������� ������� ===\n";
    array2.fillArray();
    int choice;
    do {
        choice = getMenuChoice();
        switch (choice) {
        case 1:
        showIntersection(array1,array2);
        break;
        case 2:
        showUnion(array1,array2);
        break;
        case 3:
        showBothArrays(array1,array2);
        break;
        case 4:
        cout << "�����\n";
        break;
        default:
        break;
        }
    } while (choice != 4);
    return 0;
}