#include <iostream>
#include <locale.h>
#include "Functions.hpp"

int main() {
	setlocale(0,"rus");

	int capacity = 2;
	int count = 0;
	Figure** figures = new Figure * [capacity];

	int choice;
	do {
		choice = printMenuAndGetChoice();

		switch (choice) {
		case 1: addCircle(figures,count,capacity);
			break;
		case 2: addRectangle(figures,count,capacity);
			break;
		case 3: addTrapezoid(figures,count,capacity); 
			break;
		case 4: showFigures(figures,count);
			break;
		case 0: std::cout << "Выход \n";
			break;
		default: std::cout << "Неверный выбор\n"; 
			break;
		}
	} while (choice != 0);

	for (int i = 0; i < count; ++i) {
		delete figures[i];
	}
	delete[] figures;

	return 0;
}
