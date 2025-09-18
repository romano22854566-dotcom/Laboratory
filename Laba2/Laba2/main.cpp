#include <iostream>
#include <locale>
#include "Matrix.h"

int main() {
    setlocale(0,"rus");
    Matrix matrix1;
    Matrix matrix2;
    std::cout << "=== ÏĞÎÃĞÀÌÌÀ ÄËß ÓÌÍÎÆÅÍÈÅ ÌÀÒĞÈÖ ===\n";
    std::cout << "ÏÅĞÂÀß ÌÀÒĞÈÖA:\n";
    std::cin >> matrix1;
    std::cout << "\nÂÒÎĞÀß ÌÀÒĞÈÖA:\n";
    std::cin >> matrix2;
    int choice;
    do {
    printMenu();
    choice = safeMenuInput();
    switch (choice) {
    case 1:
    showMatrix(matrix1,"Ïåğâàÿ ìàòğèöà");
    break;
    case 2:
    showMatrix(matrix2,"Âòîğàÿ ìàòğèöà");
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