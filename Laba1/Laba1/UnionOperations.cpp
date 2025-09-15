#include <iostream>
#include "TwoDArray.h"

using namespace std;

void TwoDArray::getUnion() const {
    if (array1 == nullptr || array2 == nullptr) {
        cerr << "Error: Arrays not properly initialized" << endl;
        return;
    }

    cout << "\n=== ÎÁÚÅÄÈÍÅÍÈÅ ÌÀÑÑÈÂÎÂ ===\n";

    int maxSize = rows1 * cols1 + rows2 * cols2;
    int* unionArray = new int[maxSize];
    int unionSize = 0;

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            bool found = false;
            for (int k = 0; k < unionSize; k++) {
                if (unionArray[k] == array1[i][j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                unionArray[unionSize] = array1[i][j];
                unionSize++;
            }
        }
    }

    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            bool found = false;
            for (int k = 0; k < unionSize; k++) {
                if (unionArray[k] == array2[i][j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                unionArray[unionSize] = array2[i][j];
                unionSize++;
            }
        }
    }

    // Âûâîä â âèäå ìàññèâà
    cout << "Îáúåäèíåíèå (" << unionSize << " óíèêàëüíûõ ýëåìåíòîâ):\n";
    for (int i = 0; i < unionSize; i++) {
        cout << unionArray[i] << " ";
    }
    cout << endl;

    delete[] unionArray;
}