#include <iostream>
#include <locale>
#include "Matrix.h"

int main() {
    setlocale(0,"rus");
    Matrix matrix1;
    Matrix matrix2;
    std::cout << "=== ÏÐÎÃÐÀÌÌÀ ÄËß ÓÌÍÎÆÅÍÈÅ ÌÀÒÐÈÖ ===\n";
    std::cout << "ÏÅÐÂÀß ÌÀÒÐÈÖA:\n";
    input(matrix1);
    std::cout << "\nÂÒÎÐÀß ÌÀÒÐÈÖA:\n";
    input(matrix2);
    int choice;
    do {
        printMenu();
        choice = safeMenuInput();
        switch (choice) {
        case 1:
        showMatrix(matrix1,"Ïåðâàÿ ìàòðèöà");
        break;
        case 2:
        showMatrix(matrix2,"Âòîðàÿ ìàòðèöà");
        break;
        case 3:
        multiplyMatrices(matrix1,matrix2);
        break;
        case 4:
        std::cout << "Âûõîä\n";
        break;
        default:
        break;
        }
    } while (choice != 4);
    return 0;
}