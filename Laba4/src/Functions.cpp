#include "Functions.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Trapezoid.hpp"
#include <iostream>

void resizeArray(Figure**& figures,int& capacity) {
    int newCapacity = capacity * 2;
    Figure** newArr = new Figure * [newCapacity];
    for (int i = 0; i < capacity; ++i) {
        newArr[i] = figures[i];
    }
    delete[] figures;
    figures = newArr;
    capacity = newCapacity;
}

int printMenuAndGetChoice() {
    int choice;
    std::cout << "\n=== МЕНЮ ===\n";
    std::cout << "1. Добавить круг\n";
    std::cout << "2. Добавить прямоугольник\n";
    std::cout << "3. Добавить трапецию\n";
    std::cout << "4. Показать все фигуры\n";
    std::cout << "0. Выход\n";
    std::cout << "Ваш выбор: ";
    std::cin >> choice;
    return choice;
}

void addCircle(Figure**& figures,int& count,int& capacity) {
    double r;
    std::cout << "Введите радиус круга: ";
    std::cin >> r;
    if (count == capacity) resizeArray(figures,capacity);
    figures[count++] = new Circle(r);
}

void addRectangle(Figure**& figures,int& count,int& capacity) {
    double w,h;
    std::cout << "Введите ширину прямоугольника: ";
    std::cin >> w;
    std::cout << "Введите высоту прямоугольника: ";
    std::cin >> h;
    if (count == capacity) resizeArray(figures,capacity);
    figures[count++] = new Rectangle(w,h);
}

void addTrapezoid(Figure**& figures,int& count,int& capacity) {
    double a,b,c,d,h;
    std::cout << "Введите основание a: ";
    std::cin >> a;
    std::cout << "Введите основание b: ";
    std::cin >> b;
    std::cout << "Введите боковую сторону c: ";
    std::cin >> c;
    std::cout << "Введите боковую сторону d: ";
    std::cin >> d;
    std::cout << "Введите высоту h: ";
    std::cin >> h;
    if (count == capacity) resizeArray(figures,capacity);
    figures[count++] = new Trapezoid(a,b,c,d,h);
}

void showFigures(Figure** figures,int count) {
    if (count == 0) {
        std::cout << "Фигур нет\n";
        return;
    }
    std::cout << "\n=== Список фигур ===\n";
    for (int i = 0; i < count; ++i) {
        figures[i]->print();
            std::cout << "Площадь: " << figures[i]->area() << std::endl;
            std::cout << "Периметр: " << figures[i]->perimeter() << std::endl;
    }
}
