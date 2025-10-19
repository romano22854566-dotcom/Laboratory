#include "Circle.hpp"
#include <iostream>

Circle::Circle(double r): radius(r) {}
Circle::~Circle() {}

double Circle::area() const {
    return 3.1415 * radius * radius;
}

double Circle::perimeter() const {
    return 2 * 3.1415 * radius;
}

void Circle::print() const {
    std::cout << "Фигура: Круг\n";
    std::cout << "Радиус = " << radius << std::endl;
}
