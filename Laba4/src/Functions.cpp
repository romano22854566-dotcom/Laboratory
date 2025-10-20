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
    std::cout << "\n=== ���� ===\n";
    std::cout << "1. �������� ����\n";
    std::cout << "2. �������� �������������\n";
    std::cout << "3. �������� ��������\n";
    std::cout << "4. �������� ��� ������\n";
    std::cout << "0. �����\n";
    std::cout << "��� �����: ";
    std::cin >> choice;
    return choice;
}

void addCircle(Figure**& figures,int& count,int& capacity) {
    double r;
    std::cout << "������� ������ �����: ";
    std::cin >> r;
    if (count == capacity) resizeArray(figures,capacity);
    figures[count++] = new Circle(r);
}

void addRectangle(Figure**& figures,int& count,int& capacity) {
    double w,h;
    std::cout << "������� ������ ��������������: ";
    std::cin >> w;
    std::cout << "������� ������ ��������������: ";
    std::cin >> h;
    if (count == capacity) resizeArray(figures,capacity);
    figures[count++] = new Rectangle(w,h);
}

void addTrapezoid(Figure**& figures,int& count,int& capacity) {
    double a,b,c,d,h;
    std::cout << "������� ��������� a: ";
    std::cin >> a;
    std::cout << "������� ��������� b: ";
    std::cin >> b;
    std::cout << "������� ������� ������� c: ";
    std::cin >> c;
    std::cout << "������� ������� ������� d: ";
    std::cin >> d;
    std::cout << "������� ������ h: ";
    std::cin >> h;
    if (count == capacity) resizeArray(figures,capacity);
    figures[count++] = new Trapezoid(a,b,c,d,h);
}

void showFigures(Figure** figures,int count) {
    if (count == 0) {
        std::cout << "����� ���\n";
        return;
    }
    std::cout << "\n=== ������ ����� ===\n";
    for (int i = 0; i < count; ++i) {
        figures[i]->print();
            std::cout << "�������: " << figures[i]->area() << std::endl;
            std::cout << "��������: " << figures[i]->perimeter() << std::endl;
    }
}
