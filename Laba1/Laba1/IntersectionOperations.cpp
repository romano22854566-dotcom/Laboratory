#include <iostream>
#include "TwoDArray.h"

using namespace std;

// ������� ��� ��������� �����������
void TwoDArray::getIntersection() {
    cout << "\n=== ����������� �������� ===\n";

    // ������� ����� ������ ��� �����������
    int intersectionSize = 0;

    // ������� ���������� ���������� ����� ���������
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            for (int k = 0; k < rows2; k++) {
                for (int l = 0; l < cols2; l++) {
                    if (array1[i][j] == array2[k][l]) {
                        intersectionSize++;
                    }
                }
            }
        }
    }

    if (intersectionSize == 0) {
        cout << "����������� ������ - ��� ����� ���������\n";
        return;
    }

    // ������� ���������� ������ ��� �����������
    int* intersection = new int[intersectionSize];
    int index = 0;

    // ��������� ������ �����������
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            for (int k = 0; k < rows2; k++) {
                for (int l = 0; l < cols2; l++) {
                    if (array1[i][j] == array2[k][l]) {
                        intersection[index++] = array1[i][j];
                    }
                }
            }
        }
    }

    cout << "����������� (" << intersectionSize << " ���������): ";
    for (int i = 0; i < intersectionSize; i++) {
        cout << intersection[i] << " ";
    }
    cout << endl;

    // ����������� ������
    delete[] intersection;
}