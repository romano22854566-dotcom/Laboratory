#include "Trapezoid.hpp"
#include <iostream>

Trapezoid::Trapezoid(double base1,double base2,double side1,double side2,double height)
    : a(base1),b(base2),c(side1),d(side2),h(height) {
}

Trapezoid::~Trapezoid() {}

double Trapezoid::area() const {
    return (a + b) * h / 2.0;
}

double Trapezoid::perimeter() const {
    return a + b + c + d;
}

void Trapezoid::print() const {
    std::cout << "Фигура: Трапеция\n";
    std::cout << "Основания = " << a << ", " << b
        << "; Боковые стороны = " << c << ", " << d
        << "; Высота = " << h << std::endl;
}
