#include <iostream>
#include <locale>
#include "TwoDArray.h"

using namespace std;
int main() {
    setlocale(0,"rus");
    cout << "=== ��������� ��� ������ � ���������� �������� ==\n";
    int rows1 = getSafeNumber("������� ���������� ����� ������� ������:");
    int cols1 = getSafeNumber("������� ���������� �������� ������� ������:");
    int rows2 = getSafeNumber("������� ���������� ����� ������� ������:");
    int cols2 = getSafeNumber("������� ���������� �������� ������� ������:");
    TwoDArray arrays(rows1,cols1,rows2,cols2);
    if (!arrays.initializeArrays()) {
        cout << "������\n";
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
        cout << "�����\n";
        break;
        default:
        break;
        }
    } while (choice != 4);
    return 0;
}